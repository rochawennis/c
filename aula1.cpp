#include <stdio.h>
#define TAM 5

int main(void) {
int vetor[TAM];
int i, maior, menor, pomaior, pomenor, par, impar;
par = 0;
impar = 0;
for (i = 0; i < TAM; i++) {
printf ("Digite o numero aleatorio %d: ", i);
scanf ("%d", &vetor[i]);
//encontra o maior e menor
maior = vetor[0];
menor = vetor[0];
}
for (i = 1; i < TAM; i++){
	
/*if (vetor[i] % 2 == 0){
	par++;
	}
else if (vetor[i] % 2 != 0){
	impar++;
	}
}*/

if (vetor[i]>maior){

maior = vetor[i];
pomaior=i;
}
else if (vetor[i]<menor){

menor = vetor [i];
pomenor=i;
}
}
printf("\nO maior valor e: %d, O menor valor e: %d, a posicao do maior valor esta na posicao: %d, e a posicao do menor valor esta na posicao: %d \n", maior, menor, pomaior, pomenor);
return 0;

/*printf("\nQuantidade de pares e: %d, Quantidade de impares e: %d", par, impar);
return 0;*/
}
