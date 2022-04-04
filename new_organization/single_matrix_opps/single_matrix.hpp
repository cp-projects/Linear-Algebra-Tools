#ifndef __singleMatrix_H_
#define __singleMatrix_H_

template<int R, int C>
void generateIdentity(double(&identity)[R][C]);

template<int R, int C>
void clearMatrix(double(&clear)[R][C]);

template<unsigned R, unsigned C>
void transpose(double (&original)[R][C], double (&transposed)[C][R]);

template<unsigned R, unsigned C>
void generateRandom(double(&random)[R][C]);

#include "single_matrix.cpp"

#endif
