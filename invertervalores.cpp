#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SIZE 10

void gerarAleatorios(int vec[]) {
	//gera numeros aleatorios

	int i, num;
	srand(time(NULL));
	for (i = 0; i<SIZE; i++) {
		vec[i] = (int)rand()%100;
	}
}

void bubbleSort (int vec[]) {
	// Definição de variaveis usadas no programa
	int i, j, aux;
	for(i=1; i<SIZE; i++) {
		for(j=0; j<SIZE-1; j++) {
			if(vec[j] > vec[j+1]) {
				aux = vec[j];
				vec[j]= vec[j+1];
				vec[j+1]=aux;
			}
		}
	}
}


int main (void) {
	int v[SIZE], i;

	gerarAleatorios(v);

	for (i=0; i<SIZE; i++) {
		printf("%d\n", v[i]);
	}
	
	printf("\n");
	
	bubbleSort(v);
		for (i=0; i<SIZE; i++) {
		printf("%d\n", v[i]);
	}
	
	return 0;
}
