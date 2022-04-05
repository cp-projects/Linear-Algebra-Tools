#include "matrix_vector.hpp"


void matrixVector2by2(double (&matrix)[2][2], double vector[2], double result[2]){

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){

        result[i] += vector[i]*matrix[i][j];

        }
    }

}

template<int M, int N>
void matrixVectorMultiplication(double (&matrix)[M][N], double vector[N], double result[M])
{

    for(int i = 0; i < M; i++){
        double product = 0;
        for(int j = 0; j < N; j++){

                product += matrix[i][j] * vector[i];
            }

        result[i] = product;
    }

}


