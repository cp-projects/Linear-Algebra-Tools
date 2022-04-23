#ifndef __determinant_H_
#define __determinant_H_

double det2by2(double matrix2x2[2][2]);

template<unsigned R, unsigned C>
double determinant(double (&matrix)[R][C]);

#include "determinant.cpp"

#endif
