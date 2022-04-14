//P�gina header do job.h
#include <stdio.h>
#include "operacoes.h"

#define MAXNOME 40

typedef struct job {
	int idJob;
	char nomeJob[MAXNOME];
	struct operacao* operacoes;
	struct job* seguinte;
} Job;

void listarJobs(Job* trabalho, Maquina* maquina);
Job* inserirJob(Job* trabalho, int idJob, char nomeJob[], Operacao* operacoes);
void minimoTempo(Job* trabalho, int idJob, Maquina* maquina);
void maximoTempo(Job* trabalho, int idJob, Maquina* maquina);
void mediaTempo(Job* trabalho, int idJob, Maquina* maquina);
void exportarJob(Job* trabalho, Maquina* maquina);