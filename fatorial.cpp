#include<stdio.h>

int FAT(int fat);

int main(void) {

	int n, result;

	printf("Digite o primeiro valor: ");
	scanf("%d", &n);

	result = FAT(n);

	printf("\nO fatorial do numero digitado e: %d", result);
	return 0;
}

int FAT(int n) {
	int fat;
	for(fat = 1; n > 1; n = n - 1) {
		fat = fat * n;
	}
	return fat;	
}
