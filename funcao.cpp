#include <stdio.h>

float SOMA(float a, int b);

int main (void) {
	float a;
	int b;
	a = 12.3;
	b = 10;
	SOMA (a,b);

	printf("%.3f", SOMA(a,b));
	return 0;

}

float SOMA (float a, int b) {
	float result;

	result = a+b;
	printf("A soma de %6.3f com %d e %6.3: ", a, b, result);

	return result;

}

