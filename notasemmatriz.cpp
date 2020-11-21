#include <stdio.h>
#include <stdlib.h>

#define LIN 5
#define COL 10

int main(void)	{

  int resposta[LIN][COL], gabarito[COL], notas[LIN];
  int i,j;
  

  for (i = 0; i < LIN; i++) {
    for (j = 0; j < COL; j++){
		printf("Digite a resposta %d do aluno %d: ",j,i);
		scanf("%d", &resposta[i][j]);
      }
  }
  for ( j= 0; j < COL; j++){
  printf("Digite a resposta correta do aluno %d: ",j);
  scanf("%d", &gabarito[j]);
  }
  for (i = 0; i < LIN; i++){
  notas[i]=0 ;
  for (j = 0; j <COL; j++){
  	if (resposta[i][j] == gabarito[j])
  	notas[i] = notas[i]+1;
	  }
  }
  for (i = 0; i< LIN; i++){
  	  printf("\nResposta e gabarito:\n");
  	  for (j = 0; j < COL; j++){
  	  	  printf("%d, %d\n", resposta[i][j], gabarito[j]);
		}
		  printf("A nota do aluno %d foi %d\n",i, notas[i]);
  }
  return 0;
}
