#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct No {
    int elemento;
    bool cor;
    struct No *esq;
    struct No *dir;
} No;

typedef struct {
    No *raiz;
} ArvoreBicolor;

No* novoNo(int x) {
    No *novo = (No*) malloc(sizeof(No));
    novo->elemento = x;
    novo->cor = true;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

bool isNoTipo4(No* i){
	return (i->esq != NULL && i->dir != NULL && i->esq->cor == true && i->dir->cor == true);
}

void fragmentar(No* i){
	i->cor = !i->cor;
	i->dir->cor = !i->dir->cor;
	i->esq->cor = !i->esq->cor;
}

No* rotacaoSimplesEsq(No *no) {
    No *noDir = no->dir;
    No *noDirEsq = noDir->esq;

    noDir->esq = no;
    no->dir = noDirEsq;

    return noDir;
}

No* rotacaoSimplesDir(No *no) {
    No *noEsq = no->esq;
    No *noEsqDir = noEsq->dir;

    noEsq->dir = no;
    no->esq = noEsqDir;

    return noEsq;
}

No* rotacaoDuplaEsqDir(No *no) {
    no->esq = rotacaoSimplesEsq(no->esq);
    return rotacaoSimplesDir(no);
}

No* rotacaoDuplaDirEsq(No *no) {
    no->dir = rotacaoSimplesDir(no->dir);
    return rotacaoSimplesEsq(no);
}

void balancear(No* bisavo, No* avo, No* pai, No* i, ArvoreBicolor *a) {
    if (pai != NULL &&pai->cor == true) {
        if (pai->elemento > avo->elemento){
            if(i->elemento > pai->elemento){
		        avo = rotacaoSimplesEsq(avo);
            } else {
                avo = rotacaoDuplaDirEsq(avo);
            }
        } else {
            if (i->elemento < pai->elemento) {
                avo = rotacaoSimplesDir(avo);
            } else {
                avo = rotacaoDuplaEsqDir(avo);
            }
        }
        if(bisavo == NULL){
            a->raiz = avo;
        } else if(avo->elemento < bisavo->elemento){
            bisavo->esq = avo;
        } else {
            bisavo->dir = avo;
        }
        avo->cor = false; 
        if (avo->esq != NULL) avo->esq->cor = true;
        if (avo->dir != NULL) avo->dir->cor = true;
    }
}

void inserirB(int x, No* bisavo, No* avo, No* pai, No *i, ArvoreBicolor *a) {
    if(i == NULL){
        if(x < pai->elemento){
           i = pai->esq = novoNo(x);
        } else {
           i = pai->dir = novoNo(x);
        }
        if(pai->cor == true){
            balancear(bisavo, avo, pai, i, a);
        }
    } else {
        if(isNoTipo4(i)){
            fragmentar(i);
            if(i == a->raiz){
                i->cor = false;
            } else if(pai->cor == true){
                balancear(bisavo, avo, pai, i, a);
            }
        }
        if(x < i->elemento){
            inserirB(x, avo, pai, i, i->esq, a);
        }else if(x > i->elemento) {
            inserirB(x, avo, pai, i, i->dir, a);
        } else {
            printf("Erro ao inserir\n");
        }
    }
}

void inserirRec(ArvoreBicolor *a, int x) {
    if (a->raiz== NULL) {
        a->raiz = novoNo(x);
    } else if(a->raiz->esq == NULL && a->raiz->dir == NULL){
        if(x < a->raiz->elemento){
            a->raiz->esq = novoNo(x);
        } else {
            a->raiz->dir = novoNo(x);
        }
    } else if(a->raiz->esq == NULL){
        if(x < a->raiz->elemento){
            a->raiz->esq = novoNo(x);
        }else if (x < a->raiz->dir->elemento){
            a->raiz->esq = novoNo(a->raiz->elemento);
            a->raiz->elemento = x;
        }else {
            a->raiz->esq = novoNo(a->raiz->elemento);
            a->raiz->elemento = a->raiz->dir->elemento;
            a->raiz->dir->elemento = x;
        }
        a->raiz->esq->cor = a->raiz->dir->cor = false;
    }else if(a->raiz->dir == NULL){
        if(x > a->raiz->elemento){
            a->raiz->dir = novoNo(x);
        }else if(x > a->raiz->esq->elemento){
            a->raiz->dir = novoNo(a->raiz->elemento);
            a->raiz->elemento = x;
        } else {
            a->raiz->dir = novoNo(a->raiz->elemento);
            a->raiz->elemento = a->raiz->esq->elemento;
            a->raiz->esq->elemento = x;
        }
        a->raiz->esq->cor = a->raiz->dir->cor = false;
    } else {
        inserirB(x, NULL, NULL, NULL, a->raiz, a);
    }
    a->raiz->cor = false;
}

void inserir(ArvoreBicolor *a, int x) {
    inserirRec(a, x);
}

int pesquisarRec(No *i, int x) {
    if (i == NULL) {
        return 0;
    }

    printf("%d ", i->elemento);

    if (x == i->elemento)
        return 1;
    else if (x < i->elemento)
        return pesquisarRec(i->esq, x);
    else
        return pesquisarRec(i->dir, x);
}

int pesquisar(ArvoreBicolor *a, int x) {
    return pesquisarRec(a->raiz, x);
}

void caminhaPre(No *i) {
    if (i != NULL) {
        printf("%d(cor=%d)", i->elemento, i->cor);
        caminhaPre(i->esq);
        caminhaPre(i->dir);
    }
}

void caminhaPos(No *i) {
    if (i != NULL) {
        caminhaPos(i->esq);
        caminhaPos(i->dir);
        printf("%d(cor=%d)", i->elemento, i->cor);
    }
}

void caminhaCentral(No *i) {
    if (i != NULL) {
        caminhaCentral(i->esq);
        printf("%d(cor=%d)", i->elemento, i->cor);
        caminhaCentral(i->dir);
    }
}

int main() {
    ArvoreBicolor* a = (ArvoreBicolor*) malloc(sizeof(ArvoreBicolor));
    a->raiz = NULL;

    char comando[20];
    int valor;

    while (scanf("%s", comando) != EOF) {

        if (comando[0] == 'I') {
            scanf("%d", &valor);
            inserir(a, valor);

        } else if (comando[0] == 'E') {
            if (a->raiz == NULL)
                printf("V");
            else
                caminhaCentral(a->raiz);
            printf("\n");

        } else if (comando[0] == 'P' && strlen(comando) == 1) {
            scanf("%d", &valor);

            if (pesquisar(a, valor))
                printf("S\n");
            else
                printf("N\n");

        } else if (comando[1] == 'R') {
            if (a->raiz == NULL)
                printf("V");
            else
                caminhaPre(a->raiz);
            printf("\n");

        } else if (comando[1] == 'O') {
            if (a->raiz == NULL)
                printf("V");
            else
                caminhaPos(a->raiz);
            printf("\n");
        }
    }
    
    return 0;
}
