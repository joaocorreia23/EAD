#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
// Include da Página Header para o Gui
#include "gui.h";

#define MAXNOME 40

//Funções para AutoIncrementar os ID's por uma File
int autoIdJob() {
	int idJob;
	FILE* idFile = fopen("idJob.txt", "r");
	if (!idFile) {
		idFile = fopen("idJob.txt", "w");
		if (!idFile) return -1; // Erro
		fprintf(idFile, "%d", 1);
		fclose(idFile);
		return 1;
	}
	fscanf(idFile, "%d", &idJob); // Lê o ID e Incrementa 1 Valor
	idJob++;

	fclose(idFile); // Fecha a File
	idFile = fopen("idJob.txt", "w"); // Reabre a File
	fprintf(idFile, "%d", idJob);
	fclose(idFile);
	return idJob;
}

int autoIdOp() {
	int idOp;
	FILE* idFile = fopen("idOp.txt", "r");
	if (!idFile) {
		idFile = fopen("idOp.txt", "w");
		if (!idFile) return -1; // Erro
		fprintf(idFile, "%d", 1);
		fclose(idFile);
		return 1;
	}
	fscanf(idFile, "%d", &idOp); // Lê o ID e Incrementa 1 Valor
	idOp++;

	fclose(idFile); // Fecha a File
	idFile = fopen("idOp.txt", "w"); // Reabre a File
	fprintf(idFile, "%d", idOp);
	fclose(idFile);
	return idOp;
}

int autoIdMaq() {
	int idMaq;
	FILE* idFile = fopen("idMaq.txt", "r");
	if (!idFile) {
		idFile = fopen("idMaq.txt", "w");
		if (!idFile) return -1; // Erro
		fprintf(idFile, "%d", 1);
		fclose(idFile);
		return 1;
	}
	fscanf(idFile, "%d", &idMaq); // Lê o ID e Incrementa 1 Valor
	idMaq++;

	fclose(idFile); // Fecha a File
	idFile = fopen("idMaq.txt", "w"); // Reabre a File
	fprintf(idFile, "%d", idMaq);
	fclose(idFile);
	return idMaq;
}


main() {
	// Variáveis para Escolha da Opção dos Menus e SubMenus
	int option;
	int subOption;

	// Definição de Locale como LC_ALL para UTF-8 
	// Permite assim caracteres especiais na Consola de Debug
	char* locale;
	locale = setlocale(LC_ALL, "");

	// Inserção de Máquinas Predefinidas
	Maquina* maq = NULL;
	maq = inserirMaquina(maq, 1, "Maquina1", 3, "Piso1");
	maq = inserirMaquina(maq, 2, "Maquina2", 7, "Piso1");
	maq = inserirMaquina(maq, 3, "Maquina3", 5, "Piso1");

	// Inserção de Operações Predefinidas
	Operacao* op = NULL;
	op = inserirOperacao(op, 1, "1");
	op = inserirOperacao(op, 2, "2");
	op = inserirOperacao(op, 3, "3");

	// Associação de Operações a Máquinas Predefinidas
	op = associarMaquina(op, 1, 1);
	op = associarMaquina(op, 1, 2);
	op = associarMaquina(op, 2, 2);
	op = associarMaquina(op, 2, 3);
	op = associarMaquina(op, 3, 2);

	// Inserção de Jobs Predefinidos
	Job* job = NULL;
	job = inserirJob(job, 1, "Trabalho1", op);

	do
	{
		mostraMenu();

		scanf("%d", &option);

		system("cls");

		switch (option)
		{

			// MENU MÁQUINA
		case 1:
			do
			{
				mostraMaquinasMenu();

				scanf("%d", &subOption);
				system("cls");

				switch (subOption)
				{

				case 1:
					listarMaquinas(maq);
					system("pause");
					break;

				case 2:
					maq = criaMaquina(maq);
					system("pause");
					break;

				case 0:
					subOption = 0;
					break;

				default:
					printf("Opção Inválida\n\n");
					system("pause");
					break;
				}

				system("cls");
			} while (subOption != 0);
			break;

			// MENU OPERAÇÕES
		case 2:
			do
			{
				mostraOperacoesMenu();

				scanf("%d", &subOption);
				system("cls");

				switch (subOption)
				{
				case 1:
					listarOperacoes(op, maq);
					system("pause");
					break;

				case 2:
					op = criaOperacao(op);
					system("pause");
					break;

				case 3:
					op = removeOperacao(op);
					system("pause");
					break;

				case 4:
					op = editaOperacao(op);
					system("pause");
					break;

				case 5:
					op = associaMaquina(op, maq);
					system("pause");
					break;

				case 6:
					op = desassociaMaquina(op, maq);
					system("pause");
					break;

				case 0:
					subOption = 0;
					break;

				default:
					printf("Opção Inválida\n\n");
					system("pause");
					break;
				}

				system("cls");
			} while (subOption != 0);
			break;

			// MENU TRABALHOS
		case 3:
			do
			{
				mostraTrabalhosMenu();

				scanf("%d", &subOption);
				system("cls");

				switch (subOption)
				{
				case 1:
					listarJobs(job, maq);
					system("pause");
					break;
				case 2:
					minimoTempo(job, 1, maq);
					system("pause");
					break;
				case 3:
					maximoTempo(job, 1, maq);
					system("pause");
					break;
				case 4:
					mediaTempo(job, 1, maq);
					system("pause");
					break;
				case 5:
					exportarJob(job, maq);
					system("pause");
					break;

				case 0:
					subOption = 0;
					break;

				default:
					printf("Opção Inválida\n\n");
					system("pause");
					break;
				}

				system("cls");
			} while (subOption != 0);
			break;

		case 0:
			close();
			break;

		default:
			printf("Opção Inválida\n\n");
			system("pause");
			break;

		}

		system("cls");
	} while (option != 0);

}
