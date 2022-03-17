#include <string.h>
#include <stdlib.h>
#include "operacoes.h"

// Função para Listar todas as Operações
void listarOperacoes(Operacao* operacao)
{
	printf("********************************************\n");
	printf("*            LISTA DE OPERAÇÕES            *\n");
	printf("********************************************\n\n");
	while (operacao != NULL)
	{
		printf("Nome Operação: %s     Tempo Operação: %.2f\n", operacao->nome, operacao->tempo);
		operacao = operacao->seguinte;
	}
	printf("\n********************************************\n");
}

// Função para Criar um Novo Registo de uma Nova Operação
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

// Função para Alterar uma Operação
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

// Função para Remover um Registo de uma Operação pelo Nome
Operacao* removerOperacao(Operacao* operacao, char nome[]) {
	//Declaração dos nodo's para armazenar a informação das operações
	Operacao* nodoAtual = operacao;
	Operacao* nodoAnterior;

	if (strcmp(nodoAtual->nome, nome) == 0)
	{
		operacao = nodoAtual->seguinte;
		free(nodoAtual);
	}
	else {
		nodoAnterior = operacao; // Armazena a informação da operação 
		nodoAtual = nodoAnterior->seguinte; // Segue para a proxima operação 
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
