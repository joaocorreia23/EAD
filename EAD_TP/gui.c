#include <stdio.h>
#include <stdlib.h>

#include "gui.h"


#pragma region MENUS

void mostraMenu() {
	printf("*******************************************\n");
	printf("*                   MENU                  *\n");
	printf("*******************************************\n\n");

	printf("1. Máquinas \n");
	printf("2. Operações \n");
	printf("3. Trabalhos \n");
	printf("0. Sair! \n\n");

	printf("*******************************************\n\n");

	printf("Opção: ");
}

void mostraMaquinasMenu() {
	printf("*******************************************\n");
	printf("*                Máquinas                 *\n");
	printf("*******************************************\n\n");

	printf("1. Listar Máquinas \n");
	printf("2. Inserir Nova Máquina \n");
	//printf("3. Remover Máquina \n");
	//printf("4. Alterar Máquina \n");
	printf("0. Sair! \n\n");

	printf("*******************************************\n\n");

	printf("Opção: ");
}

void mostraOperacoesMenu() {
	printf("*******************************************\n");
	printf("*                 OPERAÇÕES               *\n");
	printf("*******************************************\n\n");

	printf("1. Listar Operações \n");
	printf("2. Inserir Nova Operação \n");
	printf("3. Remover Operação \n");
	printf("4. Alterar Operação \n");
	printf("5. Associar Máquina \n");
	printf("6. Desassociar Máquina \n");
	printf("0. Sair! \n\n");

	printf("*******************************************\n\n");

	printf("Opção: ");
}

void mostraTrabalhosMenu() {
	printf("*******************************************\n");
	printf("*                 TRABALHOS               *\n");
	printf("*******************************************\n\n");

	printf("1. Listar Trabalhos \n");
	printf("0. Sair! \n\n");

	printf("*******************************************\n\n");

	printf("Opção: ");
}

#pragma endregion


#pragma region OPERAÇÕES

Operacao* associaMaquina(Operacao* operacao, Maquina* maquina) {
	int idMaq, idOp = 0;

	listarOperacoes(operacao, maquina);

	printf("ID da Operação: ");
	scanf("%d", &idOp);


	listarMaquinas(maquina);

	printf("ID da Máquina Para Associar: ");
	scanf("%d", &idMaq);


	return associarMaquina(operacao, idOp, idMaq);
}

Operacao* desassociaMaquina(Operacao* operacao, Maquina* maquina) {
	int idMaq, idOp = 0;

	listarOperacoes(operacao, maquina);

	printf("ID da Operação: ");
	scanf("%d", &idOp);


	listarMaquinas(maquina);

	printf("ID da Máquina Para Desassociar: ");
	scanf("%d", &idMaq);


	return desassociarMaquina(operacao, idOp, idMaq);
}

#pragma endregion

