
#include <stdio.h>

int equal(char *str1, char *str2){
    int i = 0;
    while(str1[i] != '\0' || str2[i] != '\0'){ // função de comparação de string se for diferente retorna 0
        if(str1[i] != str2[i]) return 0;
        i++;
    }
    return 1;
}

int lengthOfLongestSubstring(char* s) {
        int i = 0, tam = 0; // tam pra retornar o valor
        while(s[i] != '\0'){
            char ascii[256] = {0};// Crio um vetor pra armezena meu valores ascii
            int j = i, cont = 0;// contador e o j pegando a possição do i atual
            while(s[j] != '\0'){
                int valor = (int)s[j];// transformo o valor ascii em int 
                if(ascii[valor] == 0){ // comparo se esse valor esta na tabela
                    ascii[valor] = 1;// caso nao esteja na tabela adiciona um no ascii
                    cont++;// contador pra ver quantas letra esta na string
                }else{
                    break;// se achar ele sai do loop
                }
                j++;
            }
            i++;
            if(cont > tam) // pega o valor do contador e ve se é maior que o tamanho atual
                tam = cont;// se for ele tam pega o valor do cont
        }
    return tam; // retorna a quantidade 
}

int main()
{
    char s[1000];
    scanf("%s", s);getchar();
    while(!equal(s, "FIM")){ // verificar se a string é igual a fim
        int resp = lengthOfLongestSubstring(s); // chama da função para retornar o valor ao resp 
        // nome da função ta em ingles pq eu joguei no leetcode pra testar
        printf("%d\n", resp);// print
        scanf("%s", s);getchar(); // proxima linha
    }
}

