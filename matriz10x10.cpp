#include <stdio.h>

#define LIN 10
#define COL 10

int main(void) {

  int matriz[LIN][COL];
  int i,j;

  for (i = 0; i < LIN; i++) {
    for (j = 0; j < COL; j++){	
		  if (i < j)
        matriz[i][j] = 2*i+7*j-2;
      else if( i == j)
        matriz[i][j] = 3*i*i-1;
      else 
        matriz[i][j] = 4*i*i*i-5*j*+1;
      }
  }
  for (i = 0; i < LIN; i++)
  {
    printf("\n");
    for (j = 0; j < COL; j++)
    {
      printf("%d ", matriz[i][j]);
      }
  }
  return 0;
}
