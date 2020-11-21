#include <stdio.h>

int n1, n;

int ENTRADA () {
	printf("Digite o primeiro valor: ");
	scanf("%d", &n1);
}
void DOBRO() {
	n = n1 * 2;
	printf ("\nDobro: %d", n);
}

int PARIDADE() {
	if (n1 % 2 == 0) {
		return(1);
	} else {
		return (0);
	}
}


int main (void) {
	ENTRADA ();
	DOBRO ();
	n1 = PARIDADE();
	if (n1 == 1) {
		printf("\n\nO numero digitado e par", n1);
	} else {
		printf ("\n\nO numero digitado e impar", n1);
	}
}





