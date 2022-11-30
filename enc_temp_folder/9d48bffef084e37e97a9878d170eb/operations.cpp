#include "stdio.h"
#include "stdlib.h"

typedef struct Matice {
	int sloupce, radky;
	double data[];
} Matice;

struct Matice* soucet(struct Matice* matA,struct Matice* matB) {
	if (matA->sloupce != matB->sloupce || matA->radky != matB->radky) {
		printf("Zadane matice nemaji stejne rozmery.\n");
		return NULL;
	}

	Matice* mat = (Matice*)malloc(sizeof(Matice*) + matA->sloupce * matA->radky * sizeof(double));
	mat->sloupce = matA->sloupce;
	mat->radky = matA->radky;

	for (int i = 0; i < mat->sloupce * mat->radky; i++)
		mat->data[i] = matA->data[i] + matB->data[i];

	return mat;
}