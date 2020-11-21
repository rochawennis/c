#include<stdio.h>

#include<conio.h>

#include<string.h>

int main () {
	char palavra [] = "o sapo nao lava o pe. Nao lava porque nao quer. Ele mora la na lagoa. Nao lava o pe por que nao quer. Mas que chule";
	char vogais[] = "aeiou";
	int i,j;

	puts(palavra);
		printf("\n");
	for(j = 0; j < strlen(vogais); j++){
		for(i = 0; i < strlen(palavra); i++){
		if(palavra[i] == 'a'|| palavra[i] == 'e'|| palavra[i] == 'i' || palavra[i] == 'o' || palavra[i] == 'u'){
				palavra[i] = vogais[j];
				}
			}
			puts(palavra);
			printf("\n");
		}
	
}
