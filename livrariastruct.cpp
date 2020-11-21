#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Livro {
	
	char titulo[70];
	char autor[70];
	char editora[70];
	int ano;
	
};


int main(void) {
	
	struct Livro livraria;
	
	printf("Digite titulo do livro: ");
	gets(livraria.titulo);
	
	printf("Digite o autor: ");
	gets(livraria.autor);
	
	printf("Digite o editora: ");
	gets(livraria.editora);
	
	printf("Digite o ano de lancamento: ");
	scanf("%d", &livraria.ano);
	
	printf("\nTitulo: ");
	puts(livraria.titulo);
	printf("Autor: ");
	puts(livraria.autor);
	printf("Editora: ");
	puts(livraria.editora);
	printf("Ano: %d", livraria.ano);
	
}
