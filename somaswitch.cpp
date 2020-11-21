#include <stdio.h>

int main (void) {

	int op = 0;
	float n1, n2, total;

	while (op != 5) {

		printf("1 - soma\n");
		printf("2 - subtracao\n");
		printf("3 - multiplicacao\n");
		printf("4 - divisao\n");
		printf("5 - sair\n\n");
		printf("Digite uma operacao: ");
		scanf("%d", &op);

		switch (op) {
			case 1 : {
				printf("\n[SOMA]\n");
				printf("Digite o primeiro valor: ");
				scanf("%f", &n1);
				printf("\nDigite o segundo valor: ");
				scanf("%f", &n2);
				total = n1 + n2;
				printf("\nO resultado e: %0.2f\n\n", total);
				break;
			}
			case 2 : {
				printf("\n[SUBTRACAO]\n");
				printf("Digite o primeiro valor: ");
				scanf("%f", &n1);
				printf("\nDigite o segundo valor: ");
				scanf("%f", &n2);
				total = n1 - n2;
				printf("\nO resultado e: %0.2f\n\n", total);
				break;
			}
			case 3 : {
				printf("\n[MULTIPLICACAO]\n");
				printf("Digite o primeiro valor: ");
				scanf("%f", &n1);
				printf("Digite o segundo valor: ");
				scanf("%f", &n2);
				total = n1 * n2;
				printf("\nO resultado e: %0.2f\n\n", total);
				break;
			}
			case 4 : {
				printf("\n[DIVISAO]\n");
				printf("Digite o primeiro valor: ");
				scanf("%f", &n1);
				printf("\nDigite o segundo valor: ");
				scanf("%f", &n2);
				total = n1 / n2;
				printf("\nO resultado e: %0.2f\n\n", total);
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
