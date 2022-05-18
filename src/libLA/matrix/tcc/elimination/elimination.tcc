#pragma once

#include "logging.mac"

void rref(){

   int leading_col = 0;
   for(int leading_row = 0; leading_row < Rows; leading_row++){
       for(int i = 0; i < Rows; i++){                                                      LOGSELF()
       
           numeric_type leading_val = m_self_matrix[leading_row][leading_col];             LOGLEAD(leading_val)
       
           if(leading_val == 0)
	       return;

           row_vector_t one = extractRow(leading_row+1);                                   LOGVEC(one)

	   for(int j = 2; leading_row+j < Rows+1; j++){
	       row_vector_t two = extractRow(leading_row+j);                               LOGVEC(two)
	       if(one == two)
	           two.fill(0);
	           replaceRow(leading_row+j, two);
	          }

           if(leading_val != 1)
	       scaleRow(leading_row+1, 1.0/leading_val);

           if(i != leading_row && m_self_matrix[i][leading_col] != 0)
	       addScaledR(leading_row+1, i+1 , -m_self_matrix[i][leading_col]);
             }

         if(leading_col < Columns)
		 leading_col++;
               }


    this->pos_zero();
}


void ref(){

   int leading_col = 0;
   for(int leading_row = 0; leading_row < Rows; leading_row++){
       for(int i = 0; i < Rows; i++){                                                        LOGSELF()


           numeric_type leading_val = m_self_matrix[leading_row][leading_col];               LOGLEAD(leading_val)

           if(leading_val == 0)
               return;

           row_vector_t one = extractRow(leading_row+1);                                     LOGVEC(one)

           for(int j = 2; leading_row+j < Rows+1; j++){
               row_vector_t two = extractRow(leading_row+j);                                 LOGVEC(two)
               if(one == two)
                   two.fill(0);
                   replaceRow(leading_row+j, two);
                  }

           if(i != leading_row && m_self_matrix[i][leading_col] != 0)
               addScaledR(leading_row+1, i+1 , -(m_self_matrix[i][leading_col])/leading_val);
             }

         if(leading_col < Columns)
                 leading_col++;
               }


    this->pos_zero();
}

