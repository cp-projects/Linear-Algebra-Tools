#ifndef __vectorVector_H_
#define __vectorVector_H_

double dot(double* vectorOne, double* vectorTwo, int len);
void scale(double* vector, int len,  double scaler);

void addVectors(double* vectorOne, double* vectorTwo, int len);
void subtractVectors(double* vectorOne, double* vectorTwo, int len);

void addScaled(double* vectorOne, double* vectorTwo, int len, double scalar);
void subtractScaled(double* vectorOne, double* vectorTwo, int len, double scalar);

#endif
