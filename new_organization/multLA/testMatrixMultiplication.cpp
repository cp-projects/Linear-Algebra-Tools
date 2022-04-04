#include "matrix.hpp"

int main(){

double A[2][2] = {
	           {-52, 18},
                   {6.34, 100}
                              };

double B[2][2] = {
                    {10, -27.5},
		    {99,  -22.75}
                                  };

std::cout << "A is \n";
printMatrix(A);

std::cout << "B is \n";
printMatrix(B);

double result[2][2];

matrixMultiplication(A, B, result);

std::cout << "\nA * B = ";
printMatrix(result);
clearMatrix(result);

matrixMultiplication(B, A, result);

std::cout << "\nB * A = ";
printMatrix(result);
clearMatrix(result);


double A1[3][3] = {
                   {55, 104.22, 1},
	           {-12.76, 0.001, -22},
	           {105.5, 10, 1.12}	   
                                        };

double B1[3][3] = {
                   {-1.2, 129, 0.0001},
                   {16, 88, 102.2},
                   {-10.5, 77.6, -32}
                                        };

std::cout << "A1 is \n";
printMatrix(A1);

std::cout << "B1 is \n";
printMatrix(B1);

double result1[3][3];

matrixMultiplication(A1, B1, result1);

std::cout << "\nA1 * B1 =";
printMatrix(result1);
clearMatrix(result1);

matrixMultiplication(B1, A1, result1);

std::cout << "\nB1 * A1 =";
printMatrix(result1);
clearMatrix(result1);


double A2[4][4] = {
                   {1.2, 7000, -45, 69},
                   {63.33, 2, 74, -62.2},
                   {3.5, 13, 117, -0.01},
		   {0,0,0,0}
                                        };

double B2[4][4] = {
                   {11, -89, 7.71, 16},
                   {-20.2, 99, 73.3, 55},
                   {-4.5, 24, -1.73, 8.8},
		   {0,0,0,0}
                                          };

std::cout << "A2 is \n";
printMatrix(A2);

std::cout << "B2 is \n";
printMatrix(B2);

double result2[4][4];

matrixMultiplication(A2, B2, result2);

std::cout << "\nA2 * B2 =";
printMatrix(result2);
clearMatrix(result2);

matrixMultiplication(B2, A2, result2);

std::cout << "\nB2 * A2 =";
printMatrix(result2);
clearMatrix(result2);



return 0;
}
