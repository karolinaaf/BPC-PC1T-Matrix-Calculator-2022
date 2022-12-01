// MaticovaKalkulacka.cpp : Defines the entry point for the application.
//

#include "MaticovaKalkulacka.h"
#include "input.h"

typedef struct Matice {
	int sloupce, radky;
	double data[];
} Matice;

int main() {
	char cmd;

	do {
		system("cls");

		printf("Q: Konec %c ", 186); 
		printf("W: Soucet %c ", 186);
		printf("E: Rozdil %c ", 186);
		printf("R: Skalarni soucin %c ", 186);
		printf("T: Vektorovy soucin\n");
		printf("U: Determinant %c ", 186);
		printf("I: Transpozice %c ", 186);
		printf("O: Hodnost %c ", 186);
		printf("P: Inverze\n\n");

		cmd = tolower(getchar());
		while (getchar() != '\n');

		switch (cmd) {
		case 'w':
			onSoucet();
			break;
		case 'e':
			onRozdil();
			break;
		case 'r':
			onSkalar();
			break;
		case 't':
			onSoucin();
			break;
		case 'u':
			onDeterm();
			break;
		case 'i':
			onTrans();
			break;
		case 'o':
			onHodnost();
			break;
		case 'p':
			onInverze();
			break;
		}
	} while (cmd != 'q');

	return 0;
}
