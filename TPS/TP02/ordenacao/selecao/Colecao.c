#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
//criei todas as structs que preciso
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

        Colecao_Restaurante* novaCole = (Colecao_Restaurante*) malloc(sizeof(Colecao_Restaurante));// crio uma colacao
        if(novaCole == NULL){// se a colacao nao for aloca
            printf("Erro ao alocar Colecao!");
            return NULL;// retorna null
        }
        novaCole->tamanho = tam - 1;// recebe o tamanho exata da colecao
        novaCole->restaurante = (Restaurante*)malloc((tam - 1) * sizeof(Restaurante));// crio o vetor de restauanrete
        if(novaCole->restaurante == NULL){// verifico se a alocacao deu certo
            printf("Erro ao alocar restaurante!");
            return NULL;// se nao der retorna null
        }
        ler_csv_colecao(novaCole,"/tmp/restaurantes.csv");// chamada da funcao para registra restaurante

      return novaCole;// retorno uma nova colecao
}

int buscar_id(Colecao_Restaurante* colecao, int id_buscado) {// funcao para buscar o restaurante
    for (int i = 0; i < colecao->tamanho; i++) {//pego o tamanho da colecao
        if (colecao->restaurante[i].id_restaurante == id_buscado) {// e procuro o id buscado do restaurante
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

void swap(Restaurante *i, Restaurante *j, int* mov) {
   Restaurante temp = *i;
   *i = *j;
   *j = temp;
   (*mov) += 3;
}

void Selecao(Restaurante r[], int n, int* comp, int* mov){
    
    for(int i = 0; i < n - 1; i++){
        int menor = i;
        for(int j = i + 1; j < n; j++){
            (*comp)++;
            if(strcmp(r[j].nome, r[menor].nome) < 0){
                menor = j;
            }
        }
        swap(&r[i], &r[menor], mov);
    }
}
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
    //ver o timer 
    clock_t inicio, fim;
    double total_tempo;

    //crio a colecao
    Colecao_Restaurante* cr = ler_csv();
    
    //Criando um array de restaurantes ordenados, e um int para saber os ordenados
    Restaurante r_ordenados[1000];
    int ordenados = 0;
    int comp = 0, mov = 0;
    char linha[5];
    scanf("%s", linha);//leio a linha
    while(strcmp(linha, "-1") != 0){//comparo se é diferente de -1
        int id = transformarInt(linha);//transformo o valor

        int id_buscado = buscar_id(cr, id);// busca o id na lista
        if(id_buscado != -1){//verifico se é diferete de -1
           r_ordenados[ordenados] = cr->restaurante[id_buscado];  
           ordenados++;
        }
        scanf("%s", linha);// scan para a proxima linha
    }
    
    //inicio do clock + selecao
    inicio = clock();
    Selecao(r_ordenados, ordenados, &comp, &mov);
    fim = clock();
    total_tempo = ((fim - inicio) / (double)CLOCKS_PER_SEC) * 1000.0; 

    for(int i = 0; i < ordenados; i++) {
        char leitura[300];
        formatar_restaurante(&r_ordenados[i], leitura);
        printf("%s\n", leitura);
    }

    FILE* arq_log = fopen("880222_selecao.txt", "w");
    
    if(arq_log != NULL){
        fprintf(arq_log, "880222\t Comparacoes: %d\t Movimentos: %d\t Tempo: %.4lf\n", comp, mov, total_tempo);
        fclose(arq_log);
    }


    for (int i = 0; i < cr->tamanho; i++) {
        liberar_restaurante(&cr->restaurante[i]);//libero os vetores criado de cada posicao
    }
    free(cr->restaurante);//libero o vetor de colecao restaurante

    free(cr);//libero a colecao
}
