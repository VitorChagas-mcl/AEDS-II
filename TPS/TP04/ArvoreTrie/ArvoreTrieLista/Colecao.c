#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
//criei todas as structs que preciso
int comp = 0;
int mov = 0;//variasveis para contagem de comparacoes e movimentos
typedef struct Data{
    int dia;
    int mes;
    int ano;
}Data;

typedef struct Hora{
    int hora;
    int minuto;
}Hora;

typedef struct Restaurante{
    int id_restaurante;
    char* nome;
    char* cidade;
    int capacidade;
    double avaliacao;
    char** tipo_cozinha;
    int faixa_preco;
    Hora hora_abertura;
    Hora hora_fechamento;
    Data data_abertura;
    bool aberto;
}Restaurante;

typedef struct ColecaoRestaurante{
    int tamanho;
    Restaurante* restaurante;
}Colecao_Restaurante;

typedef struct No No;

typedef struct Celula{
    char elemento;
    struct Celula* prox;
    No* no;
}Celula;

struct No{
	char elemento;
    Celula* primeiro;
    Celula* ultimo;
	int folha;
};

Celula* novaCelula(char x){
    Celula* nova = (Celula*)malloc(sizeof(Celula));
    nova->elemento = x;
    nova->prox = NULL;
    nova->no = NULL;
    return nova;
}

No* novoNo(char x){
	No* novo = (No*)malloc(sizeof(No));
	novo->elemento = x;
	novo->ultimo = novo->primeiro = novaCelula('\0');
    novo->folha = 1;
    return novo;
}

No* raiz;

void start(){
	raiz = novoNo('\0');
}

Data parse_data(char *s){
    Data d;

    sscanf(s, "%d-%d-%d", &d.ano, &d.mes, &d.dia);//leitura de data
    
    return d;// retona uma struct de data
}

void formatar_data(Data* data, char* buffer){
    sprintf(buffer,"%02d/%02d/%04d", data->dia, data->mes, data->ano);//pega a Data e passa formatada para o buffer
}

Hora parse_hora(char *s){
    Hora h;
    
    sscanf(s,"%d:%d", &h.hora, &h.minuto);//ler de Hora

    return h;// retorna uma struct de hora
}

void formatar_hora(Hora* hora, char* buffer){
    sprintf(buffer, "%02d:%02d", hora->hora, hora->minuto);// pega a Hora e passa formatada para o buffer
}

void liberar_restaurante(Restaurante* r) {// criei uma funcao para liberar os vetores alocados
    free(r->nome);
    free(r->cidade);
    free(r->tipo_cozinha[0]);
    free(r->tipo_cozinha);
}

