//Página header das Operações
#include <stdio.h>
#include "maquinas.h"

#define MAXNOME 40

// Definir as Estruturas de Dados para as Operações

typedef struct operacao {
	int idJob;
	int idOp;
	char nome[MAXNOME];
	struct operacaomaquina* maquinas;
	struct operacao* seguinte;
} Operacao;

typedef struct operacaomaquina {
	int idOp;
	int idMaq;
	struct operacaomaquina* seguinte;
} OperacaoMaquina;

// Declaração das Funções para as Operações

void listarOperacoes(Operacao* operacao, Maquina* maquina);
void listarApenasOperacoes(Operacao* operacao);
Operacao* inserirOperacao(Operacao* operacao, int idOp, char nome[]);
Operacao* removerOperacao(Operacao* operacao, int idOp);
Operacao* alterarOperacao(Operacao* operacao, int idOp, char nomeNovo[]);
Operacao* associarMaquina(Operacao* operacao, int idOp, int idMaq);
Operacao* desassociarMaquina(Operacao* operacao, int idOp, int idMaq);