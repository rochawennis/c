#include <stdio.h>

void troca (int *i, int *j) { 
  int temp;
  temp = *i; 
  *i = *j; 
  *j = temp;
}

int main() {
int i, j;
i = 3;
j = 4;
printf("i = %d, j = %d\n", i, j);
troca(&i, &j);
printf("i = %d, j = %d\n", i, j);
return 0;
}
