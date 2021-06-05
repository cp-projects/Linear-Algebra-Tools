#include "matrix.hpp"
#include "myArithmetic.hpp"
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

	

	myArithmetic::test();
	



	double identity[4][4];

	generateIdentity(identity);

	printMatrix(identity);


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
	
	printMatrix(result);


	double A[3][3] = {
			    {1,2,1},
			    {3,8,1},
			    {0,4,1}
				};


        double aRowsSwapped[3][3];

	swapRows(3,2, A, aRowsSwapped);

        printMatrix(A);

        printMatrix(aRowsSwapped);

	
	
	double rowVector[3];

        extractColumn(1, A, rowVector);

	for(int i = 0; i < 3; i++) std::cout << rowVector[i] << ' ';
	std::cout << '\n';

	double test[2][2] = {
		              {1,2},
	                      {3,4}
	                           };
	
	printMatrix(test);
	
        std::cout << det2by2(test) << '\n';
	
	
	double letters[3][3] = {
                         {'a', 'b', 'c'},
                         {'d', 'e', 'f'},
                         {'g', 'h', 'i'}
                                         };
	

	double testTwo[4][4] = {
				
				{4,3,5,21},
				{2,4,5,11},	
				{13,41,2,2},
			        {2,4,5,4}	
				    };
	



	std::cout << determinant(result) << '\n';


	double testVector[4];
	double testVectorTwo[4];

        std::cout << '\n';
	extractRow(1, testTwo, testVector);
	
        printVector(testVector);

	extractColumn(1, testTwo, testVectorTwo);

	printVector(testVectorTwo);

        //going to come back to this, ideally shouldn't need to process the size of the array before calling dot method
	int size = sizeof(testVector)/sizeof(testVector[0]);	
	double dotProduct = dot(testVector, testVectorTwo, size);
	
	std::cout << '\n' << '\n' << dotProduct << '\n';



	scale(testVector, size, 2);

	printVector(testVector);

	std::cout << '\n';

	subtractVector(testVector, testVectorTwo, size);

	printVector(testVector);

	std::cout << '\n';

	double transform[4];
	matrixVectorMultiplication(identity, testVectorTwo, transform);

	printVector(transform);

        std::cout << '\n';

        double gaussOutput[4][4];

	gauss(testTwo, gaussOutput);	


return 0;
}
