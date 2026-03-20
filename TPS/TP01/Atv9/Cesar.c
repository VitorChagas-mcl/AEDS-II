#include <stdio.h>

int equal(char *str1, char *str2){						
	int i = 0; // função de comparar strings para ver se sao iguais
	while(str1[i] != '\0' || str2[i] != '\0'){
		if(str1[i] != str2[i])
			return 0;
		i++;
	}
	return 1;
}

void tirarN(char *s){
	int i = 0;
	//Fução para tirar o \n do final da string
	while(s[i] != '\0'){
		if(s[i] == '\n'){
			s[i] = '\0';
			return;
		}
		i++;
	}
}

void Cifra(char *s){// passando com por ponteiro para retornar a string
	if(*s == '\0') // condição de parada
		return;

	*s += 3;//soma 3 na posição atual

	Cifra(s + 1);// chamada recursiva
}
int main(){
	char str1[2000];

	scanf("%[^\n]", str1);
	getchar();
	
	while(!equal(str1, "FIM")){ // chamada da função para comparar strubgs
		Cifra(str1); // chama a função
		printf("%s\n", str1); // printa o vetor de char
		scanf("%[^\n]",str1);
		getchar();
	}
}
