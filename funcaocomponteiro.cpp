#include<stdio.h>

void SOMA(float *a , float b);

int main() {
	
	float a, b;
	
	printf("\nDigite o primeiro valor: ");
	scanf("%f", &a);
	printf("\nDigite o segundo valor: ");
	scanf("%f", &b);
	
	SOMA(&a, b);
	
	printf("\nO resultado da funcao soma impresso e: %6.3f", a);
	

}

void SOMA(float *a, float b) {
	*a = *a+b;
}
