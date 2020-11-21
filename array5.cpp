#include <stdio.h>
#include <stdlib.h>

int main(void){

	int matriz[5],i;
	
	for (i = 0; i < 5; i++) {
	printf ("Digite o numero aleatorio: ");	
	scanf("%x", &matriz[i]);
	}
	for (i = 0; i < 5; i++){
	printf("\n%x ", matriz[i]);
  }
}
