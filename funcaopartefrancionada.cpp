#include <stdio.h>

void Frac(float num, int* inteiro, float* frac){

  *inteiro = (int) num;
  *frac = num-*inteiro;
}

int main(void) {
float num, frac;
int inteiro;

printf("digite um numero qualquer: ");
scanf("%f", &num);

Frac(num, &inteiro, &frac);

printf("\nparte inteira do numero: %d; parte fracionada do numero: %.3f\n", inteiro, frac);

return 0;
}

