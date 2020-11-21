#include<stdio.h>

void FATORIAL(int *fat) {
	int result = *fat;
	while (*fat>1){
		result = result*(*fat-1);
		(*fat)--;
	}
	*fat = result;	
}

int main() {

	int fat;

	printf("Digite o primeiro valor: ");
	scanf("%d", &fat);

	FATORIAL(&fat);

	printf("\nO fatorial do numero digitado e: %d", fat);
	
}


