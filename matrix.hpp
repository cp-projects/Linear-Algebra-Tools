#ifndef HEADER_FILE
#define HEADER_FILE






#include <iostream>
template<int R, int C>
void printMatrix(double(&matrix)[R][C])
{

	std::cout << '\n';
	std::cout << '\n';

         for(int i = 0; i < R; i++)
            {for(int j = 0; j < C; j++){
                std::cout << (char) matrix[i][j]  << ' ';}
            std::cout << '\n'; }

        std::cout << '\n';
        std::cout << '\n';
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
void determinant(double (&matrix)[R][C])
{

  

    double two[2][2];


    bool firstFlag = true;

    for(int v = 0; v < 3; v++){

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

            
 		    
	    	 
	    std::cout << '\n';
	    
	}
  
        std::cout << (char) matrix[0][v] << ' ';	
	printMatrix(two);
       	std::cout << '\n';
    }



}




#endif
