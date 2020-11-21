#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIN 5
#define COL 5

int main(void) {

  int matriz[LIN][COL];
  int i,j;
  
  srand(time(0));

  for (i = 0; i < LIN; i++) {
    for (j = 0; j < COL; j++){	
		matriz[i][j] = rand()%100;
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
