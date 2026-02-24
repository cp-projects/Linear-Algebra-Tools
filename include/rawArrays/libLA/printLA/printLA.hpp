#ifndef __printLA_H_
#define __printLA_H_

template<int R, int C>
void printMatrix(double(&matrix)[R][C]);


template<int R>
void printVector(double (&vector)[R]);

#include <iostream>



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


/*
 *
 * Method to print a vector
 *
 *
 *
 * */
template<int R>
void printVector(double (&vector)[R]){

    std::cout << '\n';
    
    for(int i = 0; i < R; i++)
        {std::cout << vector[i] << ' ';}

    std::cout << '\n';
    std::cout << '\n';

}




#endif
