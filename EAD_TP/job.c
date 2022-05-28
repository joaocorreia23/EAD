#include <string.h>
#include <stdlib.h>
#include "job.h"

// Fun��o para Listar todos os Jobs
void listarJobs(Job* trabalho, Maquina* maquina) {

	Job* jobAux = trabalho;

	printf("*************************************************************************************************\n");
	printf("*                                     LISTA DE TRABALHOS                                        *\n");
	printf("*************************************************************************************************\n\n");

	while (jobAux != NULL)
	{
		printf("ID JOB: %d   Nome Trabalho: %s\n", jobAux->idJob, jobAux->nomeJob);
		Operacao* opAux = jobAux->operacoes;
		printf("------------------------------------------------------------------------------------------------\n");
		while (opAux != NULL) {
			printf("\tID: %d     Nome Opera��o: %s\n", opAux->idOp, opAux->nome);

			OperacaoMaquina* maqAux = opAux->maquinas;
			printf("------------------------------------------------------------------------------------------------\n");
			while (maqAux != NULL)
			{
				Maquina* maquinaAux = maquina;
				while (maquinaAux != NULL && maquinaAux->idMaq != maqAux->idMaq)
					maquinaAux = maquinaAux->seguinte;

				if (maquinaAux != NULL)
					printf("\t\tID: %d   Nome M�quina: %s     Tempo M�quina: %.2f     Localiza��o: %s\n", maquinaAux->idMaq, maquinaAux->nomeMaquina, maquinaAux->tempoOp, maquinaAux->localizacao);

				maqAux = maqAux->seguinte;
			}
			printf("------------------------------------------------------------------------------------------------\n");

			opAux = opAux->seguinte;
		}
		printf("=====================================================================================================\n");
		printf("=====================================================================================================\n\n");
		jobAux = jobAux->seguinte;
	}
	printf("\n*************************************************************************************************\n");
}

// Fun�o para Listar Apenas os Jobs
void listarApenasJobs(Job* trabalho) {
	printf("********************************************\n");
	printf("*            LISTA DE TRABALHOS            *\n");
	printf("********************************************\n\n");
	while (trabalho != NULL)
	{
		printf("ID: %d     Nome Trabalho (Job): %s\n", trabalho->idJob, trabalho->nomeJob);
		printf("-------------------------------------------\n");
		trabalho = trabalho->seguinte;
	}
	printf("\n********************************************\n");
}

// Fun��o para Adicionar Jobs
Job* inserirJob(Job* trabalho, int idJob, char nomeJob[], Operacao* operacoes) {
	Job* novo = (Job*)malloc(sizeof(Job));

	if (novo != NULL) {
		novo->idJob = idJob;
		strcpy(novo->nomeJob, nomeJob);
		novo->operacoes = operacoes;
		novo->seguinte = trabalho;
		return(novo);
	}
	else {
		return(trabalho);
	}
}

// Fun��o para Remover Job por ID
Job* removerJob(Job* trabalho, int idJob) {
	//Declara��o dos nodo's para armazenar a informa��o das opera��es
	Job* nodoAtual = trabalho;
	Job* nodoAnterior;

	if (nodoAtual->idJob == idJob) {
		trabalho = nodoAtual->seguinte;
		free(nodoAtual);
	}
	else {
		nodoAnterior = trabalho; // Armazena a informa��o da opera��o 
		nodoAtual = nodoAnterior->seguinte; // Segue para a proxima opera��o 
		while ((nodoAtual != NULL) && (nodoAtual->idJob != idJob)) {
			nodoAnterior = nodoAtual;
			nodoAtual = nodoAtual->seguinte;
		}
		if (nodoAtual != NULL)
		{
			nodoAnterior->seguinte = nodoAtual->seguinte;
			free(nodoAtual);
		}
	}
	return(trabalho);
}

