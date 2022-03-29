//Página header do job.h
#include <stdio.h>
#include "operacoes.h"

#define MAXNOME 40

typedef struct job {
	int idJob;
	char nome[MAXNOME];
	struct Operacao* operacoes;
	struct Job* seguinte;
} Job;

void listarJobs(Job* job);
Job* inserirJob(Job* trabalho, char nome[], Operacao* operacoes);