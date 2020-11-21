#include <stdio.h>
#include <stdlib.h>

int main(void){
	int matriz[3][3],i,j;
	
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++){	
		  printf ("\n%x ", &matriz[i][j]);
	}
	printf("\n");
  }
}
