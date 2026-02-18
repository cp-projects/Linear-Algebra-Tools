#include <iostream>
#include "determinant.hpp"
#include "../printLA/printLA.hpp"

int main(){

double test[2][2] = {{1, 0},
                     {24, 2}};

double testVal = det2by2(test);

//std::cout << testVal << '\n';

std::cout << "the matrix test is: ";

printMatrix(test);

std::cout << "and it's determinant is: \n";

std::cout << determinant(test) << "\n \n";




double test1[3][3] = {{1, 0, 54},
                     {24, 2, -7},
                     {3.4, 2.7, 5.5}};

std::cout << "The matrix test1 is: ";
printMatrix(test1);
std::cout << "and it's determinant is: \n";

double TV = determinant(test1);

std::cout << TV << "\n \n";



double test2[4][4] = {{1, 0, 54, 11.1},
                     {24, 2, -7, 99},
                     {3.4, 2.7, 5.5, 8.13},
		     {1, -24, -3.7, 0.001}};


std::cout << "The matrix test2 is: ";
printMatrix(test2);
std::cout << "and its determinant is: \n";
double TV2 = determinant(test2);

std::cout << TV2 << '\n';



return 0;
}
