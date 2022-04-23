#ifndef __matrixMatrix_H_
#define __matrixMatrix_H_

template<int N>
void matrixMultiplication(double (&matrixOne)[N][N], double (&matrixTwo)[N][N], double (&result)[N][N]);

template<int M, int N, int P>
void matrixMultiplication(double (&matrixOne)[M][N], double (&matrixTwo)[N][P], double (&result)[M][P]);

template<int N>
void matrixAddition(double (&matrixOne)[N][N], double (&matrixTwo)[N][N], double (&result)[N][N]);

#include "matrix_matrix.cpp"

#endif
