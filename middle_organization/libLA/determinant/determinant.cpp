#include "determinant.hpp"

//Uncomment for debugging
//#include "../printLA/printLA.hpp"


//frankly there is probably no reason for this to exist, do not use.
double det2by2(double matrix2x2[2][2]){
        double result =  (matrix2x2[0][0] * matrix2x2[1][1]) - (matrix2x2[0][1] * matrix2x2[1][0]);
	return result;
}



//creates a new unsigned M which we can reference seperately
template<unsigned M>
//makeMinor takes an original matrix, a reference to allocated space for a minor and a column to ignore when constructing the minor
void makeMinor(double (&ogMatrix)[M][M], double (&minor)[M-1][M-1], int ignoreCol){

        //we have to index the minor cols and rows seperately
	int minorRow = 0;
	//i is the rows of the original matrix
	for(int i = 0; i<M; i++){
	    //if the top row, skip to next interation of the loop
	    if(i == 0)
		continue;

	    int minorCol = 0;
	    for(int j = 0; j<M; j++){
		//skip the column we want to ignore
	        if (j != ignoreCol){
		    //adds the original matrix values of the minor we care about to the seperate minor indexes
		    minor[minorRow][minorCol] = ogMatrix[i][j];
		    minorCol++;
		}
	    }
	//make sure this is in the i but not j loop 
	minorRow++;
	}
}


//only 1 dimesion because you need a square matrix for the determinant to be useful
template<unsigned N>
double determinant(double (&matrix)[N][N]){

	//base case to break recursion when we hit a 2x2 matrix
	if constexpr (N == 2){
		return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
        	}

	//won't compule without else even if it can never be hit due to return
	else{
	    double det = 0;
	    for(int j = 0; j < N; j++){

	       //define minor and call the function to fill the allocated memory (warning, for big enough matricies we might not be able to allocate on the stack like this)
	       double minor[N-1][N-1];
	       makeMinor(matrix,minor, j);

	       //if j mod 2 is 0 return 1 else return -1, same as saying (-1)^j because it checks even vs odd
	       double sign = (j % 2 == 0 ? 1 : -1);

               //Check documentation for math function
	       det += sign * matrix[0][j] * determinant(minor);
	    }
	return det;
	}

}






