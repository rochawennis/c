#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data {

	int dia, mes, ano;

};

struct Endereco {
	char rua[20], numero[20], bairro[20];
};

struct Pessoa {

	char nome [80];
	struct Data dataNasc;
	struct Endereco endRes;
};

int main(void) {

	struct Pessoa pessoa;

	printf("Nome: ");
	gets(pessoa.nome);

	printf("Dia do nascimento: ");
	scanf("%d", &pessoa.dataNasc.dia);

	printf("Mes do nascimento: ");
	scanf("%d", &pessoa.dataNasc.mes);

	printf("Ano do nascimento: ");
	scanf("%d", &pessoa.dataNasc.ano);

	getchar();
	printf("Rua: ");
	gets(pessoa.endRes.rua);
	printf("Numero: ");
	gets(pessoa.endRes.numero);
	printf("Bairro: ");
	gets(pessoa.endRes.bairro);

	printf("\nNome: ");
	puts(pessoa.nome);
	printf("Data de Nascimento: %d/%d/%d\n", pessoa.dataNasc.dia, pessoa.dataNasc.mes,pessoa.dataNasc.ano );
	printf("Endereco: ");
	puts(pessoa.endRes.rua);
	puts(pessoa.endRes.numero);
	puts(pessoa.endRes.bairro);





}
