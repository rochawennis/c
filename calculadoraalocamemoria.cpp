#include <stdio.h>
#include <stdlib.h>

main(void){
	float *v;
	int n, i;
	float media = 0;

	
	printf("Informe a quantidade de alunos: ");
	scanf("%d", &n);
		
	v = (float*) malloc(sizeof(float)*n);
	if (v == NULL) {
		printf("Memoria insuficiente.\n");
		exit(1);
	}
	
	printf("Memoria alocada com sucesso\n");

	for (i = 0; i<n; i++){
		printf("\nInforme a %d nota: ", i+1);
		scanf("%f", &v[i]);
	}
	for (i = 0; i<n; i++)
	media = media + v[i];
	media = media/n;	
	printf("\nMedia: %.2f", media);
	
	
	
	free(v);
	
	return 0;
	


}