Restaurante* parse_restaurante(char *s){
    Restaurante* r = (Restaurante*)malloc(sizeof(Restaurante));// crio um restaurante novo
    if(r == NULL){
        printf("Nao foi possivel criar restaurante!");
        return NULL;
    }
    char hora_a[6], hora_f[6], data_a[11], nome[100], cidade[100], preco[10], tipo[40], aberto[10];// crio vetores de char para leitura da string

    sscanf(s, "%d,%[^,],%[^,],%d,%lf,%[^,],%[^,],%[^-]-%[^,],%[^,],%[^\n]",//leitura da string de restaurante
           &r->id_restaurante, nome, cidade, &r->capacidade,
           &r->avaliacao, tipo, preco, hora_a, hora_f,
           data_a, aberto);
    
    for(int i = 0; aberto[i] != '\0'; i++){
        if(aberto[i] == '\r' || aberto[i] == '\n' || aberto[i] == ' ')//verifico se existe algo apos a string
            aberto[i] = '\0';
    }
    r->aberto = (strcmp(aberto, "true") == 0);//verifica se o char aberto e true, se for r->aberto recebe true
    r->hora_abertura = parse_hora(hora_a);//chama da funcao para o parse_hora
    r->hora_fechamento = parse_hora(hora_f);// mesma chama da de cima para strings diferente
    r->data_abertura = parse_data(data_a);// chama da funcao parse_data 

    int tam = 0;//crio uma variavel para pegar o tamanho
    while(nome[tam] != '\0') tam++;//leio ate o \0
    r->nome = (char*)malloc((tam + 1) * sizeof(char));// e aloco o tamanho exato do vetor e coloco + 1
                                                     // casa para o \0
    
    sprintf(r->nome,"%s", nome);// passo char nome, para a char da struct
    
    tam = 0;// zero o tamanho
    while(cidade[tam] != '\0') tam++;//pega o tamanho
    r->cidade = (char*)malloc((tam + 1) * sizeof(char));//aloca
    
    sprintf(r->cidade,"%s", cidade);//para para a variavel da cidade na struct

    tam = 0;//zero o contador
    while(preco[tam] != '\0') tam++;//pega o tamanho
    r->faixa_preco = tam;//passo o valor exato da quantidade de $

    tam = 0;// zera o contador
    while(tipo[tam] != '\0') tam++;//pega o valor
    for(int i = 0; tipo[i] != '\0'; i++)//leitura ate o \0
        if(tipo[i] == ';') tipo[i] = ',';//substitui o ; por ,

    r->tipo_cozinha = (char**)malloc(1 * sizeof(char*));//cria uma posicao do char duplo
    r->tipo_cozinha[0] = (char*)malloc((tam + 1) * sizeof(char));//aloco o tamanho da quantidade de tipos exato

    sprintf(r->tipo_cozinha[0],"%s",tipo);//pega a primeira possicao e preenche com a string
   

    return r;// retorna um novo restaurante
}

void formatar_restaurante(Restaurante* restaurante, char* buffer){
    char hora_fechamento[7], hora_abertura[7], data_abertura[12], str_aberto[6];// crio vetores de char 

    formatar_hora(&restaurante->hora_abertura, hora_abertura);//passo a hora formata para o vetor
    formatar_hora(&restaurante->hora_fechamento, hora_fechamento);//mesma coisa que a funcao de cima para vetor diferente
    formatar_data(&restaurante->data_abertura, data_abertura);// passo a Data formatada para o veto de data
  
    char f_preco[5];// crio um vetor de proc
    int i;// i para pegar o tamanho do vetor
    for(i = 0; i < restaurante->faixa_preco; i++){// conto
        f_preco[i] = '$';// passo na posicao o $
    }
    f_preco[i] = '\0';// adiciono o \0 ao final

    if(restaurante->aberto == true) {// verifico se é true a variavel 
        sprintf(str_aberto, "true");// se for adiciona true a string 
    }else{
        sprintf(str_aberto, "false");// se nao adiciona false
    }
    sprintf(buffer,"[%d ## %s ## %s ## %d ## %.1lf ## [%s] ## %s ## %s-%s ## %s ## %s]",//formatacao do restaurante
        restaurante->id_restaurante, restaurante->nome, restaurante->cidade,
        restaurante->capacidade, restaurante->avaliacao, restaurante->tipo_cozinha[0],
        f_preco, hora_abertura, hora_fechamento, data_abertura, str_aberto);
}

void ler_csv_colecao(Colecao_Restaurante* colecao, char* path){
    
    FILE *arq = fopen(path, "r");// abre o arquivo
    if(arq == NULL){//verifica se o ponteiro é null
        printf("Erro ao abrir arquivo!");
        return;// se for retorna nada
    }
    char linha[200];// pega o linha

    fgets(linha, sizeof(linha), arq);//leio o cabecalho
   
    int i = 0;//variavel para a quantidade
    while(fgets(linha, sizeof(linha), arq) != NULL){// leio ate o fgets retorna null
        Restaurante* aux = parse_restaurante(linha); //Criei um aux para o parse_restaurante

        colecao->restaurante[i] = *aux; //Faco as transferencia do auxilia para o restaurente na posicao i
                                         // de restaurante
        i++;
        free(aux);//Libera a memoria
    }

    fclose(arq);//fecho o arquivo
}

