#include <string.h>
#include <stdlib.h>
#include "job.h"

// Função para Listar todas as Máquinas
void listarJobs(Job* trabalho)
{
	printf("***************************************************************************\n");
	printf("*                            LISTA DE TRABALHOS                           *\n");
	printf("***************************************************************************\n\n");
	while (trabalho != NULL)
	{
		printf("Nome Trabalho: %s     Operações: %s\n", trabalho->nome, trabalho->operacoes);
		trabalho = trabalho->seguinte;
	}
	printf("\n***************************************************************************\n");
}

Job* inserirJob(Job* trabalho, char nome[], Operacao* operacoes) {
	Job* novo = (Job*)malloc(sizeof(Job));

	if (novo != NULL) {
		strcpy(novo->nome, nome);
		novo->operacoes;
		return(novo);
	}
	else {
		return(trabalho);
	}
}