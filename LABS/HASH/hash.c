#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Hash{
    char **tabela;
    int m;
    int r;
    int nr;
} Hash;

void liberarHash(Hash *h) {
    for(int i = 0; i < h->m + h->r; i++) {
        if(h->tabela[i] != NULL) {
            free(h->tabela[i]);
        }
    }
    free(h->tabela);
}

void tirarN(char *s){
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == '\n' || s[i] == '\r'){
            s[i] = '\0';
        }
    }
}

void iniciarHash(Hash *h, int m, int r){
    h->m = m;
    h->r = r;
    h->nr = 0;
    h->tabela = (char**) malloc((m + r) * sizeof(char*));
    for(int i = 0; i < m + r; i++){
        h->tabela[i] = NULL;
    }
}

int hash(char *chave, Hash *h){
    int soma = 0;
    for(int i = 0; chave[i] != '\0'; i++){
        soma += (int)chave[i];
    }
    return soma % h->m;
}

bool isPosicaoLivre(int pos, Hash *h){
    return (h->tabela[pos] == NULL);
}

bool pesquisar(char *chave, Hash *h){
    int pos = hash(chave, h);
    bool resp = false;
    if(isPosicaoLivre(pos, h) == true){
        resp = false;
    }else if (strcmp(h->tabela[pos], chave) == 0){
        resp = true;
    }else{ 
        for(int i = h->m; i < h->m + h->nr; i++){
            if(strcmp(h->tabela[i], chave) == 0){
                resp = true;
                i = h->m + h->nr;
            }
        }
    }
    return resp;
}

void inserir(char *chave, Hash *h){
    if(pesquisar(chave, h) == true){
        printf("Erro\n");
        return;
    }
    int pos = hash(chave, h);
    if(isPosicaoLivre(pos, h) == true){
        h->tabela[pos] = (char*) malloc((strlen(chave) + 1) * sizeof(char));
        for(int i = 0; chave[i] != '\0'; i++){
            h->tabela[pos][i] = chave[i];
        }
        h->tabela[pos][strlen(chave)] = '\0';
    }else if(h->nr < h->r){
        h->tabela[h->m + h->nr] = (char*) malloc((strlen(chave) + 1) * sizeof(char));
        for(int i = 0; chave[i] != '\0'; i++){
            h->tabela[h->m + h->nr][i] = chave[i];
        }
        h->tabela[h->m + h->nr][strlen(chave)] = '\0';
        h->nr++;
    }else{
        printf("Erro\n");
    }
}
bool remover(char *chave, Hash *h){
    int pos = hash(chave, h);
    bool resp = false;
    if(isPosicaoLivre(pos, h) == true){
        resp = false;
    }else if (strcmp(h->tabela[pos], chave) == 0){
        resp = true;
    }else{ 
        for(int i = h->m; i < h->m + h->nr; i++){
            if(strcmp(h->tabela[i], chave) == 0){
                resp = true;
                free(h->tabela[i]);
                h->tabela[i] = NULL;
                i = h->m + h->nr;
            }
        }
        
    }
    return resp;
}

void imprimir(Hash *h){
    for(int i = 0; i < h->m + h->r; i++){
        printf("%d %s %s\n", i, (i < h->m) ? "Principal " : "Reserva ", (h->tabela[i] != NULL) ? h->tabela[i] : "-");
    }
}


int main(){
    Hash tabelaHash;
    iniciarHash(&tabelaHash, 11, 3);
    char leitura[100];
    char inicial[100];
    while(scanf("%s", inicial) != EOF){
        tirarN(inicial);
        if(inicial[0] == 'I'){
            scanf("%s", leitura);
            tirarN(leitura);
            inserir(leitura, &tabelaHash);
        }else if(inicial[0] == 'P'){
            scanf("%s", leitura);
            tirarN(leitura);
            bool resp = pesquisar(leitura, &tabelaHash);
            printf("%s\n", (resp) ? "Sim" : "Nao");
        }else if(inicial[0] == 'M'){
            imprimir(&tabelaHash);
        }else if(inicial[0] == 'R'){
            scanf("%s", leitura);
            tirarN(leitura);
            remover(leitura, &tabelaHash);
        }
    }
    liberarHash(&tabelaHash);
}

