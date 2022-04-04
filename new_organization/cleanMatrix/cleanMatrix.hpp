#ifndef __cleanMatrix_H_
#define __cleanMatrix_H_

template<int R, int C>
void generateIdentity(double(&identity)[R][C]);

template<int R, int C>
void clearMatrix(double(&clear)[R][C]);

#include "cleanMatrix.cpp"

#endif
