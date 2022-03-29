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
		printf("ID: %d     Nome Opera��o: %s\n", operacao->idOp, operacao->nome);
		Maquina* maqAux = operacao->maquinas;
		printf("----------------------------------------------------------------------------------------\n");
		while (maqAux != NULL) {
			printf("\tID: %d   Nome M�quina: %s     Tempo M�quina: %.2f     Localiza��o: %s\n", maqAux->idMaq, maqAux->nomeMaquina, maqAux->tempoOp, maqAux->localizacao);
			maqAux = maqAux->seguinte;
		}
		printf("----------------------------------------------------------------------------------------\n");
		operacao = operacao->seguinte;
	}
	printf("\n********************************************\n");
}

// Fun��o para Criar um Novo Registo de uma Nova Opera��o
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

// Fun��o para Alterar uma Opera��o
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

// Fun��o para Remover um Registo de uma Opera��o pelo ID
Operacao* removerOperacao(Operacao* operacao, int idOp) {
	//Declara��o dos nodo's para armazenar a informa��o das opera��es
	Operacao* nodoAtual = operacao;
	Operacao* nodoAnterior;

	if (nodoAtual->idOp == idOp) {
		operacao = nodoAtual->seguinte;
		free(nodoAtual);
	}
	else {
		nodoAnterior = operacao; // Armazena a informa��o da opera��o 
		nodoAtual = nodoAnterior->seguinte; // Segue para a proxima opera��o 
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
