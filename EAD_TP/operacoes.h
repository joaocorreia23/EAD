//Página header do operacoes.h
#include <stdio.h>

#define MAXNOME 40

typedef struct operacao {
	char nome[MAXNOME];
	float tempo; //Unidades de Tempo para Realizar a Operação
	struct Operacao* seguinte;
} Operacao;

void listarOperacoes(Operacao* operacao);
Operacao* inserirOperacao(Operacao* operacao, char nome[], float tempo);
Operacao* removerOperacao(Operacao* operacao, char nome[]);
Operacao* alterarOperacao(Operacao* operacao, char nome[], char nomeNovo[], float tempo);
float minimo(Operacao* operacao);
float media(Operacao* operacao);