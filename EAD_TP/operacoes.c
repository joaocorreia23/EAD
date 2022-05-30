#include <string.h>
#include <stdlib.h>
#include "operacoes.h"

// Fun��o para Listar todas as Opera��es e M�quinas
void listarOperacoes(Operacao* operacao, Maquina* maquina)
{
	printf("***************************************************************************************************\n");
	printf("*                                      LISTA DE OPERA��ES                                         *\n");
	printf("***************************************************************************************************\n\n");
	while (operacao != NULL)
	{
		printf("ID: %d     Nome Opera��o: %s\n", operacao->idOp, operacao->nome);
		OperacaoMaquina* opMaqAux = operacao->maquinas;
		printf("----------------------------------------------------------------------------------------\n");
		if (opMaqAux == NULL) {
			printf("\tN�o tem M�quinas Associadas\n");
		}
		else {
			while (opMaqAux != NULL)
			{
				Maquina* maqAux = maquina;
				while (maqAux != NULL && maqAux->idMaq != opMaqAux->idMaq)
					maqAux = maqAux->seguinte;

				if (maqAux != NULL)
					printf("\tID: %d   Nome M�quina: %s     Tempo M�quina: %.2f     Localiza��o: %s\n", maqAux->idMaq, maqAux->nomeMaquina, maqAux->tempoOp, maqAux->localizacao);

				opMaqAux = opMaqAux->seguinte;
			}
		}
		printf("----------------------------------------------------------------------------------------\n");
		operacao = operacao->seguinte;
	}
	printf("\n***************************************************************************************************\n");
}

// Fun��o para Listar todas as Opera��es Apenas
void listarApenasOperacoes(Operacao* operacao) {
	printf("********************************************\n");
	printf("*            LISTA DE OPERA��ES            *\n");
	printf("********************************************\n\n");
	while (operacao != NULL)
	{
		printf("ID: %d     Nome Opera��o: %s\n", operacao->idOp, operacao->nome);
		OperacaoMaquina* opMaqAux = operacao->maquinas;
		printf("-------------------------------------------\n");
		operacao = operacao->seguinte;
	}
	printf("\n********************************************\n");
}

// Fun��o para Criar um Novo Registo de uma Nova Opera��o
Operacao* inserirOperacao(Operacao* operacao, int idJob, int idOp, char nome[]) {
	Operacao* nova = (Operacao*)malloc(sizeof(Operacao));

	if (nova != NULL) {
		Operacao* opAux = operacao;
		Operacao* opAux2 = operacao;
		while (opAux != NULL) {
			opAux2 = opAux;
			opAux = opAux->seguinte;
		}
		nova->idJob = idJob;
		nova->idOp = idOp;
		strcpy(nova->nome, nome);
		nova->maquinas = NULL;
		nova->seguinte = NULL;
		if (opAux2 != NULL) {
			opAux2->seguinte = nova;
			return (operacao);
		}
		else {
			return (nova);
		}
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

// Fun��o para Associar um Maquina a uma Opera��o
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

// Fun��o para Dessassociar um Maquina a uma Opera��o
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

		if (nodoAtualOperacaoMaquina->idMaq == idMaq) {
			nodoAtualOperacao->maquinas = nodoAtualOperacaoMaquina->seguinte;
			free(nodoAtualOperacaoMaquina);
		}
		else {
			nodoAnteriorOperacaoMaquina = nodoAtualOperacao->maquinas; // Armazena a informa��o da opera��o 
			nodoAtualOperacaoMaquina = nodoAnteriorOperacaoMaquina->seguinte; // Segue para a proxima opera��o 
			while ((nodoAtualOperacaoMaquina != NULL) && (nodoAtualOperacaoMaquina->idMaq != idMaq)) {
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
