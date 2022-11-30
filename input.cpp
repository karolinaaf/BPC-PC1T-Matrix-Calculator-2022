#include "stdio.h"
#include "stdlib.h"

typedef struct Matice {
	int sloupce, radky;
	double data[];
} Matice;

struct Matice* readMatrix() {
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