//Fun��o para Calcular o Valor M�nimo para Completar um Job
void minimoTempo(Job* trabalho, int idJob, Maquina* maquina) {

	float MelhorTempoTotalJob = 0;
	Job* listaDeTrabalhos = trabalho;
	Maquina* MaquinaAux = (Maquina*)malloc(sizeof(Maquina));

	while (listaDeTrabalhos != NULL) {

		if (listaDeTrabalhos->idJob == idJob) {
			printf("*****************************************\n");
			printf("*      Nome do Trabalho: %s      *\n", listaDeTrabalhos->nomeJob);
			printf("*****************************************\n\n");
			Operacao* listaDeOperacoes = listaDeTrabalhos->operacoes;

			while (listaDeOperacoes != NULL)
			{
				printf("ID: %d     Nome Opera��o: %s\n", listaDeOperacoes->idOp, listaDeOperacoes->nome);
				OperacaoMaquina* opMaqAux = listaDeOperacoes->maquinas;
				printf("----------------------------------------------------------------------------------------\n");

				MaquinaAux = NULL;

				while (opMaqAux != NULL) {

					Maquina* maqAux = maquina;

					while (maqAux != NULL) {
						if (maqAux->idMaq == opMaqAux->idMaq) {
							if (MaquinaAux != NULL && MaquinaAux->tempoOp > maqAux->tempoOp) {
								MaquinaAux = maqAux;
							}
							else if (MaquinaAux == NULL) {
								MaquinaAux = maqAux;
							}
							printf("\tID: %d   Nome M�quina: %s     Tempo M�quina: %.2f     Localiza��o: %s\n", maqAux->idMaq, maqAux->nomeMaquina, maqAux->tempoOp, maqAux->localizacao);
						}
						maqAux = maqAux->seguinte;
					}
					opMaqAux = opMaqAux->seguinte;

				}
				MelhorTempoTotalJob += MaquinaAux->tempoOp;
				printf("----------------------------------------------------------------------------------------\n\n");
				listaDeOperacoes = listaDeOperacoes->seguinte;
			}

			printf("*********************************************************************************\n");
			printf("     O Minimo Tempo para Realizar este Trabalho �: %.2f Unidades de Tempo\n", MelhorTempoTotalJob);
			printf("*********************************************************************************\n");
		}
		listaDeTrabalhos = listaDeTrabalhos->seguinte;
	}
}

//Fun��o para Calcular o Valor M�ximo para Completar um Job
void maximoTempo(Job* trabalho, int idJob, Maquina* maquina) {
	float PiorTempoTotalJob = 0;
	Job* listaDeTrabalhos = trabalho;
	Maquina* MaquinaAux = (Maquina*)malloc(sizeof(Maquina));

	while (listaDeTrabalhos != NULL) {

		if (listaDeTrabalhos->idJob == idJob) {
			printf("*****************************************\n");
			printf("*      Nome do Trabalho: %s      *\n", listaDeTrabalhos->nomeJob);
			printf("*****************************************\n\n");
			Operacao* listaDeOperacoes = listaDeTrabalhos->operacoes;

			while (listaDeOperacoes != NULL)
			{
				printf("ID: %d     Nome Opera��o: %s\n", listaDeOperacoes->idOp, listaDeOperacoes->nome);
				OperacaoMaquina* opMaqAux = listaDeOperacoes->maquinas;
				printf("----------------------------------------------------------------------------------------\n");

				MaquinaAux = NULL;

				while (opMaqAux != NULL) {

					Maquina* maqAux = maquina;

					while (maqAux != NULL) {
						if (maqAux->idMaq == opMaqAux->idMaq) {
							if (MaquinaAux != NULL && MaquinaAux->tempoOp < maqAux->tempoOp) {
								MaquinaAux = maqAux;
							}
							else if (MaquinaAux == NULL) {
								MaquinaAux = maqAux;
							}
							printf("\tID: %d   Nome M�quina: %s     Tempo M�quina: %.2f     Localiza��o: %s\n", maqAux->idMaq, maqAux->nomeMaquina, maqAux->tempoOp, maqAux->localizacao);
						}
						maqAux = maqAux->seguinte;
					}
					opMaqAux = opMaqAux->seguinte;

				}
				if (MaquinaAux != NULL) {
					PiorTempoTotalJob += MaquinaAux->tempoOp;
				}
				printf("----------------------------------------------------------------------------------------\n\n");
				listaDeOperacoes = listaDeOperacoes->seguinte;
			}

			printf("*********************************************************************************\n");
			printf("     O M�ximo Tempo para Realizar este Trabalho �: %.2f Unidades de Tempo\n", PiorTempoTotalJob);
			printf("*********************************************************************************\n");

		}
		listaDeTrabalhos = listaDeTrabalhos->seguinte;
	}
}

