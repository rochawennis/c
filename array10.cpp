# include <stdio.h>

int main(void){
	float a[10];
	int i;
	
	for (i = 0; i <= 10; i++){
		
		a[i] = i*1.2;
		printf("\n%x", a[i]);
		
	}
	
	return 0;
}
