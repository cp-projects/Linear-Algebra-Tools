#ifndef __matrixMatrix_H_
#define __matrixMatrix_H_

template<int R, int C>
void generateIdentity(double(&identity)[R][C]);

template<int R, int C>
void clearMatrix(double(&clear)[R][C]);

template<unsigned R, unsigned C>
void transpose(double (&original)[R][C], double (&transposed)[C][R]);

template<unsigned R, unsigned C>
void generateRandom(double(&random)[R][C]);

template<int R, int C>
void printMatrix(double(&matrix)[R][C]);

template<int N>
void matrixMultiplication(double (&matrixOne)[N][N], double (&matrixTwo)[N][N], double (&result)[N][N]);

template<int M, int N, int P>
void matrixMultiplication(double (&matrixOne)[M][N], double (&matrixTwo)[N][P], double (&result)[M][P]);

template<int N>
void matrixAddition(double (&matrixOne)[N][N], double (&matrixTwo)[N][N], double (&result)[N][N]);

#include "matrix_matrix.cpp"

#endif
