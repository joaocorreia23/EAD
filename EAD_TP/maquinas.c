#include <stdio.h>
#include <stdlib.h>
#include "maquinas.h";


// Fun��o para Listar todas as M�quinas
void listarMaquinas(Maquina* maquina)
{
	printf("****************************************************************************\n");
	printf("*                             LISTA DE M�QUINAS                            *\n");
	printf("****************************************************************************\n\n");
	while (maquina != NULL)
	{
		printf("ID: %d   Nome M�quina: %s     Tempo M�quina: %.2f     Localiza��o: %s\n", maquina->idMaq, maquina->nomeMaquina, maquina->tempoOp, maquina->localizacao);
		maquina = maquina->seguinte;
	}
	printf("\n****************************************************************************\n");
}

// Fun��o para Criar um Novo Registo de uma Nova M�quina
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