#include <stdio.h>
#include <stdlib.h>
#include "maquinas.h";


// Função para Listar todas as Máquinas
void listarMaquinas(Maquina* maquina)
{
	printf("****************************************************************************\n");
	printf("*                             LISTA DE MÁQUINAS                            *\n");
	printf("****************************************************************************\n\n");
	while (maquina != NULL)
	{
		printf("ID: %d   Nome Máquina: %s     Tempo Máquina: %.2f     Localização: %s\n", maquina->idMaq, maquina->nomeMaquina, maquina->tempoOp, maquina->localizacao);
		maquina = maquina->seguinte;
	}
	printf("\n****************************************************************************\n");
}

// Função para Criar um Novo Registo de uma Nova Máquina
Maquina* inserirMaquina(Maquina* maquina, int idMaq, char nomeMaquina[], float tempoOp, char localizacao[]) {
	Maquina* nova = (Maquina*)malloc(sizeof(Maquina));

	if (nova != NULL) {
		nova->idMaq = idMaq;
		strcpy(nova->nomeMaquina, nomeMaquina);
		nova->tempoOp = tempoOp;
		strcpy(nova->localizacao, localizacao);
		nova->seguinte = maquina;
		return(nova);
	}
	else {
		return(maquina);
	}
}