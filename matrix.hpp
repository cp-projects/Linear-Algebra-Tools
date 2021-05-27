#ifndef HEADER_FILE
#define HEADER_FILE



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
	    	 
	    //std::cout << '\n';
	    
	}
  
/*
        std::cout << matrix[0][v] << ' ';	
	printMatrix(two);
       	std::cout << '\n';
*/
	double det = det2by2(two);
/*
	std::cout << det << '\n';
	std::cout << '\n';
	std::cout << '\n';
*/


	
        if(v % 2) oddVflag = true;


	if(oddVflag == false){
	
	   finResult += matrix[0][v]  *  det;
	}

	else{
	
	   finResult -= matrix[0][v] * det;
	}

	

	//std::cout << "   oddVflag is    " << oddVflag << "    det is   " << det << '\n';

    }

   // std::cout << finResult << '\n';
    
    return finResult;
}




#endif
