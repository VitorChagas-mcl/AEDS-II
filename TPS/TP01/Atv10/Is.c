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

int vogal(char *s){
	if(*s == '\0')
		return 1;

	if (*s != 'a' || *s != 'A' ||
            *s != 'e' || *s != 'E' ||
            *s != 'i' || *s != 'I' ||
            *s != 'o' || *s != 'O' ||
            *s != 'u' || *s != 'U')
		return 0;

	vogal(s + 1);

}

int consoante(char *s){
	if(*s == '\0')
		return 1;

	if (*s == 'a' || *s == 'A' ||
       	    *s == 'e' || *s == 'E' ||
            *s == 'i' || *s == 'I' ||
            *s == 'o' || *s == 'O' ||
            *s == 'u' || *s == 'U')
		return 0;
	consoante(s + 1);
}


int soNumero(char *s){
	if(*s == '\0')
		return 1;

	if(!(*s >= '0' && *s <= 9))	
		return 0;
	soNumero(s + 1);
}

int main(){
	char str1[2000];

	scanf("%[^\n]", str1);
	getchar();
	int x1, x2, x3, x4;
	while(!equal(str1, "FIM")){ // chamada da função para comparar strubgs
		x1 = vogal(str1);
		x2 = consoante(str1);
		x3 = soNumero(str1);
		
		(x1) ? printf("SIM ") : printf("NAO ");	
		(x2) ? printf("SIM ") : printf("NAO ");
		(x3) ? printf("SIM ") : printf("NAO ");
		printf("\n");		
		scanf("%[^\n]",str1);
		getchar();
	}
}
