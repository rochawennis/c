
#include <stdio.h>

#define LIN 4
#define COL 4


int main(void) {

  float matriz[LIN][COL], maior;
  int i,j, linMaior = 0, colMaior = 0;

  for (i = 0; i < LIN; i++) {
    for (j = 0; j < COL; j++){	
		  printf ("Digite um número: ");
      scanf ("%f", &matriz[i][j]);
	  }
  }
maior = matriz[linMaior][colMaior];
  
  for (i = 0; i < LIN; i++)
  {
    printf("\n");
    for (j = 0; j < COL; j++)
    {
      printf("%.3f ", matriz[i][j]);
      if (matriz[i][j] > maior)
      {
        maior = matriz[i][j];
        linMaior = i;
        colMaior = j;
      }
    }
  }
 printf("\n\no maior elemento é: %.3f e está localizado na linha %d e coluna %d", maior, linMaior, colMaior  );
  
  return 0;
}


