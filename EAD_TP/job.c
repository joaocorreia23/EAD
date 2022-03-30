#include <string.h>
#include <stdlib.h>
#include "job.h"

// Fun��o para Listar todos os Jobs
void listarJobs(Job* trabalho)
{
	printf("***************************************************************************\n");
	printf("*                            LISTA DE TRABALHOS                           *\n");
	printf("***************************************************************************\n\n");
	while (trabalho != NULL)
	{
		printf("ID JOB: %d   Nome Trabalho: %s\n", trabalho->idJob, trabalho->nomeJob);
		Operacao* opAux = trabalho->operacoes;
		printf("----------------------------------------------------------------------------------------\n");
		while (opAux != NULL) {
			printf("\tID: %d     Nome Opera��o: %s\n", opAux->idOp, opAux->nome);

			Maquina* maqAux = opAux->maquinas;
			printf("----------------------------------------------------------------------------------------\n");
			while (maqAux != NULL) {
				printf("\t\tID: %d   Nome M�quina: %s     Tempo M�quina: %.2f     Localiza��o: %s\n", maqAux->idMaq, maqAux->nomeMaquina, maqAux->tempoOp, maqAux->localizacao);
				maqAux = maqAux->seguinte;
			}
			printf("----------------------------------------------------------------------------------------\n");

			opAux = opAux->seguinte;
		}
		printf("----------------------------------------------------------------------------------------\n");
		trabalho = trabalho->seguinte;
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