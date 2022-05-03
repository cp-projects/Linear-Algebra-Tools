#ifndef __printLA_H_
#define __printLA_H_

template<int R, int C>
void printMatrix(double(&matrix)[R][C]);


template<int R>
void printVector(double (&vector)[R]);

#include "printLA.cpp"

#endif
