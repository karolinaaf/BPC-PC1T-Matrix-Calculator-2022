// MaticovaKalkulacka.cpp : Defines the entry point for the application.
//

#include "MaticovaKalkulacka.h"
#include "input.h"
#include "operations.h"

typedef struct Matice {
	int sloupce, radky;
	double data[];
} Matice;

int main() {
	Matice* matA = readMatrix();
	Matice* matB = readMatrix();
	Matice* mat = soucet(matA, matB);

	printf("Matice:\n");
	for (int i = 0; i < mat->sloupce * mat->radky; i++) {
		printf("%.1lf ", mat->data[i]);
	}

	free(matA);
	free(matB);
	free(mat);
	return 0;
}
