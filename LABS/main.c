#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int tam;

	while(scanf("%d", &tam) != EOF){
		int vetor[tam];
		int index = 0;
		int aux[index];

		for(int i = 0; i < tam; i++){
			scanf("%d", &vetor[i]);
		}

		for(int i = 0; i < tam; i++){
			int achou = 1;
			for(int j = i + 1; j < tam; j++){
				if(vetor[i] == vetor[j]){
					achou = 0;
					break;
				}
				//printf("i:%d j:%d", vetor[i], vetor[j]);
			}
			if(achou == 1){
				aux[index] = vetor[i];
				index++;
			}
		}
		if(index != 0){
			for(int i = 0; i < index; i++){
				printf("%d ", aux[i]);	
			}
			printf("\n");
		}else{
			printf("VAZIO\n");
		}
	}
}
