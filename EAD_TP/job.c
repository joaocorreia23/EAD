#include <string.h>
#include <stdlib.h>
#include "job.h"

// Fun��o para Listar todos os Jobs
void listarJobs(Job* trabalho, Maquina* maquina) {

	Job* jobAux = trabalho;

	printf("***************************************************************************\n");
	printf("*                            LISTA DE TRABALHOS                           *\n");
	printf("***************************************************************************\n\n");

	while (jobAux != NULL)
	{
		printf("ID JOB: %d   Nome Trabalho: %s\n", jobAux->idJob, jobAux->nomeJob);
		Operacao* opAux = jobAux->operacoes;
		printf("----------------------------------------------------------------------------------------\n");
		while (opAux != NULL) {
			printf("\tID: %d     Nome Opera��o: %s\n", opAux->idOp, opAux->nome);

			OperacaoMaquina* maqAux = opAux->maquinas;
			printf("----------------------------------------------------------------------------------------\n");
			while (maqAux != NULL)
			{
				Maquina* maquinaAux = maquina;
				while (maquinaAux != NULL && maquinaAux->idMaq != maqAux->idMaq)
					maquinaAux = maquinaAux->seguinte;

				if (maquinaAux != NULL)
					printf("\t\tID: %d   Nome M�quina: %s     Tempo M�quina: %.2f     Localiza��o: %s\n", maquinaAux->idMaq, maquinaAux->nomeMaquina, maquinaAux->tempoOp, maquinaAux->localizacao);

				maqAux = maqAux->seguinte;
			}
			printf("----------------------------------------------------------------------------------------\n");

			opAux = opAux->seguinte;
		}
		printf("----------------------------------------------------------------------------------------\n");
		jobAux = jobAux->seguinte;
	}
	printf("\n***************************************************************************\n");
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

//Fun��o para Calcular o Valor M�nimo para Completar um Job
void minimoTempo(Job* trabalho, int idJob, Maquina* maquina) {

	float MelhorTempoTotalJob = 0;
	Job* listaDeTrabalhos = trabalho;
	Maquina* MaquinaAux = (Maquina*)malloc(sizeof(Maquina));

	while (listaDeTrabalhos != NULL) {

		if (listaDeTrabalhos->idJob == idJob) {

			printf("\tNome do Trabalho: %s\n", listaDeTrabalhos->nomeJob);
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
				printf("----------------------------------------------------------------------------------------\n");
				listaDeOperacoes = listaDeOperacoes->seguinte;
			}

			printf("||========================================================||\n");
			printf("||O MELHOR TEMPO DE EXECU��O DO TRABALHO �: %.2f\n", MelhorTempoTotalJob);
			printf("||========================================================||\n");
		}
		listaDeTrabalhos = listaDeTrabalhos->seguinte;
	}
	//Job* auxListaJobs = trabalho;
	//Operacao* auxOperacoes;
	//Maquina* auxMaquinas;
	//Maquina* novaMaq = (Maquina*)malloc(sizeof(Maquina)); // Maquina auxiliar para imprimir a maquina

	//int tempoMinimo = 0;
	//int resultado = 0;

	//while (auxListaJobs != NULL)
	//{
	//    if (auxListaJobs->idJob == idJob) {

	//        auxOperacoes = auxListaJobs->operacoes;

	//        while (auxOperacoes != NULL) { // Percorrer a lista de opera��es

	//            tempoMinimo = 0;
	//            novaMaq = NULL; // Maquina inicializa-se a NULL
	//            auxMaquinas = auxOperacoes->maquinas;

	//            while (auxMaquinas != NULL) {

	//                novaMaq = auxMaquinas;

	//                if (auxMaquinas->tempoOp < tempoMinimo) {
	//                    novaMaq->nomeMaquina = auxMaquinas->nomeMaquina; // Guardamos o nome da maquina
	//                    tempoMinimo = auxMaquinas->tempoOp; // Guardamos o tempo da maquina
	//                }
	//                else if (tempoMinimo == 0) {
	//                    novaMaq->nomeMaquina = auxMaquinas->nomeMaquina; // Guardamos o nome da maquina
	//                    tempoMinimo = auxMaquinas->tempoOp; // Guardamos o tempo da maquina
	//                }
	//                auxMaquinas = auxMaquinas->seguinte;
	//            }
	//            auxOperacoes = auxOperacoes->seguinte;

	//            resultado += tempoMinimo;
	//            printf("\nTempo minimo: %d - maq: %s\n", tempoMinimo, novaMaq->nomeMaquina);

	//        }
	//    }
	//    auxListaJobs = auxListaJobs->seguinte;
	//}

	//printf("\nResultado m�nimo: %d\n", resultado);
}

//Fun��o para Calcular o Valor M�ximo para Completar um Job
void maximoTempo(Job* trabalho, int idJob, Maquina* maquina) {
	float PiorTempoTotalJob = 0;
	Job* listaDeTrabalhos = trabalho;
	Maquina* MaquinaAux = (Maquina*)malloc(sizeof(Maquina));

	while (listaDeTrabalhos != NULL) {

		if (listaDeTrabalhos->idJob == idJob) {

			printf("\tNome do Trabalho: %s\n", listaDeTrabalhos->nomeJob);
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
				printf("----------------------------------------------------------------------------------------\n");
				listaDeOperacoes = listaDeOperacoes->seguinte;
			}

			printf("||========================================================||\n");
			printf("||O PIOR TEMPO DE EXECU��O DO TRABALHO �: %.2f\n", PiorTempoTotalJob);
			printf("||========================================================||\n");
		}
		listaDeTrabalhos = listaDeTrabalhos->seguinte;
	}
}

//Fun��o para Calcular o Valor M�dio para Completar um Job
void mediaTempo(Job* trabalho, int idJob, Maquina* maquina) {
	float mediaTempo = 0;
	int countMaq = 0;
	Job* listaDeTrabalhos = trabalho;
	Maquina* MaquinaAux = (Maquina*)malloc(sizeof(Maquina));

	while (listaDeTrabalhos != NULL) {

		if (listaDeTrabalhos->idJob == idJob) {

			printf("\tNome do Trabalho: %s\n", listaDeTrabalhos->nomeJob);
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
					printf("----------------------------------------------------------------------------------------\n");
					printf("O TEMPO M�DIO EXECU��O DA OPERA��O �: %.2f\n", mediaTempo);
					printf("----------------------------------------------------------------------------------------\n");
				}
				else {
					printf("A OPERA��O N�O TEM M�QUINAS ASSOCIADAS\n");
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