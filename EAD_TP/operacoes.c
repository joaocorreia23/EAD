#include <string.h>
#include <stdlib.h>
#include "operacoes.h"

// Função para Listar todas as Operações
void listarOperacoes(Operacao* operacao, Maquina* maquina)
{
	printf("********************************************\n");
	printf("*            LISTA DE OPERAÇÕES            *\n");
	printf("********************************************\n\n");
	while (operacao != NULL)
	{
		printf("ID: %d     Nome Operação: %s\n", operacao->idOp, operacao->nome);
		OperacaoMaquina* opMaqAux = operacao->maquinas;
		printf("----------------------------------------------------------------------------------------\n");
		while (opMaqAux != NULL)
		{
			Maquina* maqAux = maquina;
			while (maqAux != NULL && maqAux->idMaq != opMaqAux->idMaq)
				maqAux = maqAux->seguinte;

			if (maqAux != NULL)
				printf("\tID: %d   Nome Máquina: %s     Tempo Máquina: %.2f     Localização: %s\n", maqAux->idMaq, maqAux->nomeMaquina, maqAux->tempoOp, maqAux->localizacao);


			opMaqAux = opMaqAux->seguinte;
		}
		/*	while (maqAux != NULL) {
				printf("\tID: %d   Nome Máquina: %s     Tempo Máquina: %.2f     Localização: %s\n", maqAux->idMaq, maqAux->nomeMaquina, maqAux->tempoOp, maqAux->localizacao);
				maqAux = maqAux->seguinte;
			}*/
		printf("----------------------------------------------------------------------------------------\n");
		operacao = operacao->seguinte;
	}
	printf("\n********************************************\n");
}

// Função para Criar um Novo Registo de uma Nova Operação
Operacao* inserirOperacao(Operacao* operacao, int idOp, char nome[]) {
	Operacao* nova = (Operacao*)malloc(sizeof(Operacao));

	if (nova != NULL) {
		nova->idOp = idOp;
		strcpy(nova->nome, nome);
		nova->maquinas = NULL;
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


Operacao* associarMaquina(Operacao* operacao, int idOp, int idMaq) {
	Operacao* nodoAtualOperacao = operacao;
	Operacao* nodoAnteriorOperacao;

	while (nodoAtualOperacao != NULL && nodoAtualOperacao->idOp != idOp)
	{
		nodoAnteriorOperacao = nodoAtualOperacao;
		nodoAtualOperacao = nodoAtualOperacao->seguinte;
	}

	if (nodoAtualOperacao != NULL)
	{
		OperacaoMaquina* nova = (OperacaoMaquina*)malloc(sizeof(OperacaoMaquina));
		nova->idMaq = idMaq;
		nova->idOp = idOp;
		nova->seguinte = nodoAtualOperacao->maquinas;

		nodoAtualOperacao->maquinas = nova;
	}

	return operacao;
}

Operacao* desassociarMaquina(Operacao* operacao, int idOp, int idMaq) {
	Operacao* nodoAtualOperacao = operacao;
	Operacao* nodoAnteriorOperacao;

	while (nodoAtualOperacao != NULL && nodoAtualOperacao->idOp != idOp)
	{
		nodoAnteriorOperacao = nodoAtualOperacao;
		nodoAtualOperacao = nodoAtualOperacao->seguinte;
	}

	if (nodoAtualOperacao != NULL)
	{
		OperacaoMaquina* nodoAtualOperacaoMaquina = nodoAtualOperacao->maquinas;
		OperacaoMaquina* nodoAnteriorOperacaoMaquina;

		if (nodoAtualOperacaoMaquina->idOp == idOp) {
			nodoAtualOperacao->maquinas = nodoAtualOperacaoMaquina->seguinte;
			free(nodoAtualOperacaoMaquina);
		}
		else {
			nodoAnteriorOperacaoMaquina = operacao; // Armazena a informação da operação 
			nodoAtualOperacaoMaquina = nodoAnteriorOperacaoMaquina->seguinte; // Segue para a proxima operação 
			while ((nodoAtualOperacaoMaquina != NULL) && (nodoAtualOperacaoMaquina->idOp != idOp)) {
				nodoAnteriorOperacaoMaquina = nodoAtualOperacaoMaquina;
				nodoAtualOperacaoMaquina = nodoAtualOperacaoMaquina->seguinte;
			}
			if (nodoAtualOperacaoMaquina != NULL)
			{
				nodoAnteriorOperacaoMaquina->seguinte = nodoAtualOperacaoMaquina->seguinte;
				free(nodoAtualOperacaoMaquina);
			}
		}
	}

	return operacao;
}