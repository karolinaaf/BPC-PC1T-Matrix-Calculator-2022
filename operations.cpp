#include "stdio.h"
#include "stdlib.h"

typedef struct Matice {
	int sloupce, radky;
	double data[];
} Matice;

// Kontroluje, jestli maj� zadan� matice shodn� rozm�ry
int shodnostRozmeru(struct Matice* matA, struct Matice* matB) {
	if (matA->sloupce != matB->sloupce || matA->radky != matB->radky) {
		system("cls");
		printf("Zadane matice nemaji stejne rozmery.\n");
		return 0;
	}
	
	return 1;
}

// Vrac� matici, kter� je sou�tem zadan�ch matic
struct Matice* soucet(struct Matice* matA, struct Matice* matB) {
	if (shodnostRozmeru(matA, matB) == 0) return NULL;

	Matice* mat = (Matice*)malloc(sizeof(Matice*) + matA->sloupce * matA->radky * sizeof(double));
	mat->sloupce = matA->sloupce;
	mat->radky = matA->radky;

	for (int i = 0; i < mat->sloupce * mat->radky; i++)
		mat->data[i] = matA->data[i] + matB->data[i];

	return mat;
}

// Vrac� matici, kter� je rozd�lem zadan�ch matic
struct Matice* rozdil(struct Matice* matA, struct Matice* matB) {
	if (shodnostRozmeru(matA, matB) == 0) return NULL;

	Matice* mat = (Matice*)malloc(sizeof(Matice*) + matA->sloupce * matA->radky * sizeof(double));
	mat->sloupce = matA->sloupce;
	mat->radky = matA->radky;

	for (int i = 0; i < mat->sloupce * mat->radky; i++)
		mat->data[i] = matA->data[i] - matB->data[i];

	return mat;
}