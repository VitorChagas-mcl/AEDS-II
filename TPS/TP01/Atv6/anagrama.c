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

int verificar(char *s1, char *s2){
	int tam1 = 0, tam2 = 0; // contador para cada string
	int i = 0;
	int veri = 1; // Verificador se manter o 1 é verdadeiro
	while(s1[i] != '\0' || s2[i] != '\0'){ // enquanto as duas string nao chegar ao \0 
		tam1 += s1[i];// pega o tamanho da primeira string
		tam2 += s2[i];// pega o tamanho da segunda string 
		i++;// incremento do while para nao ficar infinito 
	}	

	if(tam1 != tam2) // se os tamanhos for diferente atribui 0 a veri
		veri = 0;

	return veri;// retorna 1 para verdadeiro ou 0 para falsa
}
int main(){
	char str1[1000], str2[1000];

	scanf("%s %s", str1, str2);
	tirarN(str1);
	tirarN(str2);
	while(!equal(str1, "FIM")){ // chamada da função para comparar strubgs
		int test = verificar(str1, str2);// pegar o retorno da funçã
		(test) ? printf("SIM\n") : printf("NAO\n"); // Operador ternario se receber 1 ou 0 para sim ou nao
		scanf("%s %s", str1, str2); // scannea as proximas linhas
		tirarN(str1);
		tirarN(str2);
	}		
}
