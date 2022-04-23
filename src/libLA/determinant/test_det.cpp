#include <iostream>
#include "determinant.hpp"

int main(){

double test[2][2] = {{1, 0},
                     {24, 2}};

double testVal = determinant(test);

std::cout << testVal << '\n';




double test1[3][3] = {{1, 0, 54},
                     {24, 2, -7},
                     {3.4, 2.7, 5.5}};

double TV = determinant(test1);

std::cout << TV << '\n';


/*
double test2[4][4] = {{1, 0, 54, 11.1},
                     {24, 2, -7, 99},
                     {3.4, 2.7, 5.5, 8.13},
		     {1, -24, -3.7, 0.001}};

double TV2 = determinant(test2);

std::cout << TV2 << '\n';
*/


return 0;
}
