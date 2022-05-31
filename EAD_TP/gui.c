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

	printf("1. Adicionar um Trabalho\n");
	printf("2. Remover um Trabalho\n");
	printf("3. Listar Trabalhos \n");
	printf("4. Associar Opera��o a um Job \n");
	printf("5. Desassociar Opera��o a um Job \n");
	printf("6. Minimo Tempo de um Trabalho \n");
	printf("7. M�ximo Tempo de um Trabalho \n");
	printf("8. M�dia Tempo de um Trabalho \n");
	printf("9. Exportar Trabalho \n");
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


#pragma region TRABALHOS
//Fun��es para fazer o CRUD dos Trabalhos (Jobs)

Job* criaJob(Job* trabalho) {
	char nomeJob[MAXNOME];
	int idJob = 0;
	Operacao* operacoes = NULL; 

	idJob = autoIdJob(idJob);

	printf("Nome da Trabalho (Job): ");
	scanf("%s", &nomeJob);

	return inserirJob(trabalho, idJob, nomeJob, operacoes);
}

Job* removeJob(Job* trabalho) {
	int idJob = 0;

	listarApenasJobs(trabalho);

	printf("ID do Trabalho (Job) para Eliminar: ");
	scanf("%d", &idJob);


	return removerJob(trabalho, idJob);
}

Job* associaOperacao(Job* trabalho, Operacao* operacao) {
	int idJob, idOp = 0;

	listarApenasOperacoes(operacao);

	printf("ID da Opera��o Para Associar: ");
	scanf("%d", &idOp);


	listarApenasJobs(trabalho);

	printf("ID do Job: ");
	scanf("%d", &idJob);


	return associarOperacao(trabalho, idOp, idJob);
}

Job* desassociaOperacao(Job* trabalho, Operacao* operacao) {
	int idJob, idOp = 0;

	listarApenasJobs(trabalho);

	printf("ID do Job: ");
	scanf("%d", &idJob);

	listarApenasOperacoes(operacao);

	printf("ID da Opera��o Para Associar: ");
	scanf("%d", &idOp);

	return desassociarOperacao(trabalho, idJob, idOp);
}

#pragma endregion