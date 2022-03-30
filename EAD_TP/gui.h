// Página header do gui.h
#include <stdio.h>
#include "job.h"

void mostraMenu();
void mostraMaquinasMenu();
void mostraOperacoesMenu();
void mostraTrabalhosMenu();

Operacao* associaMaquina(Operacao* operacao, Maquina* maquinas);
Operacao* desassociaMaquina(Operacao* operacao, Maquina* maquinas);