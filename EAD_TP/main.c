#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
// Include da Página Header para o Job
#include "job.h"

#define MAXNOME [40];

mostraMenu() {
	printf("*******************************************\n");
	printf("*                   MENU                  *\n");
	printf("*******************************************\n\n");

	printf("1. Listar Operações \n");
	printf("2. Inserir Nova Operação \n");
	printf("3. Remover Operação \n");
	printf("4. Alterar Operação \n");
	printf("5. Quantidade Minima de Tempo \n");
	printf("6. Quantidade Máxima de Tempo \n");
	printf("7. Quantidade Média de Tempo \n");
	printf("0. Sair! \n\n");

	printf("*******************************************\n\n");
}

close() {
	printf("*******************************************\n");
	printf("*           Até Breve, Obrigado!          *\n");
	printf("*******************************************\n");

	exit(0);
}

Operacao* criaOperacao(Operacao* operacao) {
	char name MAXNOME;
	float tempo;

	printf("Nome da Operação: ");
	scanf("%s", &name);

	printf("Tempo da Operação: ");
	scanf("%f", &tempo);


	return inserirOperacao(operacao, name, tempo);
}

Operacao* removeOperacao(Operacao* operacao) {
	char name MAXNOME;

	printf("Nome da Operação: ");
	scanf("%s", &name);


	return removerOperacao(operacao, name);
}

Operacao* editaOperacao(Operacao* operacao) {
	char name MAXNOME;
	char newName MAXNOME;
	float tempo;

	printf("Nome da Operação Para Editar: ");
	scanf("%s", &name);

	printf("Novo Nome da Operação: ");
	scanf("%s", &newName);

	printf("Novo Tempo da Operação: ");
	scanf("%f", &tempo);


	return alterarOperacao(operacao, name, newName, tempo);
}

main() {
	Operacao* op = NULL;
	int option;

	char* locale;
	locale = setlocale(LC_ALL, "");


	op = inserirOperacao(op, "00", 10);
	op = inserirOperacao(op, "01", 10);
	op = inserirOperacao(op, "02", 10);
	op = inserirOperacao(op, "03", 10);
	op = inserirOperacao(op, "04", 10);

	do
	{
		mostraMenu();

		printf("Opção: ");
		scanf("%d", &option);

		system("cls");

		switch (option)
		{
		case 1:
			listarOperacoes(op);
			system("pause");
			break;

		case 2:
			op = criaOperacao(op);
			break;

		case 3:
			listarOperacoes(op);
			op = removeOperacao(op);
			break;

		case 4:
			listarOperacoes(op);
			op = editaOperacao(op);
			break;

		case 5:
			break;

		case 6:
			break;

		case 7:
			break;

		case 0:
			close();
			break;

		default:
			printf("Opção Inválida\n\n");
			system("pause");
			break;

		}

		system("cls");
	} while (option != 0);

}
