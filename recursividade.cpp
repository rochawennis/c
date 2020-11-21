#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

# define SIZE 100

void gerarAleatorios(int vec[]) {
	//gera numeros aleatorios

	int i, num;
	srand(time(NULL));
	for (i = 0; i<SIZE; i++) {
		vec[i] = (int)rand()%100;
	}
}

void quick ( int v [ SIZE], int primeiro, int ultimo ) {
	int inicio, fim, meio, pivo, aux ;
	inicio = primeiro ;
	fim = ultimo ;
	meio = ( inicio + fim ) / 2 ;
	pivo = v [ meio ] ;
	while ( inicio < fim ) { //while #1
		while ( v [ inicio ] < pivo )
			inicio++ ;
		while ( v [ fim ] > pivo )
			fim-- ;
		if ( inicio < fim ) {
			aux = v [ inicio ] ;
			v [ inicio++ ] = v [ fim ] ;
			v [ fim-- ] = aux ;
		} //Fecha if
	} //Fecha while #1
	if ( inicio == fim ) {
		inicio++ ;
		fim-- ;
	}
	if ( fim > primeiro )
		quick ( v, primeiro, fim ) ;
	if ( inicio < ultimo )
		quick ( v, inicio, ultimo ) ;

}//Fim

int main ( ) {
	int i;
	int v[SIZE];
	gerarAleatorios(v);
	quick ( v, 0, SIZE-1 ) ;

	printf ( "\n\nVetor Ordenado:\n" ) ;
	for ( i = 0; i < SIZE; i++)
		printf ( "%d\n", v[i]) ;

	return 0 ;
}