//Fun��o para Calcular o Valor M�dio por Opera��o para Completar um Job
void mediaTempo(Job* trabalho, int idJob, Maquina* maquina) {
	float mediaTempo = 0;
	int countMaq = 0;
	Job* listaDeTrabalhos = trabalho;
	Maquina* MaquinaAux = (Maquina*)malloc(sizeof(Maquina));

	while (listaDeTrabalhos != NULL) {

		if (listaDeTrabalhos->idJob == idJob) {
			printf("*****************************************\n");
			printf("*      Nome do Trabalho: %s      *\n", listaDeTrabalhos->nomeJob);
			printf("*****************************************\n\n");
			Operacao* listaDeOperacoes = listaDeTrabalhos->operacoes;

			while (listaDeOperacoes != NULL)
			{
				printf("ID: %d     Nome Opera��o: %s\n", listaDeOperacoes->idOp, listaDeOperacoes->nome);
				OperacaoMaquina* opMaqAux = listaDeOperacoes->maquinas;
				printf("----------------------------------------------------------------------------------------\n");

				MaquinaAux = NULL;
				mediaTempo = 0;
				countMaq = 0;

				while (opMaqAux != NULL) {

					Maquina* maqAux = maquina;

					while (maqAux != NULL) {
						if (maqAux->idMaq == opMaqAux->idMaq) {
							mediaTempo = mediaTempo + maqAux->tempoOp;
							countMaq++;
							printf("\tID: %d   Nome M�quina: %s     Tempo M�quina: %.2f     Localiza��o: %s\n", maqAux->idMaq, maqAux->nomeMaquina, maqAux->tempoOp, maqAux->localizacao);
						}
						maqAux = maqAux->seguinte;
					}
					opMaqAux = opMaqAux->seguinte;

				}
				if (countMaq > 0) {
					mediaTempo = mediaTempo / countMaq;
					printf("\n**************************************************************\n");
					printf("     O Tempo M�dio por Opera��o �: %.2f Unidades de Tempo\n", mediaTempo);
					printf("**************************************************************\n\n");

				}
				else {
					printf("Sem M�quinas Associadas a Opera��o\n");
					printf("----------------------------------------------------------------------------------------\n");
				}


				listaDeOperacoes = listaDeOperacoes->seguinte;
			}
		}
		listaDeTrabalhos = listaDeTrabalhos->seguinte;
	}
}

//Fun��o Para Exportar todos os Dados de um Job
void exportarJob(Job* trabalho, Maquina* maquina) {

	remove("JobExported.txt");

	FILE* exportFile = fopen("JobExported.txt", "a");

	Job* jobAux = trabalho;

	fprintf(exportFile, "*************************************************************************************************\n");
	fprintf(exportFile, "*                                     LISTA DE TRABALHOS                                        *\n");
	fprintf(exportFile, "*************************************************************************************************\n\n");

	while (jobAux != NULL)
	{
		fprintf(exportFile, "ID JOB: %d   Nome Trabalho: %s\n", jobAux->idJob, jobAux->nomeJob);
		Operacao* opAux = jobAux->operacoes;
		fprintf(exportFile, "----------------------------------------------------------------------------------------\n");
		while (opAux != NULL) {
			fprintf(exportFile, "\tID: %d     Nome Opera��o: %s\n", opAux->idOp, opAux->nome);

			OperacaoMaquina* maqAux = opAux->maquinas;
			fprintf(exportFile, "----------------------------------------------------------------------------------------\n");
			while (maqAux != NULL)
			{
				Maquina* maquinaAux = maquina;
				while (maquinaAux != NULL && maquinaAux->idMaq != maqAux->idMaq)
					maquinaAux = maquinaAux->seguinte;

				if (maquinaAux != NULL)
					fprintf(exportFile, "\t\tID: %d   Nome M�quina: %s     Tempo M�quina: %.2f     Localiza��o: %s\n", maquinaAux->idMaq, maquinaAux->nomeMaquina, maquinaAux->tempoOp, maquinaAux->localizacao);

				maqAux = maqAux->seguinte;
			}
			fprintf(exportFile, "----------------------------------------------------------------------------------------\n");

			opAux = opAux->seguinte;
		}
		jobAux = jobAux->seguinte;
	}
	fprintf(exportFile, "\n************************************************************************************************\n");

	fclose(exportFile);

	printf("****************************************************************\n");
	printf("*                 TRABALHO EXPORTADO COM SUCESSO               *\n");
	printf("****************************************************************\n");
}