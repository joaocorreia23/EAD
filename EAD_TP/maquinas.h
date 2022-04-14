#include <stdio.h>
#include <stdlib.h>

#define MAXNOME 40

// Definir as Estruturas de Dados para as M�quinas

typedef struct maquina {
	int idMaq;
	char nomeMaquina[MAXNOME];
	float tempoOp;
	char localizacao[MAXNOME];
	struct maquina* seguinte;
} Maquina;

// Declara��o das Fun��es para as M�quinas

void listarMaquinas(Maquina* maquina);
Maquina* inserirMaquina(Maquina* maquina, int idMaq, char nomeMaquina[], float tempoOp, char localizacao[]);