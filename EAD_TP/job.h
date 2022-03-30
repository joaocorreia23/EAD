//Página header do job.h
#include <stdio.h>
#include "operacoes.h"

#define MAXNOME 40

typedef struct job {
	int idJob;
	char nomeJob[MAXNOME];
	struct operacao* operacoes;
	struct job* seguinte;
} Job;

void listarJobs(Job* trabalho);
Job* inserirJob(Job* trabalho, int idJob, char nomeJob[], Operacao* operacoes);