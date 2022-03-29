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
		printf("ID: %d     Nome Operação: %s\n", operacao->idOp, operacao->nome);
		Maquina* maqAux = operacao->maquinas;
		printf("----------------------------------------------------------------------------------------\n");
		while (maqAux != NULL) {
			printf("\tID: %d   Nome Máquina: %s     Tempo Máquina: %.2f     Localização: %s\n", maqAux->idMaq, maqAux->nomeMaquina, maqAux->tempoOp, maqAux->localizacao);
			maqAux = maqAux->seguinte;
		}
		printf("----------------------------------------------------------------------------------------\n");
		operacao = operacao->seguinte;
	}
	printf("\n********************************************\n");
}

// Função para Criar um Novo Registo de uma Nova Operação
Operacao* inserirOperacao(Operacao* operacao, int idOp, char nome[], Maquina* maquinas) {
	Operacao* nova = (Operacao*)malloc(sizeof(Operacao));

	if (nova != NULL) {
		nova->idOp = idOp;
		strcpy(nova->nome, nome);
		nova->maquinas = maquinas;
		nova->seguinte = operacao;
		return(nova);
	}
	else {
		return(operacao);
	}
}

// Função para Alterar uma Operação
Operacao* alterarOperacao(Operacao* operacao, int idOp, char nomeNovo[]) {
	Operacao* nodoAtual = operacao;
	Operacao* nodoAnterior;

	while (nodoAtual != NULL && nodoAtual->idOp != idOp)
	{
		nodoAnterior = nodoAtual;
		nodoAtual = nodoAtual->seguinte;
	}

	if (nodoAtual != NULL)
	{
		strcpy(nodoAtual->nome, nomeNovo);
	}

	return(operacao);
}

// Função para Remover um Registo de uma Operação pelo ID
Operacao* removerOperacao(Operacao* operacao, int idOp) {
	//Declaração dos nodo's para armazenar a informação das operações
	Operacao* nodoAtual = operacao;
	Operacao* nodoAnterior;

	if (nodoAtual->idOp == idOp) {
		operacao = nodoAtual->seguinte;
		free(nodoAtual);
	}
	else {
		nodoAnterior = operacao; // Armazena a informação da operação 
		nodoAtual = nodoAnterior->seguinte; // Segue para a proxima operação 
		while ((nodoAtual != NULL) && (nodoAtual->idOp != idOp)) {
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
