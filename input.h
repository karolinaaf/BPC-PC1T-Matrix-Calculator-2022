#pragma once

struct Matice* readMatrix();
void printMatrix(struct Matice* mat, int historie = 0);
void printZnamenko(int pocetSloupcu, char znamenko);

void onSoucet();
void onRozdil();
void onSkalar();
void onSoucin();
void onDeterm();
void onTrans();
void onHodnost();
void onInverze();
