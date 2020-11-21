#include<stdio.h>
#include <math.h>

float DIST(float x1, float y1, float x2, float y2);

int main(void) {
	
	float x1, y1, x2, y2, result;
	
	printf("\nDigite o ponto x1: ");
	scanf("%f", &x1);
	printf("\nDigite o ponto y1: ");
	scanf("%f", &y1);
	printf("\nDigite o ponto x2: ");
	scanf("%f", &x2);
	printf("\nDigite o ponto y2: ");
	scanf("%f", &y2);
	
	result = DIST(x1, y1, x2, y2);
	
	printf("\nA distancia entre os pontos e: %3.f", result);
	
	return 0;

}

float DIST(float x1, float y1, float x2, float y2) {
	float result, a, b;
	
	a = x1-x2;
	b = y1-y2;
	
	result = sqrt(pow(a,2)+pow(b,2));
	
	return result;
	
}
