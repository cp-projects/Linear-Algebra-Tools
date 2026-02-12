#include "libLA.hpp"

int main(){	

	double identity[4][4];

	generateIdentity(identity);

	printMatrix(identity);


	double input[3][4] = {
	
	    {1,2,3,4},
	    {5,6,7,8},
	    {9,9,0,0}
	  
	};

	std::cout << "This is Input\n";	
	printMatrix(input);


 	double output[4][3];	
 
        transpose(input, output);

	std::cout << "This is Output (the output of input transposed)\n";
	printMatrix(output);	



	double result[3][3];

	matrixMultiplication(input, output, result);


	std::cout << "This is the Matrix Multiplication of intput * output\n";
	printMatrix(result);


	double A[3][3] = {
			    {1,2,1},
			    {3,8,1},
			    {0,4,1}
				};


        double aRowsSwapped[3][3];

	swapRows(3,2, A, aRowsSwapped);

        
	std::cout << "This is the original matrix A before swapping rows 3 and 2\n";
	
	printMatrix(A);

	std::cout << "This is the matrix aRowsSwapped after swapping rows 3 and 2\n";
	printMatrix(aRowsSwapped);

	
	
	double rowVector[3];

        extractColumn(1, A, rowVector);

	std::cout << "extracted col 1 form the matrix A (as a row vector form I guess? not sure why I called it rowvector tbh) and attempt to print below\n";
	for(int i = 0; i < 3; i++) std::cout << rowVector[i] << ' ';
	std::cout << '\n';

	double test[2][2] = {
		              {1,2},
	                      {3,4}
	                           };
	
	//printMatrix(test);
	
        //std::cout << det2by2(test) << '\n';
	
	
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
	
        

	//for some reason this is testing my determinant function on result all the way back at the top, idk man


	std::cout << determinant(result) << '\n';


	double testVector[4];
	double testVectorTwo[4];

        std::cout << '\n';
	extractRow(1, testTwo, testVector);
	
        printVector(testVector);

	
	std::cout << '\n';
	extractColumn(1, testTwo, testVectorTwo);

	printVector(testVectorTwo);

        //going to come back to this, ideally shouldn't need to process the size of the array before calling dot method
	int size = sizeof(testVector)/sizeof(testVector[0]);	
	double dotProduct = dot(testVector, testVectorTwo, size);
	
	std::cout << '\n' << '\n' << dotProduct << '\n';

	std::cout << '\n';

	scale(testVector, size, 2);

	printVector(testVector);

	std::cout << '\n';

	subtractVectors(testVector, testVectorTwo, size);

	printVector(testVector);

	std::cout << '\n' << '\n';

	double transform[4];
	matrixVectorMultiplication(identity, testVectorTwo, transform);

        printVector(transform);

        std::cout << '\n' << '\n' << '\n';
	
	printMatrix(testTwo);

        double gaussOutput[4][4];

	gauss(testTwo, gaussOutput);	

	
       	//std::cout << '\n' << '\n' << absolute(-7.5) <<'\n';


	double crossResVector[3];
	std::cout << '\n';


        double crossVecOne[3] = {-2,5,4};
        double crossVecTwo[3] = {2,-3,-9};

	cross(crossVecOne, crossVecTwo, crossResVector);

	printVector(crossResVector);

	std::cout << "This is the Invert Method\n";

	double invertOutput[2][2];

	double myHomeWork[2][2] = {
		                    {3, 1},
	                            {-4, 6}
              					};

	//std::cout << "This is the input to invert\n";

	//printMatrix(myHomeWork);
	
	//invert(myHomeWork, invertOutput);

       // std::cout << "This is ivert Output\n";

	/*
	printMatrix(invertOutput);

	double appliedTransform[2];
	double transformInput[2];
        transformInput[0] = 148;
	transformInput[1] = 440;
	applyInvert(myHomeWork, transformInput, appliedTransform);

	//printVector(appliedTransform);

         */


return 0;

}
