#pragma once

matrix_t invert2x2(){

   if(Rows != 2 || Columns != 2)
	   throw wrongDimentions();

   numeric_type scalar = 1/determinant2x2(*((cap::matrix<numeric_type,2,2>*)this));
   
   numeric_type temp = m_self_matrix[0][0];
   m_self_matrix[0][0] = m_self_matrix[1][1];
   m_self_matrix[1][1] = temp;
   
   m_self_matrix[0][1] = -m_self_matrix[0][1];
   m_self_matrix[1][0] = -m_self_matrix[1][0];

   this->scale(scalar);
   this->pos_zero();

   return  m_self_matrix;
}



matrix_t invert(){

    if(Rows != Columns)
	    throw mustBeSquare();

    if(!Determinant())
	    throw mustBeLinearlyIndependent();

    if(Rows == 2 && Columns == 2)
            return this->invert2x2();


    matrix_t result;
    result.Identity();

    int leading_col = 0;
    for(int leading_row = 0; leading_row < Rows; leading_row++){
       for(int i = 0; i < Rows; i++){                                                      

           numeric_type leading_val = m_self_matrix[leading_row][leading_col];            

           //if(leading_val == 0)
              // return result;

	   //if(leading_val > 100)
	      // leading_val/=1000;


           row_vector_t one = extractRow(leading_row+1);
	   row_vector_t resOne = result.extractRow(leading_row+1);

           if(leading_val != 1){
               scaleRow(leading_row+1, 1/leading_val);
               resOne*(1/leading_val);
	       result.replaceRow(leading_row+1, resOne);
	     }

           if(i != leading_row && m_self_matrix[i][leading_col] != 0){
	       addScaledR(leading_row+1, i+1 , -m_self_matrix[i][leading_col]);
	       row_vector_t resTwo = result.extractRow(i+1);
	       resTwo * -m_self_matrix[i][leading_col];
	       result.replaceRow(i+1, resTwo);
             }

         }

         if(leading_col < Columns)
                 leading_col++;
               }


    this->pos_zero();
    return result;
}


