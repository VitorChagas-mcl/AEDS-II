#include <stdio.h>

int equal(char *str1, char *str2){
	int i = 0;
	while(str1[i] != '\0' && str2[i] != '\0'){
		if(str1[i] != str2[i])// compara as string se for diferente retorna 0
			return 0;
		i++;
	}	
	//caso nao caia no if retorna 1
	return 1;
}

void tirarN(char *s){
	int i = 0;
	while(s[i] != '\0'){
		if(s[i] == '\n'){//função pra tirar o N da entrada do teclado
			s[i] = '\0';
			return;
		}
		i++;
	}
}

void inverter(char *s, char *invertido){//passagem por referencia para modificar a string
	int i = 0;
	while(s[i] != '\0')//Pega o tamanho da string1
		i++;

	int j = 0;
	while(i >= 0){
		invertido[j] = s[i - 1];// pega a primeira posição do invertido
					// e coloca o a ultima letra da mensagem enviada
		i--;
		j++;
	}
	invertido[j] = '\0';//Adiciona um \0 no final da string ex:Vitor\0 pra indicar final de string
}
int main(){

	char msg[1000], resp[1000];
	fgets(msg, 1000, stdin);
	tirarN(msg);
	while(!equal(msg, "FIM")){
		inverter(msg, resp);
		printf("%s\n",resp);
		fgets(msg, 1000, stdin);
		tirarN(msg);
	}
}
