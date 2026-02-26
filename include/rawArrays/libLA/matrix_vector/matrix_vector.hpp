#pragma once

#ifndef __matrixVector_H_
#define __matrixVector_H_

template<int M, int N>
void matrixVectorMultiplication(double (&matrix)[M][N], double vector[N], double result[M])
{

    for(int i = 0; i < M; i++){
        double product = 0;
        for(int j = 0; j < N; j++){

                product += matrix[i][j] * vector[j];
            }

        result[i] = product;
    }

}




#endif
