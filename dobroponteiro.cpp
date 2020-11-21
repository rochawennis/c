#include <stdio.h>

float Dobro (float *i, float *j) { 
	*i = 2*(*i);
	*j = 2*(*j);
  	return *i + (*j) ;
}

int main() {
float i, j, dobro;
i = 3;
j = 4;
printf("i = %f, j = %f\n", i, j);
dobro = Dobro(&i, &j);
printf("i = %f, j = %f\n", i, j);
return 0;
}
