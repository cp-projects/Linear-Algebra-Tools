#pragma once

#ifndef __matrixMatrix_H_
#define __matrixMatrix_H_


template<int N>
void matrixMultiplication(double (&matrixOne)[N][N], double (&matrixTwo)[N][N], double (&result)[N][N])
{

    //printf("matrixMultiplication nxn\n");

    double temp;
    for(int v = 0; v < N; v++){
        for(int i = 0; i < N; i++){

            temp = matrixOne[i][v];
            for(int j = 0; j < N; j++)
                result[i][j] += temp * matrixTwo[v][j];
        }
    }
}


template<int M, int N, int P>
void matrixMultiplication(double (&matrixOne)[M][N], double (&matrixTwo)[N][P], double (&result)[M][P]){
    for(int i = 0; i < M; i++)
        for(int j = 0; j < P; j++)
            for(int v = 0; v < N; v++)
                result[i][j] += matrixOne[i][v] * matrixTwo[v][j];
}


//eventually include the capability to throw an error when it's not NXN but for now this works
template<int N>
void matrixAddition(double (&matrixOne)[N][N], double (&matrixTwo)[N][N], double (&result)[N][N]){
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            result[i][j] = matrixOne[i][j] + matrixTwo[i][j];
}



#endif
