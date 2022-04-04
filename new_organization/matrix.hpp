#ifndef HEADER_FILE
#define HEADER_FILE


#include <iostream>
#include "myArithmetic.hpp"
#include "matrixErrors.hpp"




/*
 * 
 * Implamentation of Matrix Vector Multiplication
 *
 *
 *
 * */
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

/*
 *
 * Gaussian Elimination
 *
 *
 *
 * */
template<int R, int C>
void gauss(double (&input)[R][C], double (&output)[R][C])
{

int rowPivot = 0;
int columnPivot = 0;

double maxAbsolute;




//works down main diagonal of the matrix
while(rowPivot < R && columnPivot < C)
    {
     
        

	std::cout << absolute(input[rowPivot][columnPivot]) << ' ';
	
	
	if(absolute(input[rowPivot][columnPivot]) > maxAbsolute)
	    
	    maxAbsolute = input[rowPivot][columnPivot];
	    std::cout << " MAX VALUE = " << maxAbsolute << '\n';
	    

	rowPivot++;
	columnPivot++;
    }

}




void adj2by2(double (&input)[2][2], double (&output)[2][2]){

    output[0][0] = input[1][1];
    output[0][1] = -input[0][1];
    output[1][0] = -input[1][0];
    output[1][1] = input[0][0];

    //printMatrix(output);
}



template<unsigned R, unsigned C>
void invert(double (&inputMatrix)[R][C], double (&outputMatrix)[R][C]){

    double det = determinant(inputMatrix);
    double oneOverDet = 1/det;

    double adjOutput[2][2];
    adj2by2(inputMatrix, adjOutput);
    //printMatrix(adjOutput);

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
	
	    outputMatrix[i][j] = oneOverDet*adjOutput[i][j];
	
	}
    }

    //std::cout << oneOverDet << '\n';

    //printMatrix(outputMatrix);
}


template<unsigned R, unsigned C>
void applyInvert(double (&inputMatrix)[R][C], double (&inputVector)[C], double (&result)[R]){

    double inverted[R][C];

    invert(inputMatrix, inverted);

    std::cout << "This is the output of Invert\n";
    printMatrix(inverted);

    std::cout << "Output Done\n";

    std::cout << "Input Vector is\n";

    printVector(inputVector);

    matrixVector2by2(inputMatrix, inputVector, result);

    std::cout << "Result of Trasform is\n";

    printVector(result);

}


#endif
