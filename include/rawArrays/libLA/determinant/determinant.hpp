#ifndef __determinant_H_
#define __determinant_H_

#include <cmath>

double det2by2(double matrix2x2[2][2]);

template<unsigned M>
void makeMinor(double (&ogMatrix)[M][M], double (&minor)[M-1][M-1], int ignorCol);

template<unsigned N>
double determinant(double (&matrix)[N][N]);

#include "determinant.cpp"

#endif
