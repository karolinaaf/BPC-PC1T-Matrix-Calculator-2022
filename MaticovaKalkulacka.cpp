// MaticovaKalkulacka.cpp : Defines the entry point for the application.
//

#include "MaticovaKalkulacka.h"
#include "input.h"

typedef struct Matice {
	int sloupce, radky;
	double data[];
} Matice;

int main() {
	Matice* mat = readMatrix();

	printf("Matice:\n");
	for (int i = 0; i < mat->sloupce * mat->radky; i++) {
		printf("%.1lf ", mat->data[i]);
	}

	free(mat);
	return 0;
}
