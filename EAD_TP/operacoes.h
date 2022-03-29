//Página header do operacoes.h
#include <stdio.h>
#include "maquinas.h"

#define MAXNOME 40

typedef struct operacao {
	int idOp;
	char nome[MAXNOME];
	struct Maquina* maquinas;
	struct Operacao* seguinte;
} Operacao;

void listarOperacoes(Operacao* operacao);
Operacao* inserirOperacao(Operacao* operacao, int idOp, char nome[], Maquina* maquinas);
Operacao* removerOperacao(Operacao* operacao, int idOp);
Operacao* alterarOperacao(Operacao* operacao, int idOp, char nomeNovo[]);