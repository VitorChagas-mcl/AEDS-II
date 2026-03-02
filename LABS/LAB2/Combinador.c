#include <stdio.h>

int main(){
	char str1[100], str2[100], final[1000];

	while(scanf("%s %s", str1, str2) != EOF){
		int i = 0, j = 0;

		while(str1[i] != '\0' && str2[i] != '\0'){
			final[j++] = str1[i++];
			final[j++] = str2[i++];
		}

		while(str1[i] != '\0'){
			final[j++] = str1[i++];
		}

		while(str2[i] != '\0'){
			final[j++] = str2[i++];
		}

		final[j] = '\0';
	}
	printf("%s\n", final);
}
