#include <string.h>
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
	//printf("6. Minimo Tempo de um Trabalho \n");
	//printf("7. Máximo Tempo de um Trabalho \n");
	//printf("8. Média Tempo de um Trabalho \n");
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


	Operacao* opAux = operacao;
	while (opAux != NULL && strcmp(opAux->nome, name) != 0)
		opAux = opAux->seguinte;

	if (opAux != NULL) {
		printf("\n\Já existe uma operação com o nome '%s'\n", name);
		return operacao;
	}

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
	int idOp = 0, idMaq = 0, found = 0;

	do
	{
		listarOperacoes(operacao, maquina);

		printf("ID da Operação: ");
		scanf("%d", &idOp);

		Operacao* opAux = operacao;
		while (opAux != NULL && opAux->idOp != idOp)
			opAux = opAux->seguinte;

		if (opAux == NULL) {
			idOp = 0;
			system("cls");
			printf("Escolha inválida\n");
			system("pause");
			system("cls");
		}
	} while (idOp == 0);

	system("cls");

	do
	{
		printf("ID da Operação: %d\n", idOp);

		listarMaquinas(maquina);

		printf("ID da Máquina Para Associar: ");
		scanf("%d", &idMaq);

		Maquina* maqAux = maquina;
		while (maqAux != NULL && maqAux->idMaq != idMaq)
			maqAux = maqAux->seguinte;

		if (maqAux == NULL) {
			idMaq = 0;
			system("cls");
			printf("Escolha inválida\n");
			system("pause");
			system("cls");
		}
	} while (idMaq == 0);

	// Verificação de Existencia de Máquinas já Associadas
	Operacao* opAux = operacao;
	while (opAux != NULL) {
		OperacaoMaquina* OpMaqAux = opAux->maquinas;
		while (OpMaqAux != NULL) {
			if (OpMaqAux->idOp == idOp && OpMaqAux->idMaq == idMaq) {
				found = 1;
			}
			OpMaqAux = OpMaqAux->seguinte;
		}
		opAux = opAux->seguinte;
	}
	if (found == 1) {
		printf("\n\nA Máquina '%d' já está associada a operação '%d'\n", idMaq, idOp);
		return operacao;
	}

	return associarMaquina(operacao, idOp, idMaq);
}

Operacao* desassociaMaquina(Operacao* operacao, Maquina* maquina) {
	int idOp = 0, idMaq = 0, found = 0;

	do
	{
		listarOperacoes(operacao, maquina);

		printf("ID da Operação: ");
		scanf("%d", &idOp);

		Operacao* opAux = operacao;
		while (opAux != NULL && opAux->idOp != idOp)
			opAux = opAux->seguinte;

		if (opAux == NULL) {
			idOp = 0;
			system("cls");
			printf("Escolha inválida\n");
			system("pause");
			system("cls");
		}
	} while (idOp == 0);

	system("cls");

	do
	{
		printf("ID da Operação: %d\n", idOp);

		listarMaquinas(maquina);

		printf("ID da Máquina Para Desassociar: ");
		scanf("%d", &idMaq);

		Maquina* maqAux = maquina;
		while (maqAux != NULL && maqAux->idMaq != idMaq)
			maqAux = maqAux->seguinte;

		if (maqAux == NULL) {
			idMaq = 0;
			system("cls");
			printf("Escolha inválida\n");
			system("pause");
			system("cls");
		}
	} while (idMaq == 0);

	// Verificação de Existencia de Máquinas já não Associadas
	Operacao* opAux = operacao;
	while (opAux != NULL) {
		OperacaoMaquina* OpMaqAux = opAux->maquinas;
		while (OpMaqAux != NULL) {
			if (OpMaqAux->idOp == idOp && OpMaqAux->idMaq == idMaq) {
				found = 1;
			}
			OpMaqAux = OpMaqAux->seguinte;
		}
		opAux = opAux->seguinte;
	}

	if (found == 1) {
		return desassociarMaquina(operacao, idOp, idMaq);
	}
	else {
		printf("\n\nA Máquina '%d' não está associada a operação '%d'\n", idMaq, idOp);
		return operacao;
	}
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

	Maquina* maqAux = maquina;
	while (maqAux != NULL && strcmp(maqAux->nomeMaquina, name) != 0)
		maqAux = maqAux->seguinte;

	if (maqAux != NULL) {
		printf("\n\Já existe uma Máquina com o nome '%s'\n", name);
		return maquina;
	}

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

	printf("Nome do Trabalho (Job): ");
	scanf("%s", &nomeJob);

	Job* jobAux = trabalho;
	while (jobAux != NULL && strcmp(jobAux->nomeJob, nomeJob) != 0)
		jobAux = jobAux->seguinte;

	if (jobAux != NULL) {
		printf("\n\Já existe um trabalho com o nome '%s'\n", nomeJob);
		return trabalho;
	}

	return inserirJob(trabalho, idJob, nomeJob, operacoes);
}

