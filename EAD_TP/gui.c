#include <string.h>
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
	//printf("6. Minimo Tempo de um Trabalho \n");
	//printf("7. M�ximo Tempo de um Trabalho \n");
	//printf("8. M�dia Tempo de um Trabalho \n");
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


	Operacao* opAux = operacao;
	while (opAux != NULL && strcmp(opAux->nome, name) != 0)
		opAux = opAux->seguinte;

	if (opAux != NULL) {
		printf("\n\J� existe uma opera��o com o nome '%s'\n", name);
		return operacao;
	}

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
	int idOp = 0, idMaq = 0, found = 0;

	do
	{
		listarOperacoes(operacao, maquina);

		printf("ID da Opera��o: ");
		scanf("%d", &idOp);

		Operacao* opAux = operacao;
		while (opAux != NULL && opAux->idOp != idOp)
			opAux = opAux->seguinte;

		if (opAux == NULL) {
			idOp = 0;
			system("cls");
			printf("Escolha inv�lida\n");
			system("pause");
			system("cls");
		}
	} while (idOp == 0);

	system("cls");

	do
	{
		printf("ID da Opera��o: %d\n", idOp);

		listarMaquinas(maquina);

		printf("ID da M�quina Para Associar: ");
		scanf("%d", &idMaq);

		Maquina* maqAux = maquina;
		while (maqAux != NULL && maqAux->idMaq != idMaq)
			maqAux = maqAux->seguinte;

		if (maqAux == NULL) {
			idMaq = 0;
			system("cls");
			printf("Escolha inv�lida\n");
			system("pause");
			system("cls");
		}
	} while (idMaq == 0);

	// Verifica��o de Existencia de M�quinas j� Associadas
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
		printf("\n\nA M�quina '%d' j� est� associada a opera��o '%d'\n", idMaq, idOp);
		return operacao;
	}

	return associarMaquina(operacao, idOp, idMaq);
}

Operacao* desassociaMaquina(Operacao* operacao, Maquina* maquina) {
	int idOp = 0, idMaq = 0, found = 0;

	do
	{
		listarOperacoes(operacao, maquina);

		printf("ID da Opera��o: ");
		scanf("%d", &idOp);

		Operacao* opAux = operacao;
		while (opAux != NULL && opAux->idOp != idOp)
			opAux = opAux->seguinte;

		if (opAux == NULL) {
			idOp = 0;
			system("cls");
			printf("Escolha inv�lida\n");
			system("pause");
			system("cls");
		}
	} while (idOp == 0);

	system("cls");

	do
	{
		printf("ID da Opera��o: %d\n", idOp);

		listarMaquinas(maquina);

		printf("ID da M�quina Para Desassociar: ");
		scanf("%d", &idMaq);

		Maquina* maqAux = maquina;
		while (maqAux != NULL && maqAux->idMaq != idMaq)
			maqAux = maqAux->seguinte;

		if (maqAux == NULL) {
			idMaq = 0;
			system("cls");
			printf("Escolha inv�lida\n");
			system("pause");
			system("cls");
		}
	} while (idMaq == 0);

	// Verifica��o de Existencia de M�quinas j� n�o Associadas
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
		printf("\n\nA M�quina '%d' n�o est� associada a opera��o '%d'\n", idMaq, idOp);
		return operacao;
	}
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

	Maquina* maqAux = maquina;
	while (maqAux != NULL && strcmp(maqAux->nomeMaquina, name) != 0)
		maqAux = maqAux->seguinte;

	if (maqAux != NULL) {
		printf("\n\J� existe uma M�quina com o nome '%s'\n", name);
		return maquina;
	}

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

	printf("Nome do Trabalho (Job): ");
	scanf("%s", &nomeJob);

	Job* jobAux = trabalho;
	while (jobAux != NULL && strcmp(jobAux->nomeJob, nomeJob) != 0)
		jobAux = jobAux->seguinte;

	if (jobAux != NULL) {
		printf("\n\J� existe um trabalho com o nome '%s'\n", nomeJob);
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
			printf("Escolha inv�lida\n");
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

		printf("ID da Opera��o Para Associar: ");
		scanf("%d", &idOp);

		Operacao* opAux = operacao;
		while (opAux != NULL && opAux->idOp != idOp)
			opAux = opAux->seguinte;

		if (opAux == NULL) {
			idOp = 0;
			system("cls");
			printf("Escolha inv�lida\n");
			system("pause");
			system("cls");
		}
	} while (idOp == 0);

	system("cls");

	do
	{
		printf("ID da Opera��o: %d\n", idOp);

		listarApenasJobs(trabalho);

		printf("ID do Job: ");
		scanf("%d", &idJob);

		Job* jobAux = trabalho;
		while (jobAux != NULL && jobAux->idJob != idJob)
			jobAux = jobAux->seguinte;

		if (jobAux == NULL) {
			idJob = 0;
			system("cls");
			printf("Escolha inv�lida\n");
			system("pause");
			system("cls");
		}
	} while (idJob == 0);

	// Verifica��o de Existencia de Opera��es j� Associadas
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
		printf("\n\nA Opera��o '%d' j� est� associada ao trabalho '%d'\n", idOp, idJob);
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
			printf("Escolha inv�lida\n");
			system("pause");
			system("cls");
		}
	} while (idJob == 0);

	system("cls");

	do
	{
		printf("ID do Trabalho: %d\n", idJob);

		listarApenasOperacoes(operacao);

		printf("ID da Opera��o Para desassociar: ");
		scanf("%d", &idOp);

		Operacao* opAux = operacao;
		while (opAux != NULL && opAux->idOp != idOp)
			opAux = opAux->seguinte;

		if (opAux == NULL) {
			idOp = 0;
			system("cls");
			printf("Escolha inv�lida\n");
			system("pause");
			system("cls");
		}
	} while (idOp == 0);

	// Verifica��o de Existencia de Opera��es j� Associadas
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
		printf("\n\nA Opera��o '%d' n�o est� associada ao trabalho '%d'\n", idOp, idJob);
		return trabalho;
	}
}

#pragma endregion