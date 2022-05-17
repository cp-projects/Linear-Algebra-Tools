#pragma once


numeric_type determinant2x2(cap::matrix<numeric_type,2,2> &matrix2x2){
        numeric_type result =  (matrix2x2[0][0] * matrix2x2[1][1]) - (matrix2x2[0][1] * matrix2x2[1][0]);
        return result;
      }


numeric_type Determinant(){

    if(Rows != Columns)
	    throw mustBeSquare();


    else if(Rows == 2 && Columns == 2) 
	    return determinant2x2(*((cap::matrix<numeric_type,2,2>*) this));
    

    numeric_type finResult = 0;
    cap::matrix two = cap::matrix<numeric_type, 2, 2>();
    bool firstFlag = true;
    for(int v = 0; v < 3; v++){
        bool oddVflag = false;
        for(int i = 0; i < Rows; i++){
            bool twoColumn = 0;
            for(int j = 0; j < Columns; j++){
                if(i != 0 && j != v){
                    if(firstFlag == true){
                            two[i-1][0] = m_self_matrix[i][j];
                            two[i][0] = m_self_matrix[i+1][j];
                     }
                    else{
                            two[i-1][twoColumn] = m_self_matrix[i][j];
                            firstFlag = false;
                         }
                    firstFlag = false;
                 }
                 twoColumn = 1;
               } //end loop
            }//end loop
        numeric_type det = determinant2x2(two);
        if(v % 2)
                oddVflag = true;
        if(oddVflag == false)
           finResult += m_self_matrix[0][v]  *  det;
        else
           finResult -= m_self_matrix[0][v] * det;
    }//end loop
    return finResult;
}

