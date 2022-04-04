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


return 0;
}
