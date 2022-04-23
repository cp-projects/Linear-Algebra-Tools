#ifndef __rowOps_H_
#define __rowOps_H_


template<int R, int C>
void extractRow(int rowIndex, double (&original)[R][C], double rowVector[C]);

template<int R, int C>
void replaceRow(int rowIndex, double (&original)[R][C], double rowVector[C]);

template<int R, int C>
void extractColumn(int columnIndex, double (&original)[R][C], double columnVector[R]);

template<int R, int C>
void replaceColumn(int columnIndex, double (&original)[R][C], double columnVector[R]);


template<unsigned R, unsigned C>
void swapRows(int rowOne, int rowTwo, double (&original)[R][C], double (&swapped)[R][C]);

#include "row_ops.cpp"

#endif
