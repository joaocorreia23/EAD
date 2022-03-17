#include <string.h>
#include <stdlib.h>
#include "operacoes.h"

// Fun��o para Listar todas as Opera��es
void listarOperacoes(Operacao* operacao)
{
	printf("********************************************\n");
	printf("*            LISTA DE OPERA��ES            *\n");
	printf("********************************************\n\n");
	while (operacao != NULL)
	{
		printf("Nome Opera��o: %s     Tempo Opera��o: %.2f\n", operacao->nome, operacao->tempo);
		operacao = operacao->seguinte;
	}
	printf("\n********************************************\n");
}

// Fun��o para Criar um Novo Registo de uma Nova Opera��o
Operacao* inserirOperacao(Operacao* operacao, char nome[], float tempo) {
	Operacao* nova = (Operacao*)malloc(sizeof(Operacao));

	if (nova != NULL) {
		strcpy(nova->nome, nome);
		nova->tempo = tempo;
		nova->seguinte = operacao;
		return(nova);
	}
	else {
		return(operacao);
	}
}

// Fun��o para Alterar uma Opera��o
Operacao* alterarOperacao(Operacao* operacao, char nome[], char nomeNovo[], float tempo) {
	Operacao* nodoAtual = operacao;
	Operacao* nodoAnterior;

	while (nodoAtual != NULL && strcmp(nodoAtual->nome, nome) != 0)
	{
		nodoAnterior = nodoAtual;
		nodoAtual = nodoAtual->seguinte;
	}

	if (nodoAtual != NULL)
	{
		strcpy(nodoAtual->nome, nomeNovo);
		nodoAtual->tempo = tempo;
	}

	return(operacao);
}

// Fun��o para Remover um Registo de uma Opera��o pelo Nome
Operacao* removerOperacao(Operacao* operacao, char nome[]) {
	//Declara��o dos nodo's para armazenar a informa��o das opera��es
	Operacao* nodoAtual = operacao;
	Operacao* nodoAnterior;

	if (strcmp(nodoAtual->nome, nome) == 0)
	{
		operacao = nodoAtual->seguinte;
		free(nodoAtual);
	}
	else {
		nodoAnterior = operacao; // Armazena a informa��o da opera��o 
		nodoAtual = nodoAnterior->seguinte; // Segue para a proxima opera��o 
		while ((nodoAtual != NULL) && (strcmp(nodoAtual->nome, nome) != 0))
		{
			nodoAnterior = nodoAtual;
			nodoAtual = nodoAtual->seguinte;
		}
		if (nodoAtual != NULL)
		{
			nodoAnterior->seguinte = nodoAtual->seguinte;
			free(nodoAtual);
		}
	}
	return(operacao);
}

float minimo(Operacao* operacao)
{
	float min = 0;

	return 0.0f;
}

float media(Operacao* operacao)
{
	return 0.0f;
}