Colecao_Restaurante* ler_csv(){//funcao para cria a colecao
        FILE *arq = fopen("/tmp/restaurantes.csv", "r");// abro o arquivo para leitura

        if(arq == NULL){// verifico se o ponteiro do arquivo nao é nulll
            printf("Erro ao abrir arquivo!");
            return NULL;// se for retorna null
        }

        int tam = 0;//crio uma variavel para o tamanho da colecao
        char linha[200];

        while(fgets(linha, sizeof(linha), arq) != NULL){//leio ate o final do arquivo 
            tam++;//incremento do tam
        }

        fclose(arq);// fecho o arquivo

        Colecao_Restaurante* novaCole = (Colecao_Restaurante*) malloc(sizeof(Colecao_Restaurante));// crio uma colecao
        if(novaCole == NULL){// se a colecao nao for aloca
            printf("Erro ao alocar Colecao!");
            return NULL;// retorna null
        }
        novaCole->tamanho = tam - 1;// recebe o tamanho exata da colecao
        novaCole->restaurante = (Restaurante*)malloc((tam - 1) * sizeof(Restaurante));// crio o vetor de restaurante
        if(novaCole->restaurante == NULL){// verifico se a alocacao deu certo
            printf("Erro ao alocar restaurante!");
            return NULL;// se nao der retorna null
        }
        ler_csv_colecao(novaCole,"/tmp/restaurantes.csv");// chamada da funcao para registra restaurante

      return novaCole;// retorno uma nova colecao
}

int buscarId(Colecao_Restaurante* colecao, int id_buscado) {// funcao para buscar o restaurante
    for (int i = 0; i < colecao->tamanho; i++) {//pego o tamanho da colecao
        if (colecao->restaurante[i].id_restaurante == id_buscado) {// e procuro o id buscado do restaurante
            return i; // retorno a posicao
        }
    }
    return -1;// se nao encontra retorna -1
}
int buscarNome(Colecao_Restaurante* colecao, char* chave) {// funcao para buscar o restaurante
    for (int i = 0; i < colecao->tamanho; i++) {//pego o tamanho da colecao
        if (strcmp(colecao->restaurante[i].nome,chave) == 0) {// e procuro o id buscado do restaurante
            return i; // retorno a posicao
        }
    }
    return -1;// se nao encontra retorna -1
}

int transformarInt(char *s){// funcao para transforma o char em int
    int qtdCaracteres;
    for(qtdCaracteres=0; s[qtdCaracteres] != '\0' && s[qtdCaracteres] != '\n'; qtdCaracteres++);

    int contador = 1;
    int resposta = 0;
    for(int i=qtdCaracteres-1; i>=0; i--) {
        resposta += (s[i] - '0') * contador;//pega o valor e multiplica pela casa unidade decimal ou centena
        contador *= 10;//aumento o valor do contador por exemplo 10, 100, 1000
    }
    return resposta;// retorno o valor do id
}

No* inserirNo(No* i,char elemento){
    Celula* nova = novaCelula(elemento);
    nova->no = novoNo(elemento);
    i->ultimo->prox = nova;
    i->ultimo = nova;
    return nova->no;
}

No* pesquisarNo(char x, No* i){
    No* resp = NULL;
    for(Celula* ic = i->primeiro->prox; ic != NULL; ic = ic->prox){
        comp++;
        if(ic->elemento == x){
            resp = ic->no;
            ic = i->ultimo;
        }
    }
    return resp;
}

void setFilho(char x, No* i){
    for(Celula* ic = i->primeiro->prox; ic != NULL; ic = ic->prox){
        if(ic->elemento == x){
            ic->no->folha = 0;
            ic = i->ultimo;
        }
    }
}

