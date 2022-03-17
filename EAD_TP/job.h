//Página header do job.h
#include <stdio.h>
#include "operacoes.h"

#define MAXNOME 40

typedef struct job {
	char nome[MAXNOME];
	struct Operacao* operacoes;
	struct Job* seguinte;
} Job;