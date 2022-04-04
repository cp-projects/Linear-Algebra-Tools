#include "determinant.hpp"

double determinant(double matrix2x2[2][2]){
        double result =  (matrix2x2[0][0] * matrix2x2[1][1]) - (matrix2x2[0][1] * matrix2x2[1][0]);
	return result;
}


template<unsigned R, unsigned C>
double determinant(double (&matrix)[R][C])
{       

    double finResult;
    double two[2][2];
    bool firstFlag = true;
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
               } //end loop
            }//end loop
        double det = determinant(two);
        if(v % 2) 
		oddVflag = true;
        if(oddVflag == false)
           finResult += matrix[0][v]  *  det;
        else
           finResult -= matrix[0][v] * det;
    }//end loop
    return finResult;
}



