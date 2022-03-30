#include <stdio.h>
#include <stdlib.h>

#include "gui.h"


#pragma region MENUS

void mostraMenu() {
	printf("*******************************************\n");
	printf("*                   MENU                  *\n");
	printf("*******************************************\n\n");

	printf("1. M�quinas \n");
	printf("2. Opera��es \n");
	printf("3. Trabalhos \n");
	printf("0. Sair! \n\n");

	printf("*******************************************\n\n");

	printf("Op��o: ");
}

void mostraMaquinasMenu() {
	printf("*******************************************\n");
	printf("*                M�quinas                 *\n");
	printf("*******************************************\n\n");

	printf("1. Listar M�quinas \n");
	printf("2. Inserir Nova M�quina \n");
	//printf("3. Remover M�quina \n");
	//printf("4. Alterar M�quina \n");
	printf("0. Sair! \n\n");

	printf("*******************************************\n\n");

	printf("Op��o: ");
}

void mostraOperacoesMenu() {
	printf("*******************************************\n");
	printf("*                 OPERA��ES               *\n");
	printf("*******************************************\n\n");

	printf("1. Listar Opera��es \n");
	printf("2. Inserir Nova Opera��o \n");
	printf("3. Remover Opera��o \n");
	printf("4. Alterar Opera��o \n");
	printf("5. Associar M�quina \n");
	printf("6. Desassociar M�quina \n");
	printf("0. Sair! \n\n");

	printf("*******************************************\n\n");

	printf("Op��o: ");
}

void mostraTrabalhosMenu() {
	printf("*******************************************\n");
	printf("*                 TRABALHOS               *\n");
	printf("*******************************************\n\n");

	printf("1. Listar Trabalhos \n");
	printf("0. Sair! \n\n");

	printf("*******************************************\n\n");

	printf("Op��o: ");
}

#pragma endregion


#pragma region OPERA��ES

Operacao* associaMaquina(Operacao* operacao, Maquina* maquina) {
	int idMaq, idOp = 0;

	listarOperacoes(operacao, maquina);

	printf("ID da Opera��o: ");
	scanf("%d", &idOp);


	listarMaquinas(maquina);

	printf("ID da M�quina Para Associar: ");
	scanf("%d", &idMaq);


	return associarMaquina(operacao, idOp, idMaq);
}

Operacao* desassociaMaquina(Operacao* operacao, Maquina* maquina) {
	int idMaq, idOp = 0;

	listarOperacoes(operacao, maquina);

	printf("ID da Opera��o: ");
	scanf("%d", &idOp);


	listarMaquinas(maquina);

	printf("ID da M�quina Para Desassociar: ");
	scanf("%d", &idMaq);


	return desassociarMaquina(operacao, idOp, idMaq);
}

#pragma endregion

