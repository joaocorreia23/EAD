#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>

struct job {
	char nome[40];
	int operacoes;
}job;

close() {
	printf("*******************************************\n");
	printf("*           Até Breve, Obrigado!          *\n");
	printf("*******************************************\n");

	exit(0);
}

main() {

	char* locale;
	locale = setlocale(LC_ALL, "");

	int option;

	printf("*******************************************\n");
	printf("*                   MENU                  *\n"); 
	printf("*******************************************\n\n");

	printf("1. Inserir Nova Operação \n");
	printf("2. Remover Operação \n");
	printf("3. Alterar Operação \n");
	printf("4. Quantidade Minima de Tempo \n");
	printf("5. Quantidade Máxima de Tempo \n");
	printf("6. Quantidade Média de Tempo \n");
	printf("0. Sair! \n\n");

	printf("*******************************************\n\n");

	printf("Opção: ");
	scanf("%d", &option);

	system("cls");

	switch (option)
	{
	case 1:
		break;

	case 2:
		break;

	case 3:
		break;

	case 4:
		break;

	case 5:
		break;

	case 0:
		close();
		break;

	default:
		printf("Opção Inválida\n\n");
		system("pause");
	}
}
