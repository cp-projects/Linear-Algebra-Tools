#include "matrix.hpp"
#include <iostream>

/*

template<int R, int C>
void printMatrix(double(&matrix)[R][C])
{

	 for(int i = 0; i < R; i++)
            {for(int j = 0; j < C; j++){
                std::cout << matrix[i][j]  << ' ';}
            std::cout << '\n'; }

	std::cout << '\n';
        std::cout << '\n';
        std::cout << '\n';
}

*/




int main(){


	double input[3][4] = {
	
	    {1,2,3,4},
	    {5,6,7,8},
	    {9,9,0,0}
	  
	};

	printMatrix(input);


 	double output[4][3];	
 
        transpose(input, output);

	printMatrix(output);	



	double result[3][3];

	matrixMultiplication(input, output, result);
	
	printMatrix(output);


	double test[2][2] = {
		              {1,2},
	                      {3,4}
	                           };
	
	printMatrix(test);
	
	//std::cout << det2by2(test) << '\n';
	
	
	double letters[3][3] = {
                         {'a', 'b', 'c'},
                         {'d', 'e', 'f'},
                         {'g', 'h', 'i'}
                                         };
	
	determinant(letters);




return 0;
}
