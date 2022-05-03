#include "matrix_matrix.hpp"
#include "../errorsLA/matrixErrors.hpp"


/*
 * Method to print a matrix
 * 
 *
 * */

template<int R, int C>
void printMatrix(double(&matrix)[R][C])
{

        std::cout << '\n';

         for(int i = 0; i < R; i++)
            {for(int j = 0; j < C; j++){
                std::cout <<  matrix[i][j]  << ' ';}
            std::cout << '\n'; }

        std::cout << '\n';

}



template<int R, int C>
void generateIdentity(double(&identity)[R][C]){

    if(R != C) throw mustBeSquare();

    for(int i = 0; i < R; i++){

        for(int j = 0; j < C; j++){

            if(i == j) identity[i][j] = 1;

            else{ identity[i][j] = 0;}  }   }
}




template<int R, int C>
void clearMatrix(double(&clear)[R][C]){

    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            clear[i][j] = 0;


}


template<unsigned R, unsigned C>
void transpose(double (&original)[R][C], double (&transposed)[C][R])
{

     for(int i = 0; i < R; i++){
         for(int j = 0; j < C; j++){
             transposed[j][i] = original[i][j];}
     }
}


template<unsigned R, unsigned C>
void generateRandom(double(&random)[R][C]){

    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            random[i][j] = rand() % 70;


}



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

