#include "stdio.h"
#include "stdlib.h"
#include "operations.h"
#include "time.h"

typedef struct Matice {
	int sloupce, radky;
	double data[];
} Matice;


// Naète matici od uživatele
struct Matice* readMatrix() {
	system("cls");

	int sloupce, radky;

	printf("Zadejte pocet sloupcu matice: ");
	scanf("%d", &sloupce);
	printf("Zadejte pocet radku matice: ");
	scanf("%d", &radky);

	Matice* mat = (Matice*) malloc(sizeof(Matice*) + sloupce * radky * sizeof(double));
	mat->sloupce = sloupce;
	mat->radky = radky;

	printf("Zadejte hodnoty matice (Oddelene mezerami nebo enterem):\n");
	for (int i = 0; i < sloupce * radky; i++) {
		scanf("%lf", mat->data + i);
	}

	return mat;
}

// Vypíše matici
void printMatrix(struct Matice* mat, int historie = 0) {
	printf("%c", 218);
	for (int i = 0; i < mat->sloupce; i++) printf("        ");
	printf("%c\n", 191);

	for (int i = 0; i < mat->sloupce * mat->radky; i++) {
		if (i % mat->sloupce == 0) printf("%c", 179);

		printf(" %6.2lf ", mat->data[i]);

		if ((i + 1) % mat->sloupce == 0) printf("%c\n", 179);
	}

	printf("%c", 192);
	for (int i = 0; i < mat->sloupce; i++) printf("        ");
	printf("%c\n", 217);

	// Zapis do historie
	if (historie) {
		FILE* fw;

		if ((fw = fopen("D://historie.txt", "a")) == NULL) {
			printf("Soubor historie se nepodarilo otevrit.\n");
			return;
		}

		time_t t = time(NULL);
		struct tm tm = *localtime(&t);

		fprintf(fw, "%d.%d.%d\t%d:%d:%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);

		for (int i = 0; i < mat->sloupce * mat->radky; i++) {
			fprintf(fw, " %6.2lf ", mat->data[i]);

			if ((i + 1) % mat->sloupce == 0) fprintf(fw, "\n");
		}

		fprintf(fw, "\n");

		if (fclose(fw) == EOF) printf("Chyba pri zavirani souboru historie.\n");

		getchar();
		getchar();
	}
}

void printZnamenko(int pocetSloupcu, char znamenko) {
	for (int i = 0; i < (pocetSloupcu * 8) / 2; i++) printf(" ");
	printf(" %c\n", znamenko);
}

int kontrolaRozmeru(struct Matice* mat) {
	if (mat->radky > 5 || mat->sloupce > 5) {
		system("cls");
		printf("Zadana matice nesmi byt vetsi nez 5x5!\n");
		getchar();
		getchar();
		return 1;
	}

	return 0;
}

// Vykoná souèet matic
void onSoucet() {
	Matice* matA = readMatrix();
	if (kontrolaRozmeru(matA)) return;
	Matice* matB = readMatrix();
	if (kontrolaRozmeru(matB)) return;

	Matice* mat = soucet(matA, matB);

	if (mat == NULL) {
		getchar();
		getchar();
		return;
	}

	system("cls");

	printMatrix(matA);
	printZnamenko(matA->sloupce, '+');
	printMatrix(matB);
	printZnamenko(matB->sloupce, '=');
	printMatrix(mat, 1);

	free(matA);
	free(matB);
	free(mat);
}

// Vykoná rozdíl matic
void onRozdil() {
	Matice* matA = readMatrix();
	if (kontrolaRozmeru(matA)) return;
	Matice* matB = readMatrix();
	if (kontrolaRozmeru(matB)) return;

	Matice* mat = rozdil(matA, matB);

	if (mat == NULL) {
		getchar();
		getchar();
		return;
	}

	system("cls");

	printMatrix(matA);
	printZnamenko(matA->sloupce, '-');
	printMatrix(matB);
	printZnamenko(matB->sloupce, '=');
	printMatrix(mat, 1);

	free(matA);
	free(matB);
	free(mat);
}

// Vykoná skalární souèin
void onSkalar() {
	Matice* matA = readMatrix();
	if (kontrolaRozmeru(matA)) return;

	system("cls");

	double skalar = 0;
	printf("Zadejte skalar, kterym chcete nasobit matici:\n");
	scanf("%lf", &skalar);

	Matice* mat = skalarniSoucin(matA, skalar);

	system("cls");

	printMatrix(matA);
	printZnamenko(matA->sloupce, '*');
	for (int i = 0; i < (matA->sloupce * 8) / 2; i++) printf(" ");
	printf("%.2lf\n", skalar);
	printZnamenko(matA->sloupce, '=');
	printMatrix(mat, 1);

	free(matA);
	free(mat);
}

// Vykoná maticový souèin
void onSoucin() {
	Matice* matA = readMatrix();
	if (kontrolaRozmeru(matA)) return;
	Matice* matB = readMatrix();
	if (kontrolaRozmeru(matB)) return;

	Matice* mat = soucin(matA, matB);

	if (mat == NULL) {
		system("cls");
		printf("Pocet sloupcu matice A musi byt stejny jako pocet radku matice B, jinak nasobeni neni definovano.\n");

		getchar();
		getchar();
		return;
	}

	system("cls");

	printMatrix(matA);
	printZnamenko(matA->sloupce, '*');
	printMatrix(matB);
	printZnamenko(matB->sloupce, '=');
	printMatrix(mat, 1);

	free(matA);
	free(matB);
	free(mat);
}

// Spoèítá determiannt
void onDeterm() {
	Matice* mat = readMatrix();

	double det = determinant(mat);

	system("cls");

	if (det == LONG_MAX) {
		printf("Zadana matice musi mit tvar ctverce a nesmi byt vetsi nez 4x4.\n");

		getchar();
		getchar();
		return;
	}

	printMatrix(mat);
	printZnamenko(mat->sloupce, '=');

	for (int i = 0; i < (mat->sloupce * 8) / 2; i++) printf(" ");
	printf("%.2lf\n", det);

	getchar();
	getchar();

	free(mat);
}

// Vypíše transponovanou matici
void onTrans() {
	Matice* matA = readMatrix();
	if (kontrolaRozmeru(matA)) return;

	Matice* mat = transpozice(matA);

	system("cls");

	printMatrix(matA);
	printZnamenko(matA->sloupce, 'T');
	printMatrix(mat, 1);

	free(matA);
	free(mat);
}

// todo
void onHodnost() {

}

// todo
void onInverze() {
	Matice* matA = readMatrix();
	Matice* mat = inverze(matA);

	system("cls");

	printMatrix(mat, 1);

	free(matA);
	free(mat);
}
