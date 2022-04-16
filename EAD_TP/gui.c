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
	printf("2. Minimo Tempo de um Trabalho \n");
	printf("3. M�ximo Tempo de um Trabalho \n");
	printf("4. M�dia Tempo de um Trabalho \n");
	printf("5. Exportar Trabalho \n");
	printf("0. Sair! \n\n");

	printf("*******************************************\n\n");

	printf("Op��o: ");
}

void close() {
	printf("*******************************************\n");
	printf("*           At� Breve, Obrigado!          *\n");
	printf("*******************************************\n");

	exit(0);
}

#pragma endregion


#pragma region OPERA��ES
//Fun��es para fazer o CRUD das Opera��es

Operacao* criaOperacao(Operacao* operacao) {
	char name[MAXNOME];
	float tempo;
	int idOp = 0;
	Maquina* maquinas = NULL;

	idOp = autoIdOp(idOp);

	printf("Nome da Opera��o: ");
	scanf("%s", &name);

	return inserirOperacao(operacao, idOp, name, maquinas);
}

Operacao* removeOperacao(Operacao* operacao) {
	int idOp = 0;

	listarApenasOperacoes(operacao);

	printf("ID da Opera��o para Eliminar: ");
	scanf("%d", &idOp);


	return removerOperacao(operacao, idOp);
}

Operacao* editaOperacao(Operacao* operacao) {
	char newName[MAXNOME];
	float tempo;

	int idOp = 0;

	listarApenasOperacoes(operacao);

	printf("ID da Opera��o Para Editar: ");
	scanf("%d", &idOp);

	printf("Novo Nome da Opera��o: ");
	scanf("%s", &newName);

	return alterarOperacao(operacao, idOp, newName);
}

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


	printf("ID da M�quina Para Desassociar: ");
	scanf("%d", &idMaq);


	return desassociarMaquina(operacao, idOp, idMaq);
}

#pragma endregion


#pragma region M�QUINAS
//Fun��es para fazer o CRUD das M�quinas

Maquina* criaMaquina(Maquina* maquina) {
	char name[MAXNOME];
	float tempoOp;
	char localizacao[MAXNOME];
	int idMaq = 0;

	idMaq = autoIdOp(idMaq);

	printf("Nome da M�quina: ");
	scanf("%s", &name);

	printf("Tempo da M�quina: ");
	scanf("%f", &tempoOp);

	printf("Localiza��o da M�quina: ");
	scanf("%s", &localizacao);

	return inserirMaquina(maquina, idMaq, name, tempoOp, localizacao);
}

#pragma endregion