#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main(void) {
	int *v, *m;
	int n, i, j, acertos = 0;

	srand(time(NULL));

	printf("Informe a quantidade de numeros (1-20): ");
	scanf("%d", &n);
	for (i = 0; i<n; i++) {
		if (n>20) {
			printf("Informe a quantidade de numeros (1-20): ");
			scanf("%d", &n);
		}
	}

	v = (int*) malloc(sizeof(int)*n);
	m = (int*) malloc(sizeof(int)*n);
	if (v == NULL) {
		printf("Memoria insuficiente.\n");
		exit(1);
	}

	printf("Memoria alocada com sucesso\n");

	for (i = 0; i<n; i++) {
		printf("\nInforme o %d numero (0-100): ", i+1);
		scanf("%d", &v[i]);
		if (v[i]>100) {
			do {
				printf("Informe o %d numero (0-100): ", i+1);
				scanf("%d", &v[i]);
			} while (v[i]>100);
		}
	}
	printf("\nNumeros sorteados");
	printf("\n----------------");
	for (j = 0; j<n; j++) {
		m[j] = rand()%10;
		printf("\n%d", m[j]);
		printf("\n----------------");
	}
	printf("\n");

	printf("\nResultado");
	printf("\n----------------");
	for (i = 0; i<n; i++) {
		for (j = 0; j<n; j++) {
			if (v[i] == m[j]) {
				for (j = 0; j<n; j++);
				printf("\n%d ->Foi sorteado", v[i]);
				printf("\n----------------\n");
				acertos++;
			}
		}
	}
	printf("\nAcertos -> %d\n", acertos);

	free(v);
	free(m);

	return 0;

}

