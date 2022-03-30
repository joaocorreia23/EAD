#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
// Include da Página Header para o Gui
#include "gui.h";

#define MAXNOME 40

close() {
	printf("*******************************************\n");
	printf("*           Até Breve, Obrigado!          *\n");
	printf("*******************************************\n");

	exit(0);
}

//Funções para AutoIncrementar o ID por uma File
int autoIdJob() {
	int idJob;
	FILE* idFile = fopen("idJob.txt", "r");
	if (!idFile) {
		idFile = fopen("idJob.txt", "w");
		if (!idFile) return -1; // fail
		fprintf(idFile, "%d", 1);
		fclose(idFile);
		return 1;
	}
	fscanf(idFile, "%d", &idJob);
	idJob++;

	fclose(idFile); // close file for read
	idFile = fopen("idJob.txt", "w"); // reopen for write 
	fprintf(idFile, "%d", idJob);
	fclose(idFile);
	return idJob;
}

int autoIdOp() {
	int idOp;
	FILE* idFile = fopen("idOp.txt", "r");
	if (!idFile) {
		idFile = fopen("idOp.txt", "w");
		if (!idFile) return -1; // fail
		fprintf(idFile, "%d", 1);
		fclose(idFile);
		return 1;
	}
	fscanf(idFile, "%d", &idOp);
	idOp++;

	fclose(idFile); // close file for read
	idFile = fopen("idOp.txt", "w"); // reopen for write
	fprintf(idFile, "%d", idOp);
	fclose(idFile);
	return idOp;
}

int autoIdMaq() {
	int idMaq;
	FILE* idFile = fopen("idMaq.txt", "r");
	if (!idFile) {
		idFile = fopen("idMaq.txt", "w");
		if (!idFile) return -1; // fail
		fprintf(idFile, "%d", 1);
		fclose(idFile);
		return 1;
	}
	fscanf(idFile, "%d", &idMaq);
	idMaq++;

	fclose(idFile); // close file for read
	idFile = fopen("idMaq.txt", "w"); // reopen for write
	fprintf(idFile, "%d", idMaq);
	fclose(idFile);
	return idMaq;
}

//Funções para fazer o CRUD das Operações
Operacao* criaOperacao(Operacao* operacao) {
	char name[MAXNOME];
	float tempo;
	int idOp = 0;
	Maquina* maquinas = NULL;

	idOp = autoIdOp(idOp);

	printf("Nome da Operação: ");
	scanf("%s", &name);

	printf("Nome da Operação: ");

	return inserirOperacao(operacao, idOp, name, maquinas);
}

Operacao* removeOperacao(Operacao* operacao) {
	int idOp = 0;

	printf("ID da Operação: ");
	scanf("%d", &idOp);


	return removerOperacao(operacao, idOp);
}

Operacao* editaOperacao(Operacao* operacao) {
	char newName[MAXNOME];
	float tempo;

	int idOp = 0;

	printf("ID da Operação Para Editar: ");
	scanf("%d", &idOp);

	printf("Novo Nome da Operação: ");
	scanf("%s", &newName);

	return alterarOperacao(operacao, idOp, newName);
}

//Funções para fazer o CRUD das Máquinas
Maquina* criaMaquina(Maquina* maquina) {
	char name[MAXNOME];
	float tempoOp;
	char localizacao[MAXNOME];
	int idMaq = 0;

	idMaq = autoIdOp(idMaq);

	printf("Nome da Máquina: ");
	scanf("%s", &name);

	printf("Tempo da Máquina: ");
	scanf("%f", &tempoOp);

	printf("Localização da Máquina: ");
	scanf("%s", &localizacao);

	return inserirMaquina(maquina, idMaq, name, tempoOp, localizacao);
}


main() {
	int option;
	int subOption;

	char* locale;
	locale = setlocale(LC_ALL, "");

	Maquina* maq = NULL;
	maq = inserirMaquina(maq, 1, "Máquina1", 3, "Piso1");
	maq = inserirMaquina(maq, 2, "Máquina2", 7, "Piso1");
	//maq = inserirMaquina(maq, 3, "Máquina3", 5, "Piso1");

	Operacao* op = NULL;
	op = inserirOperacao(op, 1, "00");
	op = inserirOperacao(op, 2, "01");
	op = inserirOperacao(op, 3, "02");

	op = associarMaquina(op, 1, 1);
	op = associarMaquina(op, 1, 2);
	op = associarMaquina(op, 2, 2);
	op = associarMaquina(op, 3, 2);

	Job* job = NULL;
	//job = inserirJob(job, 1, "Trabalho1", op);
	//job = inserirJob(job, 2, "Trabalho2", op);
	//job = inserirJob(job, 3, "Trabalho3", op);
	//job = inserirJob(job, 10, "TrabalhoTeste", op);


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
					listarJobs(job);
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
