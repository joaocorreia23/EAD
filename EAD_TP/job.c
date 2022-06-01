#include <string.h>
#include <stdlib.h>
#include "job.h"

//Fun��o para Listar todos os Jobs
void listarJobs(Job* trabalho, Maquina* maquina, Operacao* operacao) {

	Job* jobAux = trabalho;

	printf("*************************************************************************************************\n");
	printf("*                                     LISTA DE TRABALHOS                                        *\n");
	printf("*************************************************************************************************\n\n");


	if (trabalho != NULL) {
		while (jobAux != NULL)
		{
			printf("ID JOB: %d   Nome Trabalho: %s\n", jobAux->idJob, jobAux->nomeJob);
			JobOperation* jobOpAux = jobAux->operacoes;
			printf("------------------------------------------------------------------------------------------------\n");

			if (jobOpAux != NULL) {
				while (jobOpAux != NULL) {
					Operacao* opAux = operacao;
					while (opAux != NULL && opAux->idOp != jobOpAux->idOp)
						opAux = opAux->seguinte;

					printf("\tID: %d     Nome Opera��o: %s\n", opAux->idOp, opAux->nome);

					OperacaoMaquina* maqAux = opAux->maquinas;
					printf("------------------------------------------------------------------------------------------------\n");
					if (maqAux != NULL) {
						while (maqAux != NULL)
						{
							Maquina* maquinaAux = maquina;
							while (maquinaAux != NULL && maquinaAux->idMaq != maqAux->idMaq)
								maquinaAux = maquinaAux->seguinte;

							if (maquinaAux != NULL)
								printf("\t\tID: %d   Nome M�quina: %s     Tempo M�quina: %.2f     Localiza��o: %s\n", maquinaAux->idMaq, maquinaAux->nomeMaquina, maquinaAux->tempoOp, maquinaAux->localizacao);

							maqAux = maqAux->seguinte;
						}
					}
					else
					{
						printf("\t\tSem maquinas associadas\n");
					}
					printf("------------------------------------------------------------------------------------------------\n");

					jobOpAux = jobOpAux->seguinte;
				}
			}
			else
			{
				printf("\tSem opera��es associadas\n");
			}
			printf("=================================================================================================\n");
			printf("=================================================================================================\n\n");
			jobAux = jobAux->seguinte;
		}
	}
	else {
		printf("Sem trabalhos a apresentar");
	}

	printf("\n*************************************************************************************************\n");
}

//Fun��o para Listar Apenas os Jobs
void listarApenasJobs(Job* trabalho) {
	Job* jobAux = trabalho;
	printf("********************************************\n");
	printf("*            LISTA DE TRABALHOS            *\n");
	printf("********************************************\n\n");
	while (jobAux != NULL)
	{
		printf("ID: %d     Nome Trabalho (Job): %s\n", jobAux->idJob, jobAux->nomeJob);
		printf("-------------------------------------------\n");
		jobAux = jobAux->seguinte;
	}
	printf("\n********************************************\n");
}

//Fun��o para Adicionar Jobs
Job* inserirJob(Job* trabalho, int idJob, char nomeJob[]) {
	Job* novo = (Job*)malloc(sizeof(Job));

	if (novo != NULL) {
		novo->idJob = idJob;
		strcpy(novo->nomeJob, nomeJob);
		novo->operacoes = NULL;
		novo->seguinte = trabalho;
		return(novo);
	}
	else {
		return(trabalho);
	}
}

