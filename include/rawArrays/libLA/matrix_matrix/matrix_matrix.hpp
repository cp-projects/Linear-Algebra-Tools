#pragma once

#ifndef __matrixMatrix_H_
#define __matrixMatrix_H_

#include<cassert>

template<int N>
void matrixMultiplication(double (&matrixOne)[N][N], double (&matrixTwo)[N][N], double (&result)[N][N])
{

    //printf("matrixMultiplication nxn\n");

    //add documentation later that we need to not overwrite itself
    assert(&result != &matrixOne);
    assert(&result != &matrixTwo);

    std::cout << "Using SAME SIZE version\n";

    for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
        result[i][j] = 0;

    double temp;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){

	    double sum = 0;
            temp = matrixOne[j][i];
            for(int k = 0; k < N; k++){
                sum += matrixOne[i][k] * matrixTwo[k][j];
	    }
	    result[i][j] = sum;
        }
    }
}


template<int M, int N, int P>
void matrixMultiplication(double (&matrixOne)[M][N], double (&matrixTwo)[N][P], double (&result)[M][P]){

   assert(&result != &matrixOne);
   assert(&result != &matrixTwo);

   std::cout << "Using Different version\n";

   for(int i = 0; i < M; i++){
        for(int j = 0; j < P; j++){
	    double sum = 0;
            for(int k = 0; k < N; k++){
                sum += matrixOne[i][k] * matrixTwo[k][j];
	    }
	    result[i][j] = sum;
	}
    }
}


//eventually include the capability to throw an error when it's not NXN but for now this works
template<int N>
void matrixAddition(double (&matrixOne)[N][N], double (&matrixTwo)[N][N], double (&result)[N][N]){
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            result[i][j] = matrixOne[i][j] + matrixTwo[i][j];
}



#endif
