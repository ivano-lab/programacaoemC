# include <stdio.h>

int main() {
	int numeros[3];
	int tamanho = sizeof(numeros) / sizeof(numeros[0]);
	
	
	
	for(int i = 0; i < tamanho; i++) {
		printf("Digite o número: ");
		scanf("%d", &numeros[i]);
	}

	printf("Os números digitados são: ");
	for(int i = 0; i < tamanho; i++) {
		printf("%d ", numeros[i]);
	}
	printf("\n");
	
	return 0;
}
