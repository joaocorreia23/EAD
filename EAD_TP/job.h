//Página header do job.h
#include <stdio.h>
#include "operacoes.h"

#define MAXNOME 40

// Definir as Estruturas de Dados para os Jobs (Trabalhos)

typedef struct job {
	int idJob;
	char nomeJob[MAXNOME];
	struct joboperation* operacoes;
	struct job* seguinte;
} Job;

typedef struct joboperation {
	int idJob;
	int idOp;
	struct joboperation* seguinte;
} JobOperation;

// Declaração das Funções para os Jobs (Trabalhos)

void listarJobs(Job* trabalho, Maquina* maquina, Operacao* operacao);
void listarApenasJobs(Job* trabalho);
Job* inserirJob(Job* trabalho, int idJob, char nomeJob[]);
Job* removerJob(Job* trabalho, int idJob);
void minimoTempo(Job* trabalho, int idJob, Maquina* maquina);
void maximoTempo(Job* trabalho, int idJob, Maquina* maquina);
void mediaTempo(Job* trabalho, int idJob, Maquina* maquina);
void exportarJob(Job* trabalho, Maquina* maquina);
Job* associarOperacao(Job* trabalho, int idJob, int idOp);
Job* desassociarOperacao(Job* trabalho, int idJob, int idOp);