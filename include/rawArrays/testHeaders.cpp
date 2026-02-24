#include "libLA.hpp"

int main(){


        //Checks C++ Version we are actually using, that g++ compiles with naturally without a fla
        std::cout << __cplusplus << std::endl;

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

	std::cout << "\n\n";

	double test[2][2] = {
		              {1,2},
	                      {3,4}
	                           };
	std::cout << "new test matrix:\n";
	printMatrix(test);
	
	std::cout << "deterimant of the test matrix is: \n";
        //std::cout << det2by2(test) << '\n';
	std::cout << determinant(test) << '\n';
	//Now, I could use the old det2x2(test) method, but why it is pointless and probably shouldn't exist
	
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
	//Me again later, it turned out I was avoiding the fact that my determinant function only worked for 3x3 matricies,
	//so when I put in the testTwo function, which is 4x4, it crashed, and rather than rewriting the function (which I just did)
	//I just switched to the 3x3 matrix so it would compile, very bad practice unless I noted very clearly that this was something
	//to fix immediately after fixing somethinmg else, and even then, probably should have just commented it out.

 
	std::cout << "the testTwo matrix is below:\n";
	printMatrix(testTwo);
	std::cout << "and it's determinant is: \n";
	std::cout << determinant(testTwo) << '\n';

	double test3[4][4] = {{1, 0, 54, 11.1},
                     {24, 2, -7, 99},
                     {3.4, 2.7, 5.5, 8.13},
                     {1, -24, -3.7, 0.001}};


         std::cout << "\n The matrix test3 is: ";
         printMatrix(test3);
         std::cout << "and its determinant is: \n";
         double TV3 = determinant(test3);
         std::cout << TV3 << '\n';

	double testVector[4];
	double testVectorTwo[4];

        std::cout << '\n';
	extractRow(1, test3, testVector);

        std::cout << "This is testVector = 1st row vector of test3 extracted by extractRow function";	
        printVector(testVector);
	
	std::cout << '\n';
	extractColumn(1, testTwo, testVectorTwo);

	std::cout << "This is testVectorTwo = 1st column vector of testTwo extracted by extractColumn function";
	printVector(testVectorTwo);

        //going to come back to this, ideally shouldn't need to process the size of the array before calling dot method
	//adding to this comment much later, I think what I was saying is that (ideally) I can perhaps build the size calculation into the dot function
	//but I'm not sure even this is possible, obviously we need to know the size of the the arrays we're talking about so it needs to be defined somewhere
	//I think most realistic is once I rewrite/reconsider as a "vector" object/class rather than raw arrays, failing that, if possible, inside the function
	//failing this as is
	int size = sizeof(testVector)/sizeof(testVector[0]);	
	double dotProduct = dot(testVector, testVectorTwo, size);
	

	std::cout << '\n' << "The dot product of testVector and testVectorTwo is: " << '\n' << dotProduct << '\n';

	std::cout << '\n';

	scale(testVector, size, 2);

	std::cout << "this is testVector scaled by 2 (note, this changes original testVector, doesn't create a new scaled vector)";
	printVector(testVector);

	std::cout << '\n' << "This is the (newly scaled) testVector - testVectorTwo, not that this will also overwrite the value of the testVector variable";
	subtractVectors(testVector, testVectorTwo, size);
	printVector(testVector);

	std::cout << '\n' << '\n';

	double transform[4];
	matrixVectorMultiplication(identity, testVectorTwo, transform);

	std::cout << "This is the result of the identity times testVectorTwo";
	printVector(transform);

        std::cout << '\n' << '\n' << '\n';

        std::cout << "reminder of testTwo matrix";
	printMatrix(testTwo);

	matrixVectorMultiplication(testTwo, testVectorTwo, transform);
	std::cout << "This is the result of testVectorTwo times testTwo matrix";
	printVector(transform);

        double gaussOutput[4][4];
        gauss(testTwo, gaussOutput);
	std::cout << "This is the result of Gaussian elimination on testTwo matrix";
        printMatrix(gaussOutput);

	
       	std::cout << '\n' << '\n' << absolute(-7.5) <<'\n';


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
