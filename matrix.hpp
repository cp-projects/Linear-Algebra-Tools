#ifndef HEADER_FILE
#define HEADER_FILE

#include "myArithmetic.hpp"

/*
 * Method to print a matrix
 * 
 *
 * */


#include <iostream>
template<int R, int C>
void printMatrix(double(&matrix)[R][C])
{

	std::cout << '\n';

         for(int i = 0; i < R; i++)
            {for(int j = 0; j < C; j++){
                std::cout <<  matrix[i][j]  << ' ';}
            std::cout << '\n'; }

        std::cout << '\n';
        
}


/*
 *
 * Method to print a vector
 *
 *
 *
 * */
template<int R>
void printVector(double (&vector)[R])
{


    std::cout << '\n';

    for(int i = 0; i < R; i++)
    {
    
        std::cout << vector[i] << ' ';
    
    }


}





/*
 * Method to generate the Identity Matrix
 *
 * */


template<int R, int C>
void generateIdentity(double(&identity)[R][C])
{

    for(int i = 0; i < R; i++){
    
        for(int j = 0; j < C; j++){
	
	    if(i == j) identity[i][j] = 1;

	    else{
	        
                identity[i][j] = 0;
	    }
	
	}
    
    
    }


}


/*
 *
 * Implamentation of a transpose method for a matrix of undefined size
 * 
 *
 * */
template<unsigned R, unsigned C>
void transpose(double (&original)[R][C], double (&transposed)[C][R])
{


     for(int i = 0; i < R; i++){
         for(int j = 0; j < C; j++){
             transposed[j][i] = original[i][j];}
     }


}


/*
 * dot product
 *
 *
 * */
double dot(double* vectorOne, double* vectorTwo, int len){

    double dotProduct;
    for(int i = 0; i < len; i++){
    
        dotProduct += vectorOne[i]*vectorTwo[i];
    }

return dotProduct;
}


/*
 * scaler
 *
 **/
//template<int R>
constexpr void scale(double* vector, int len,  double scaler){

   //double res[R];	
   for(int i = 0; i < len; i++){
       vector[i] *= scaler;
   }

}

/*
 * subtract vector
 *
 * */
//template<int R, int C>
constexpr void subtractVector(double* vectorOne, double* vectorTwo, int len){

    for(int i = 0; i < len; i++){
    
        vectorOne[i] -= vectorTwo[i];
    
    }

}



/*
 *
 * method for extracting a specific row as a vector
 *
 * */
template<int R, int C>
void extractRow(int rowIndex, double (&original)[R][C], double rowVector[C])
{

	for(int i = 0; i < R; i++){
	    for(int j = 0; j < C; j++){
	        if(i+1 == rowIndex) rowVector[j] = original[i][j];   
	    }
	}

}



/*
 *
 * method for replacing a specific row with a vector
 *
 * */
template<int R, int C>
void replaceRow(int rowIndex, double (&original)[R][C], double rowVector[C])
{

        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if(i+1 == rowIndex)  original[i][j] = rowVector[j];
            }
        }

}



/*
 *
 * method for extracting a specific column as a vector
 *
 * */
template<int R, int C>
void extractColumn(int columnIndex, double (&original)[R][C], double columnVector[R])
{

        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if(j+1 == columnIndex) columnVector[i] = original[i][j];
            }
        }

}



/*
 *
 * method for replacing a specific column with a vector
 *
 * */
template<int R, int C>
void replaceColumn(int columnIndex, double (&original)[R][C], double columnVector[R])
{

        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if(j+1 == columnIndex) original[i][j] = columnVector[i];
            }
        }

}




/*
 * 
 * method to swap rows of a matrix
 *
 *
 * */
