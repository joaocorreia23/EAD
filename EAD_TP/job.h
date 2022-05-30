//P�gina header do job.h
#include <stdio.h>
#include "operacoes.h"

#define MAXNOME 40

// Definir as Estruturas de Dados para os Jobs (Trabalhos)

typedef struct job {
	int idJob;
	char nomeJob[MAXNOME];
	struct operacao* operacoes;
	struct job* seguinte;
} Job;

typedef struct jobOperation{
	int idJob;
	int idOp;
	struct jobOperation* seguinte;
} jobOperation;

// Declara��o das Fun��es para os Jobs (Trabalhos)

void listarJobs(Job* trabalho, Maquina* maquina);
void listarApenasJobs(Job* trabalho);
Job* inserirJob(Job* trabalho, int idJob, char nomeJob[], Operacao* operacoes);
Job* removerJob(Job* trabalho, int idJob);
void minimoTempo(Job* trabalho, int idJob, Maquina* maquina);
void maximoTempo(Job* trabalho, int idJob, Maquina* maquina);
void mediaTempo(Job* trabalho, int idJob, Maquina* maquina);
void exportarJob(Job* trabalho, Maquina* maquina);