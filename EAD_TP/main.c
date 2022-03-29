#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
// Include da Página Header para o Job
#include "job.h"

#define MAXNOME [40];

mostraMenu() {
	printf("*******************************************\n");
	printf("*                   MENU                  *\n");
	printf("*******************************************\n\n");

	printf("1. Listar Operações \n");
	printf("2. Inserir Nova Operação \n");
	printf("3. Remover Operação \n");
	printf("4. Alterar Operação \n");
	printf("5. Quantidade Minima de Tempo \n");
	printf("6. Quantidade Máxima de Tempo \n");
	printf("7. Quantidade Média de Tempo \n");
	printf("8. Listar Máquinas \n");
	printf("9. Listar Trabalhos \n");
	printf("10. Criar Máquina \n");
	printf("0. Sair! \n\n");

	printf("*******************************************\n\n");
}

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
	char name MAXNOME;
	float tempo;
	int idOp = 0;
	Maquina *maquinas = NULL;

	idOp = autoIdOp(idOp);

	printf("Nome da Operação: ");
	scanf("%s", &name);

	return inserirOperacao(operacao, idOp, name, maquinas);
}

Operacao* removeOperacao(Operacao* operacao) {
	int idOp = 0;

	printf("ID da Operação: ");
	scanf("%d", &idOp);


	return removerOperacao(operacao, idOp);
}

Operacao* editaOperacao(Operacao* operacao) {
	char newName MAXNOME;
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
	char name MAXNOME;
	float tempoOp;
	char localizacao MAXNOME;
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

	char* locale;
	locale = setlocale(LC_ALL, "");

	Job* job = NULL;
	//job = inserirJob(job, "Trabalho1", "01");

	Maquina* maq = NULL;
	maq = inserirMaquina(maq, 1, "Máquina1", 3, "Piso1");
	maq = inserirMaquina(maq, 2, "Máquina1", 7, "Piso1");
	maq = inserirMaquina(maq, 3, "Máquina1", 5, "Piso1");

	Operacao* op = NULL;
	op = inserirOperacao(op, 1, "00", maq);
	op = inserirOperacao(op, 2, "01", maq);
	op = inserirOperacao(op, 3, "02", maq);


	do
	{
		mostraMenu();

		printf("Opção: ");
		scanf("%d", &option);

		system("cls");

		switch (option)
		{
		case 1:
			listarOperacoes(op);
			system("pause");
			break;

		case 2:
			op = criaOperacao(op);
			break;

		case 3:
			listarOperacoes(op);
			op = removeOperacao(op);
			break;

		case 4:
			listarOperacoes(op);
			op = editaOperacao(op);
			break;

		case 5:
			break;

		case 6:
			break;

		case 7:
			break;

		case 8:
			listarMaquinas(maq);
			system("pause");
			break;

		case 9:
			listarJobs(job);
			system("pause");
			break;

		case 10:
			maq = criaMaquina(maq);
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