int pegarTamanho(char *s){
    int cont = 0;
    for(int i = 0; s[i] != '\0'; i++){
        cont++;
    }
    return cont;
}
void inserirRec(char* s, No* i, int pos){
    No* filho = pesquisarNo(s[pos], i);
    int tam = pegarTamanho(s);
    comp++;
	if(filho == NULL){
        mov++;
		filho = inserirNo(i, s[pos]);
        if(pos == tam - 1){
            setFilho(s[pos], i);
        }else{
            inserirRec(s, filho, pos + 1);
        }
	}else if(pos < tam - 1){
        inserirRec(s, filho, pos + 1);        
    }else{
        printf("Erro ao inserir");
    }
}

void inserir(char* x){
	inserirRec(x, raiz, 0);	
}

int pesquisarRec(char* x, No* i, int pos){
    int resp = 1;
    No* filho = pesquisarNo(x[pos], i);
    int tam = pegarTamanho(x);
    comp++;
    if(filho == NULL){
        resp = 1;
    }else if(pos == tam - 1){
        printf("%c ", x[pos]);
        resp = filho->folha;
    }else if(pos < tam - 1){
        printf("%c ", x[pos]);
        resp = pesquisarRec(x, filho, pos + 1);
    } else {
        printf("Erro ao pesquisar");
    }

    return resp;
}

int pesquisar(char* x){
	return pesquisarRec(x, raiz, 0);
}
/*
void caminharCentral(No* i){
	
	if(i != NULL){	
		caminharCentral(i->esq);
		char buffer[300];
        formatar_restaurante(i->elemento, buffer);
        printf("%s\n", buffer);
		caminharCentral(i->dir);
	}
}
*/

int main(){
   /*pequeno teste para ver se esta funcionando
    Data d = parse_data("2026-04-13");
    char b[11];
    formatar_data(&d, b);
    printf("%s ", b);
    Hora h = parse_hora("12:00");
    char s[6];
    formatar_hora(&h, s);
    printf("%s\n", s);*/
    //crio a colecao e retorno completo
    Colecao_Restaurante* cr = ler_csv();
    clock_t inicio, fim;
    double total_tempo;
    start();

    char linha[50];
    scanf("%s", linha);//leio a linha
    while(strcmp(linha, "-1") != 0){//comparo se é diferente de -1
        int id = transformarInt(linha);//transformo o valor
        int idBuscado = buscarId(cr, id);// busca o id na lista
        if(idBuscado != -1){//verifico se é diferete de -1
            inserir(cr->restaurante[idBuscado].nome);
        }
        scanf("%s", linha);// scan para a proxima linha
    }
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    fgets(linha,sizeof(linha), stdin);
    for(int i = 0; linha[i] != '\0';i++){
        if(linha[i] == '\r' || linha[i] == '\n')
            linha[i] = '\0';
    }
    inicio = clock();
     while(strcmp(linha, "FIM") != 0){
        if(pesquisar(linha) != 1){
            int id = buscarNome(cr, linha);
            char leitura[300];
            formatar_restaurante(&cr->restaurante[id], leitura);
            printf("SIM %s\n", leitura);
        }else{
            printf("NAO\n");
        }
        fgets(linha, sizeof(linha), stdin);
        for(int i = 0; linha[i] != '\0';i++){
            if(linha[i] == '\r' || linha[i] == '\n') {
                linha[i] = '\0';
            }
        }
    }
    fim = clock();
    total_tempo = ((fim - inicio) / (double)CLOCKS_PER_SEC) * 1000.0;
    FILE* arq_log = fopen("880222_arvore_trie_lista.txt", "w");

    if(arq_log != NULL){
        fprintf(arq_log, "880222\t Comparacoes: %d\t Movimentos: %d\t Tempo: %.4lf\n", comp, mov, total_tempo);
        fclose(arq_log);
    }
    free(cr->restaurante);//libero o vetor de colecao restaurante
    free(cr);//libero a colecao
}
