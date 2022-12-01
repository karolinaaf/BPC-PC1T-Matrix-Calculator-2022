#include "stdio.h"
#include "stdlib.h"
#include "operations.h"

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
void printMatrix(struct Matice* mat) {
	printf("Matice:\n");
	for (int i = 0; i < mat->sloupce * mat->radky; i++) {
		printf("%.1lf ", mat->data[i]);
	}
	printf("\n");

	getchar();
	getchar();
}

// Vykoná souèet matic
void onSoucet() {
	Matice* matA = readMatrix();
	Matice* matB = readMatrix();
	Matice* mat = soucet(matA, matB);

	printMatrix(mat);

	free(matA);
	free(matB);
	free(mat);
}

// Vykoná rozdíl matic
void onRozdil() {
	Matice* matA = readMatrix();
	Matice* matB = readMatrix();
	Matice* mat = rozdil(matA, matB);

	printMatrix(mat);

	free(matA);
	free(matB);
	free(mat);
}

// todo
void onSkalar() {

}

// todo
void onSoucin() {

}

// todo
void onDeterm() {

}

// todo
void onTrans() {

}

// todo
void onHodnost() {

}

// todo
void onInverze() {

}
