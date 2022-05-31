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

	printf("1. Adicionar um Trabalho\n");
	printf("2. Remover um Trabalho\n");
	printf("3. Listar Trabalhos \n");
	printf("4. Associar Operação a um Job \n");
	printf("5. Desassociar Operação a um Job \n");
	printf("6. Minimo Tempo de um Trabalho \n");
	printf("7. Máximo Tempo de um Trabalho \n");
	printf("8. Média Tempo de um Trabalho \n");
	printf("9. Exportar Trabalho \n");
	printf("0. Sair! \n\n");

	printf("*******************************************\n\n");

	printf("Opção: ");
}

void close() {
	printf("*******************************************\n");
	printf("*           Até Breve, Obrigado!          *\n");
	printf("*******************************************\n");

	exit(0);
}

#pragma endregion


#pragma region OPERAÇÕES
//Funções para fazer o CRUD das Operações

Operacao* criaOperacao(Operacao* operacao) {
	char name[MAXNOME];
	float tempo;
	int idOp = 0;
	Maquina* maquinas = NULL;

	idOp = autoIdOp(idOp);

	printf("Nome da Operação: ");
	scanf("%s", &name);

	return inserirOperacao(operacao, idOp, name, maquinas);
}

Operacao* removeOperacao(Operacao* operacao) {
	int idOp = 0;

	listarApenasOperacoes(operacao);

	printf("ID da Operação para Eliminar: ");
	scanf("%d", &idOp);


	return removerOperacao(operacao, idOp);
}

Operacao* editaOperacao(Operacao* operacao) {
	char newName[MAXNOME];
	float tempo;

	int idOp = 0;

	listarApenasOperacoes(operacao);

	printf("ID da Operação Para Editar: ");
	scanf("%d", &idOp);

	printf("Novo Nome da Operação: ");
	scanf("%s", &newName);

	return alterarOperacao(operacao, idOp, newName);
}

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


	printf("ID da Máquina Para Desassociar: ");
	scanf("%d", &idMaq);


	return desassociarMaquina(operacao, idOp, idMaq);
}

#pragma endregion


#pragma region MÁQUINAS
//Funções para fazer o CRUD das Máquinas

Maquina* criaMaquina(Maquina* maquina) {
	char name[MAXNOME];
	float tempoOp;
	char localizacao[MAXNOME];
	int idMaq = 0;

	idMaq = autoIdOp(idMaq);

	printf("Nome da Máquina: ");
	scanf("%s", &name);

	printf("Tempo da Máquina: ");
	scanf("%f", &tempoOp);

	printf("Localização da Máquina: ");
	scanf("%s", &localizacao);

	return inserirMaquina(maquina, idMaq, name, tempoOp, localizacao);
}

#pragma endregion


#pragma region TRABALHOS
//Funções para fazer o CRUD dos Trabalhos (Jobs)

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

	printf("ID da Operação Para Associar: ");
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

	printf("ID da Operação Para Associar: ");
	scanf("%d", &idOp);

	return desassociarOperacao(trabalho, idJob, idOp);
}

#pragma endregion