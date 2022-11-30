// MaticovaKalkulacka.cpp : Defines the entry point for the application.
//

#include "MaticovaKalkulacka.h"
#include "input.h"

using namespace std;

int main()
{
	struct Matice {
		int sloupce, radky;
		double* data;
	};
	FILE* fr, * fw;

	char fileName[64];
	char inputFilePath[] = "D://";
	printf("Zadejte nazev souboru:");
	scanf("%64s", fileName);
	strcat(inputFilePath, fileName);
	if ((fr = fopen(inputFilePath, "r")) == NULL) {
		printf("Chyba pri otevirani %s\n", inputFilePath);
		return 0;
	}

	if (fclose(fr) == EOF) printf("Chyba pri zavirani %s\n", inputFilePath);
	if (fclose(fw) == EOF) printf("Chyba pri zavirani souboru.\n");
	return 0;
}
