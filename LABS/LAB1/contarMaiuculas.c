#include <stdio.h>

void tirarN(char *str){
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == '\n'){
            str[i] = '\0';
            return;
        }
    }
}

int contarMaiusculas(char *str){
    int cont = 0;
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] >= 'A' && str[i] <= 'Z')
            cont++;
    }
    return cont;
}

int compararStrings(char *str1, char *str2){
    int i = 0;
    while(str1[i] != '\0' && str2[i] != '\0'){
        if(str1[i] != str2[i]) return 0;
        i++;
    }
    return 1;
}

int main(){
    char str[100];

    fgets(str, sizeof(str), stdin);
    tirarN(str);

    while(compararStrings(str, "FIM") == 0){
        int maiusculas = contarMaiusculas(str);
        printf("%d\n", maiusculas);
        fgets(str, sizeof(str), stdin);
        tirarN(str);
    }

}