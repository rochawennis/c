#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct Data {

	int dia;
	int mes;
	int ano;

};

int main(void) {
	struct Data hoje;
	hoje.dia;
	hoje.mes;
	hoje.ano;

	printf("Digite o dia: ");
	scanf("%d", &hoje.dia);

	printf("Digite o mes: ");
	scanf("%d", &hoje.mes);

	printf("Digite o ano: ");
	scanf("%d", &hoje.ano);
	
	printf("%d/""%d/""%d", hoje.dia, hoje.mes, hoje.ano);
	
	return 0;
}
