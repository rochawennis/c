#include <stdio.h>

float ENTRADA () {
	float n1;
	printf("Digite o primeiro valor: ");
	scanf("%f", &n1);
	return n1;
}
float SOMA(float n1, float n2);
float SUBTRACAO(float n1, float n2);
float MULTI(float n1, float n2);
float DIVISAO(float n1, float n2);

int main (void) {

	int op = 0;

	float total, n1, n2;

	while (op != 5) {

		printf("\n1 - soma\n");
		printf("2 - subtracao\n");
		printf("3 - multiplicacao\n");
		printf("4 - divisao\n");
		printf("5 - sair\n\n");
		printf("Digite uma operacao: ");
		scanf("%d", &op);

		switch (op) {
			case 1 : {
				printf("\n[SOMA]\n");
				n1 = ENTRADA();
				n2 = ENTRADA();
				total = SOMA(n1,n2);
				printf("\nO resultado e: %0.2f", total);
				break;
			}
			case 2 : {
				printf("\n[SUBTRACAO]\n");
				n1 = ENTRADA();
				n2 = ENTRADA();
				total = SUBTRACAO(n1,n2);
				printf("\nO resultado e: %0.2f", total);
				break;
			}
			case 3 : {
				printf("\n[MULTIPLICACAO]\n");
				n1 = ENTRADA();
				n2 = ENTRADA();
				total = MULTI(n1,n2);
				printf("\nO resultado e: %0.2f", total);
				break;
			}
			case 4 : {
				printf("\n[DIVISAO]\n");
				n1 = ENTRADA();
				n2 = ENTRADA();
				total = DIVISAO(n1,n2);
				printf("\nO resultado e: %0.2f", total);
				break;
			}
			case 5 : {
				break;
			}
			default : {
				printf("\nOpcao incorreta, escolha das abaixo!\n\n");
				break;
			}
		}
	}
}

float SOMA(float n1, float n2) {
	return n1 + n2;
}

float SUBTRACAO(float n1, float n2) {
	return n1 - n2;

}

float MULTI(float n1, float n2) {
	return n1 * n2;

}

float DIVISAO(float n1, float n2) {
	return n1 / n2;

}


