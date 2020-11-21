#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Aluno {

	int RA;
	char nome[70];
	float nota[3];

};

int main(void) {
	struct Aluno aluno;
	int i;
	
	float media = 0;
	
	printf("Digite seu RA: ");
	scanf("%d", &aluno.RA);

	getchar();
	printf("Digite seu nome: ");
	gets(aluno.nome);
	
	for (i = 0; i <3; i++){
		printf("nota de avaliacao %d\n", i+1);
		scanf("%f", &aluno.nota[i]);
	}

	for (i = 0; i <3; i++){
		media += aluno.nota[i];
	}
	
	media = media/3;


	printf("\nRA: %d\n", aluno.RA);
	printf("Nome: ");
	puts(aluno.nome);
	printf("AV1: %.1f; AV2: %.1f; AV3: %.1f\n", aluno.nota[0], aluno.nota[1], aluno.nota[2]);
	printf("Media final: %.1f", media);

	return 0;
}
