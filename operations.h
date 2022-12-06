#pragma once

int shodnostRozmeru(struct Matice* matA, struct Matice* matB);

struct Matice* soucet(Matice* matA, Matice* matB);
struct Matice* rozdil(struct Matice* matA, struct Matice* matB);
struct Matice* skalarniSoucin(struct Matice* matA, double skalar);
struct Matice* soucin(struct Matice* matA, struct Matice* matB);
double determinant(struct Matice* mat);
struct Matice* transpozice(struct Matice* matA);
struct Matice* inverze(struct Matice* matA);