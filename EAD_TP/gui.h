// Página header do gui.h
#include <stdio.h>
#include "job.h"

#pragma region MENUS

void mostraMenu();
void mostraMaquinasMenu();
void mostraOperacoesMenu();
void mostraTrabalhosMenu();
void close();

#pragma endregion

#pragma region OPERAÇÕES

Operacao* criaOperacao(Operacao* operacao, Job* trabalho);
Operacao* removeOperacao(Operacao* operacao);
Operacao* editaOperacao(Operacao* operacao);
Operacao* associaMaquina(Operacao* operacao, Maquina* maquinas);
Operacao* desassociaMaquina(Operacao* operacao, Maquina* maquinas);

#pragma endregion

#pragma region MÁQUINAS

Maquina* criaMaquina(Maquina* maquina);

#pragma endregion

#pragma region TRABALHOS

Job* criaJob(Job* trabalho);
Job* removeJob(Job* trabalho);

#pragma endregion