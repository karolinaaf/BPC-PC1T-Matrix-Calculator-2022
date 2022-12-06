#include "stdio.h"
#include "stdlib.h"
#include "math.h"

typedef struct Matice {
	int sloupce, radky;
	double data[];
} Matice;

// Kontroluje, jestli mají zadané matice shodné rozmìry
int shodnostRozmeru(struct Matice* matA, struct Matice* matB) {
	if (matA->sloupce != matB->sloupce || matA->radky != matB->radky) {
		system("cls");
		printf("Zadane matice nemaji stejne rozmery.\n");
		return 0;
	}
	
	return 1;
}

// Vrací matici, která je souètem zadaných matic
struct Matice* soucet(struct Matice* matA, struct Matice* matB) {
	if (shodnostRozmeru(matA, matB) == 0) return NULL;

	Matice* mat = (Matice*)malloc(sizeof(Matice*) + matA->sloupce * matA->radky * sizeof(double));
	mat->sloupce = matA->sloupce;
	mat->radky = matA->radky;

	for (int i = 0; i < mat->sloupce * mat->radky; i++)
		mat->data[i] = matA->data[i] + matB->data[i];

	return mat;
}

// Vrací matici, která je rozdílem zadaných matic
struct Matice* rozdil(struct Matice* matA, struct Matice* matB) {
	if (shodnostRozmeru(matA, matB) == 0) return NULL;

	Matice* mat = (Matice*)malloc(sizeof(Matice*) + matA->sloupce * matA->radky * sizeof(double));
	mat->sloupce = matA->sloupce;
	mat->radky = matA->radky;

	for (int i = 0; i < mat->sloupce * mat->radky; i++)
		mat->data[i] = matA->data[i] - matB->data[i];

	return mat;
}

// Vrací matici, která je souèinem matice a zadaného èísla
struct Matice* skalarniSoucin(struct Matice* matA, double skalar) {
	Matice* mat = (Matice*)malloc(sizeof(Matice*) + matA->sloupce * matA->radky * sizeof(double));
	mat->sloupce = matA->sloupce;
	mat->radky = matA->radky;

	for (int i = 0; i < mat->sloupce * mat->radky; i++)
		mat->data[i] = matA->data[i] * skalar;

	return mat;
}

// Vrací matici, která je souèinem zadaných matic
struct Matice* soucin(struct Matice* matA, struct Matice* matB) {
	if (matA->sloupce != matB->radky) return NULL;

	Matice* mat = (Matice*)malloc(sizeof(Matice*) + matA->sloupce * matA->radky * sizeof(double));
	mat->sloupce = matB->sloupce;
	mat->radky = matA->radky;

	// Bruh
	double soucet;
	for (int i = 0; i < matA->radky; i++) {
		for (int j = 0; j < matB->sloupce; j++) {
			soucet = 0;
			for (int k = 0; k < matA->sloupce; k++)
				soucet += matA->data[ matA->sloupce* i + k] * matB->data[matB->sloupce * k + j];
			mat->data[matB->sloupce * i + j] = soucet;
		}
	}

	return mat;
}

// Vrací determinant zadané matice
double determinant(struct Matice* mat) {
	if (mat->radky != mat->sloupce) return LONG_MAX; // Overeni, ze matice je ctverec
	if (mat->radky > 4) return LONG_MAX; // Podle zadani nesmi matice byt vetsi nez 4x4

	switch (mat->radky) {
	case 1:
		return mat->data[0];
	case 2:
		return mat->data[0] * mat->data[3] - mat->data[1] * mat->data[2];
	case 3:
		return mat->data[0] * mat->data[4] * mat->data[8]
			 + mat->data[3] * mat->data[7] * mat->data[2]
			 + mat->data[6] * mat->data[1] * mat->data[5]
			 - mat->data[2] * mat->data[4] * mat->data[6]
			 - mat->data[5] * mat->data[7] * mat->data[0]
			 - mat->data[8] * mat->data[1] * mat->data[3];
	case 4:
		return mat->data[0] * pow(-1, 2) *
			  (mat->data[5] * mat->data[10] * mat->data[15]
			 + mat->data[9] * mat->data[14] * mat->data[7]
			 + mat->data[13] * mat->data[6] * mat->data[11]
			 - mat->data[7] * mat->data[10] * mat->data[13]
			 - mat->data[11] * mat->data[14] * mat->data[5]
			 - mat->data[15] * mat->data[6] * mat->data[9])
			 + mat->data[4] * pow(-1, 3) *
			  (mat->data[1] * mat->data[10] * mat->data[15]
			 + mat->data[9] * mat->data[14] * mat->data[3]
			 + mat->data[13] * mat->data[2] * mat->data[11]
			 - mat->data[3] * mat->data[10] * mat->data[13]
			 - mat->data[2] * mat->data[9] * mat->data[15]
			 - mat->data[1] * mat->data[11] * mat->data[14])
			 + mat->data[8] * pow(-1, 4) *
			  (mat->data[1] * mat->data[6] * mat->data[15]
			 + mat->data[5] * mat->data[14] * mat->data[3]
			 + mat->data[13] * mat->data[2] * mat->data[7]
			 - mat->data[3] * mat->data[6] * mat->data[13]
			 - mat->data[7] * mat->data[14] * mat->data[1]
			 - mat->data[15] * mat->data[2] * mat->data[5])
			 + mat->data[12] * pow(-1, 5) *
			  (mat->data[1] * mat->data[6] * mat->data[11]
			 + mat->data[5] * mat->data[10] * mat->data[3]
			 + mat->data[9] * mat->data[2] * mat->data[7]
			 - mat->data[3] * mat->data[6] * mat->data[9]
			 - mat->data[7] * mat->data[10] * mat->data[1]
			 - mat->data[11] * mat->data[2] * mat->data[5]);
	}
}

// Vrací transponovanou matici od zadané matice
struct Matice* transpozice(struct Matice* matA) {
	Matice* mat = (Matice*)malloc(sizeof(Matice*) + matA->sloupce * matA->radky * sizeof(double));
	mat->sloupce = matA->radky;
	mat->radky = matA->sloupce;

	int index = 0;
	for (int i = 0; i < mat->sloupce; i++) {
		for (int j = 0; j < mat->radky; j++)
			mat->data[j * mat->sloupce + i] = matA->data[i * mat->radky + j];
	}

	return mat;
}

struct Matice* inverze(struct Matice* matA) {
	if (matA->radky != matA->sloupce) return NULL; // Overeni, ze matice je ctverec
	if (matA->radky > 4) return NULL; // Matice nesmi byt vetsi nez 4x4 kvoli omezeni funkce determiannt()
	if (determinant(matA) == 0) return NULL; // Determinant matice nesmi byt 0

	Matice* mat = (Matice*)malloc(sizeof(Matice*) + matA->sloupce * matA->radky * sizeof(double));
	mat->sloupce = matA->sloupce;
	mat->radky = matA->radky;

	return mat;
}