template<unsigned R, unsigned C>
void swapRows(int rowOne, int rowTwo, double (&original)[R][C], double (&swapped)[R][C])
{
    double tempRow1[C];
    double tempRow2[C];
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
	    if(i+1 == rowOne) tempRow1[j] = original[i][j];
	    if(i+1 == rowTwo) tempRow2[j] = original[i][j];

	    else{swapped[i][j] = original[i][j];}
	}
    }
    

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(i+1 == rowOne) swapped[i][j] = tempRow2[j];
            if(i+1 == rowTwo) swapped[i][j] = tempRow1[j];
        }
    }
}


/*
 *
 * Implamentation of matrix multiplication methods
 *
 * */
template<int M, int N, int P>
void matrixMultiplication(double (&matrixOne)[M][N], double (&matrixTwo)[N][P], double (&result)[M][P])
{

    double product;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < P; j++){
            product = 0;
            for(int v = 0; v < N; v++){

            product += matrixOne[i][v] * matrixTwo[v][j];
                }

        result[i][j] = product;}

    }

}

/*
 * 
 * Implamentation of Matrix Vector Multiplication
 *
 *
 *
 * */
template<int M, int N>
void matrixVectorMultiplication(double (&matrix)[M][N], double ($vector)[N], double ($result)[M])
{

    for(int i = 0; i < M; i++){
        double product = 0;
        for(int j = 0; j < N; j++){
           
                product += matrix[i][j] * $vector[i];

              
            }
                           
        $result[i] = product;
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
     
        

	std::cout << absoluteDouble(input[rowPivot][columnPivot]) << ' ';
	
	
	if(absoluteDouble(input[rowPivot][columnPivot]) > maxAbsolute)
	    
	    maxAbsolute = input[rowPivot][columnPivot];
	    std::cout << " MAX VALUE = " << maxAbsolute << '\n';
	    

	rowPivot++;
	columnPivot++;
	
//	std::cout << '\n';
    }



}


/*
 *
 * Implamention of determinant calculation method
 *
 *
 * */
constexpr double det2by2(double matrix2x2[2][2]){

        double result =  (matrix2x2[0][0] * matrix2x2[1][1]) - (matrix2x2[0][1] * matrix2x2[1][0]);
	
	return result;}


template<unsigned R, unsigned C>
double determinant(double (&matrix)[R][C])
{

    

    //initializes return value
    double finResult;

    //initialize 2x2 submatrix
    double two[2][2];


    //for some reason I was not able
    //to get the first column of the
    //first submatrix without this
    bool firstFlag = true;



    //really inneficient
    //basically runs through
    //the whole matrix once per
    //submatrix and focuses on
    //the part we're interested in
   
    for(int v = 0; v < 3; v++){

        bool oddVflag = false;
        for(int i = 0; i < R; i++){
	    
	    bool twoColumn = 0;
            for(int j = 0; j < C; j++){
		           
	        if(i != 0 && j != v){

		    if(firstFlag == true){
			    two[i-1][0] = matrix[i][j];
			    two[i][0] = matrix[i+1][j];
		    } 

		    else{
			    two[i-1][twoColumn] = matrix[i][j];
			    firstFlag = false;
		    }

		    firstFlag = false;

	         }
     
		 twoColumn = 1;
	         
	     }		    
	    	 
	    
	}
  

	double det = det2by2(two);


	
        if(v % 2) oddVflag = true;


	if(oddVflag == false){
	
	   finResult += matrix[0][v]  *  det;
	}

	else{
	
	   finResult -= matrix[0][v] * det;
	}

    }

   
    
    return finResult;
}


/*
 * 
 *
 * Implamentation of the Cross Product
 *
 *
 * */


template <int len>
void cross( double (&vectorOne)[len], double (&vectorTwo)[len], double (&output)[len]){

        std::cout << "vector one is ";
	printVector(vectorOne);
	std::cout << '\n';

	std::cout << "vector two is ";
	printVector(vectorTwo);
	std::cout << '\n';

	for(int i = 0; i < len; i++){

	    output[i] = absoluteDouble(vectorOne[absoluteInt(i - len)]) + vectorTwo[i]; 
	
	};


	std::cout << "output vector is "; 
	printVector(output);
	std::cout << '\n';

}


#endif