Job* removeJob(Job* trabalho) {
	int idJob = 0;

	do
	{
		listarApenasJobs(trabalho);

		printf("ID do Trabalho (Job) para Eliminar: ");
		scanf("%d", &idJob);

		Job* jobAux = trabalho;
		while (jobAux != NULL && jobAux->idJob != idJob)
			jobAux = jobAux->seguinte;

		if (jobAux == NULL) {
			idJob = 0;
			system("cls");
			printf("Escolha inválida\n");
			system("pause");
			system("cls");
		}
	} while (idJob == 0);

	return removerJob(trabalho, idJob);
}

Job* associaOperacao(Job* trabalho, Operacao* operacao) {
	int idJob = 0, idOp = 0, found = 0;

	do
	{
		listarApenasOperacoes(operacao);

		printf("ID da Operação Para Associar: ");
		scanf("%d", &idOp);

		Operacao* opAux = operacao;
		while (opAux != NULL && opAux->idOp != idOp)
			opAux = opAux->seguinte;

		if (opAux == NULL) {
			idOp = 0;
			system("cls");
			printf("Escolha inválida\n");
			system("pause");
			system("cls");
		}
	} while (idOp == 0);

	system("cls");

	do
	{
		printf("ID da Operação: %d\n", idOp);

		listarApenasJobs(trabalho);

		printf("ID do Job: ");
		scanf("%d", &idJob);

		Job* jobAux = trabalho;
		while (jobAux != NULL && jobAux->idJob != idJob)
			jobAux = jobAux->seguinte;

		if (jobAux == NULL) {
			idJob = 0;
			system("cls");
			printf("Escolha inválida\n");
			system("pause");
			system("cls");
		}
	} while (idJob == 0);

	// Verificação de Existencia de Operações já Associadas
	Job* jobAux = trabalho;
	while (jobAux != NULL) {
		JobOperation* JobOpAux = jobAux->operacoes;
		while (JobOpAux != NULL) {
			if (JobOpAux->idJob == idJob && JobOpAux->idOp == idOp) {
				found = 1;
			}
			JobOpAux = JobOpAux->seguinte;
		}
		jobAux = jobAux->seguinte;
	}
	if (found == 1) {
		printf("\n\nA Operação '%d' já está associada ao trabalho '%d'\n", idOp, idJob);
		return trabalho;
	}

	return associarOperacao(trabalho, idOp, idJob);
}

Job* desassociaOperacao(Job* trabalho, Operacao* operacao) {
	int idJob, idOp = 0, found = 0;

	do
	{
		listarApenasJobs(trabalho);

		printf("ID do Job: ");
		scanf("%d", &idJob);

		Job* jobAux = trabalho;
		while (jobAux != NULL && jobAux->idJob != idJob)
			jobAux = jobAux->seguinte;

		if (jobAux == NULL) {
			idJob = 0;
			system("cls");
			printf("Escolha inválida\n");
			system("pause");
			system("cls");
		}
	} while (idJob == 0);

	system("cls");

	do
	{
		printf("ID do Trabalho: %d\n", idJob);

		listarApenasOperacoes(operacao);

		printf("ID da Operação Para desassociar: ");
		scanf("%d", &idOp);

		Operacao* opAux = operacao;
		while (opAux != NULL && opAux->idOp != idOp)
			opAux = opAux->seguinte;

		if (opAux == NULL) {
			idOp = 0;
			system("cls");
			printf("Escolha inválida\n");
			system("pause");
			system("cls");
		}
	} while (idOp == 0);

	// Verificação de Existencia de Operações já Associadas
	Job* jobAux = trabalho;
	while (jobAux != NULL) {
		JobOperation* JobOpAux = jobAux->operacoes;
		while (JobOpAux != NULL) {
			if (JobOpAux->idJob == idJob && JobOpAux->idOp == idOp) {
				found = 1;
			}
			JobOpAux = JobOpAux->seguinte;
		}
		jobAux = jobAux->seguinte;
	}

	if (found == 1) {
		return desassociarOperacao(trabalho, idJob, idOp);
	}
	else {
		printf("\n\nA Operação '%d' não está associada ao trabalho '%d'\n", idOp, idJob);
		return trabalho;
	}
}

#pragma endregion