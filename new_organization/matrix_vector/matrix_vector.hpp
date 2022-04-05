#ifndef __matrixVector_H_
#define __matrixVector_H_


void matrixVector2by2(double (&matrix)[2][2], double vector[2], double result[2]);

template<int M, int N>
void matrixVectorMultiplication(double (&matrix)[M][N], double vector[N], double result[M]);

#include "matrix_vector.cpp"

#endif
