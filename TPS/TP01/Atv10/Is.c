#include <stdio.h>

int letra(char s){
	return ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z'));
}
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

	if(!letra(*s))// verifica se tem apenas letra
		return 0;

	if (*s != 'a' && *s != 'A' && // verifica se tem alguma letra que nao é vogal
            *s != 'e' && *s != 'E' &&
            *s != 'i' && *s != 'I' &&
            *s != 'o' && *s != 'O' &&
            *s != 'u' && *s != 'U')
		return 0;

	return vogal(s + 1); // chama recursiva

}

int consoante(char *s){
	if(*s == '\0')
		return 1;

	if(!letra(*s))//verifica se tem apenas letra
		return 0;
	//verifica se tem alguma vogal
	if (*s == 'a' || *s == 'A' ||// se tiver qualquer vogal ja sai
       	    *s == 'e' || *s == 'E' ||
            *s == 'i' || *s == 'I' ||
            *s == 'o' || *s == 'O' ||
            *s == 'u' || *s == 'U')
		return 0;
	return consoante(s + 1); // chamada recursiva
}


int soNumero(char *s){
	if(*s == '\0')
		return 1;

	if(!(*s >= '0' && *s <= '9')) // verifica se tem apenas numero
		return 0;
	
	return soNumero(s + 1); // chamada recursiva
}

int soNumReal(char *s, int sep){
	if(*s == '\0'){ 
		return 1;
	}

	if((*s >= '0' && *s <= '9')){// verifica se existe se tem numero
	}else if(*s == '.' || *s == ','){//verifica se é ponto
			sep++;// se for sep++;

			if(sep > 1) // se tiver mais de um . ou , retorna false
				return 0;
		
	}else{
		return 0; // caso nao tenha nenhum numero ou . sai
	}
	return soNumReal(s + 1, sep);// chamada recursiva
}
int main(){
	char str1[2000];

	scanf("%[^\n]", str1);
	getchar();
	int x1, x2, x3, x4;
	while(!equal(str1, "FIM")){ // chamada da função para comparar strubgs
		//Pega 1 ou 0 nas funções 
		x1 = vogal(str1);
		x2 = consoante(str1);
		x3 = soNumero(str1);
		x4 = soNumReal(str1, 0);
		//verifica se é 1 se for printa sim, se for 0 printa nao
		(x1) ? printf("SIM ") : printf("NAO ");	
		(x2) ? printf("SIM ") : printf("NAO ");
		(x3) ? printf("SIM ") : printf("NAO ");
		(x4) ? printf("SIM") : printf("NAO");
		printf("\n");		
		scanf("%[^\n]",str1);
		getchar();
	}
}
