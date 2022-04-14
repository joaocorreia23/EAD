#include <stdio.h>
#include <stdlib.h>

#define MAXNOME 40

// Definir as Estruturas de Dados para as Máquinas

typedef struct maquina {
	int idMaq;
	char nomeMaquina[MAXNOME];
	float tempoOp;
	char localizacao[MAXNOME];
	struct maquina* seguinte;
} Maquina;

// Declaração das Funções para as Máquinas

void listarMaquinas(Maquina* maquina);
Maquina* inserirMaquina(Maquina* maquina, int idMaq, char nomeMaquina[], float tempoOp, char localizacao[]);