//Fun��o para Remover Job por ID
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
void exportarJob(Job* trabalho, Maquina* maquina, Operacao* operacao) {

	remove("JobExported.txt");

	FILE* exportFile = fopen("JobExported.txt", "a");

	Job* jobAux = trabalho;

	fprintf(exportFile, "*************************************************************************************************\n");
	fprintf(exportFile, "*                                     LISTA DE TRABALHOS                                        *\n");
	fprintf(exportFile, "*************************************************************************************************\n\n");


	if (trabalho != NULL) {
		while (jobAux != NULL)
		{
			fprintf(exportFile, "ID JOB: %d   Nome Trabalho: %s\n", jobAux->idJob, jobAux->nomeJob);
			JobOperation* jobOpAux = jobAux->operacoes;
			fprintf(exportFile, "------------------------------------------------------------------------------------------------\n");

			if (jobOpAux != NULL) {
				while (jobOpAux != NULL) {
					Operacao* opAux = operacao;
					while (opAux != NULL && opAux->idOp != jobOpAux->idOp)
						opAux = opAux->seguinte;

					fprintf(exportFile, "\tID: %d     Nome Opera��o: %s\n", opAux->idOp, opAux->nome);

					OperacaoMaquina* maqAux = opAux->maquinas;
					fprintf(exportFile, "------------------------------------------------------------------------------------------------\n");
					if (maqAux != NULL) {
						while (maqAux != NULL)
						{
							Maquina* maquinaAux = maquina;
							while (maquinaAux != NULL && maquinaAux->idMaq != maqAux->idMaq)
								maquinaAux = maquinaAux->seguinte;

							if (maquinaAux != NULL)
								fprintf(exportFile, "\t\tID: %d   Nome M�quina: %s     Tempo M�quina: %.2f     Localiza��o: %s\n", maquinaAux->idMaq, maquinaAux->nomeMaquina, maquinaAux->tempoOp, maquinaAux->localizacao);

							maqAux = maqAux->seguinte;
						}
					}
					else
					{
						fprintf(exportFile, "\t\tSem maquinas associadas\n");
					}
					fprintf(exportFile, "------------------------------------------------------------------------------------------------\n");

					jobOpAux = jobOpAux->seguinte;
				}
			}
			else
			{
				fprintf(exportFile, "\tSem opera��es associadas\n");
			}
			fprintf(exportFile, "=================================================================================================\n");
			fprintf(exportFile, "=================================================================================================\n\n");
			jobAux = jobAux->seguinte;
		}
	}
	else {
		fprintf(exportFile, "Sem trabalhos a apresentar");
	}

	fprintf(exportFile, "\n*************************************************************************************************\n");


	/*Job* jobAux = trabalho;

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
	fprintf(exportFile, "\n************************************************************************************************\n");*/

	fclose(exportFile);

	printf("****************************************************************\n");
	printf("*                 TRABALHO EXPORTADO COM SUCESSO               *\n");
	printf("****************************************************************\n");
}

//Fun��o para Associar Opera��o a um Job
Job* associarOperacao(Job* trabalho, int idOp, int idJob) {
	Job* nodoAtualTrabalho = trabalho;
	Job* nodoAnteriorTrabalho;


	while (nodoAtualTrabalho != NULL && nodoAtualTrabalho->idJob != idJob)
	{
		nodoAnteriorTrabalho = nodoAtualTrabalho;
		nodoAtualTrabalho = nodoAnteriorTrabalho->seguinte;
	}

	if (nodoAtualTrabalho != NULL)
	{
		JobOperation* nova = (JobOperation*)malloc(sizeof(JobOperation));
		nova->idOp = idOp;
		nova->idJob = idJob;
		nova->seguinte = nodoAtualTrabalho->operacoes;

		nodoAtualTrabalho->operacoes = nova;
	}

	return trabalho;
}

//Fun��o para Desassociar Opera��o a um Job
Job* desassociarOperacao(Job* trabalho, int idJob, int idOp) {
	Job* nodoAtualTrabalho = trabalho;
	Job* nodoAnteriorTrabalho;

	while (nodoAtualTrabalho != NULL && nodoAtualTrabalho->idJob != idJob)
	{
		nodoAnteriorTrabalho = nodoAtualTrabalho;
		nodoAtualTrabalho = nodoAtualTrabalho->seguinte;
	}

	if (nodoAtualTrabalho != NULL)
	{
		JobOperation* nodoAtualjobOperation = nodoAtualTrabalho->operacoes;
		JobOperation* nodoAnteriorjobOperation;

		if (nodoAtualjobOperation->idOp == idOp) {
			nodoAtualTrabalho->operacoes = nodoAtualjobOperation->seguinte;
			free(nodoAtualjobOperation);
		}
		else {
			nodoAnteriorjobOperation = nodoAtualTrabalho->operacoes; // Armazena a informa��o da opera��o 
			nodoAtualjobOperation = nodoAnteriorjobOperation->seguinte; // Segue para a proxima opera��o 
			while ((nodoAtualjobOperation != NULL) && (nodoAtualjobOperation->idOp != idOp)) {
				nodoAnteriorjobOperation = nodoAtualjobOperation;
				nodoAtualjobOperation = nodoAtualjobOperation->seguinte;
			}
			if (nodoAtualjobOperation != NULL)
			{
				nodoAnteriorjobOperation->seguinte = nodoAtualjobOperation->seguinte;
				free(nodoAtualjobOperation);
			}
		}
	}

	return trabalho;
}



