#include <stdio.h>

int equal(char *str1, char *str2){						
	int i = 0;
	while(str1[i] != '\0' && str2[i] != '\0'){
		if(str1[i] != str2[i])// comparando strings se sao diferente
			return 0;
		i++;
	}
	//caso nao caia no if returna 1
	return 1;
}

void tirarN(char *s){
	int i = 0;

	while(s[i] != '\0'){
		if(s[i] == '\n'){ // função de tirar o \n da entrada do teclado
			s[i] = '\0';
			return;
		}
		i++;
	}
}

int somaRec(char *s){

	if(*s == '\0'){// condição de parada
		return 0;	
	}
	int resp = *s - '0'; // pega o valor ascii por exemplo 5 em ascii 
			     //é 53 e o 0 é 48 faz 53 - 48 = 5
			     //assim pegando valor exato;
	return resp + somaRec(s + 1);// chama recursiva fazendo 5 + a chamada da função novamente
}

int main(){
	
	char linha[100];
	
	scanf("%s", linha);
	tirarN(linha);
	while(!equal(linha,"FIM")){
		printf("%d\n",somaRec(linha));
		scanf("%s", linha);
		tirarN(linha);
	}
}
