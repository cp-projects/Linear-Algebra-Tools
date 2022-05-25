#pragma once


//twoFactor_t*
void QR(){

   if(Rows != Columns)
	   throw mustBeSquare();

   //if(this->Determinant() == 0)
	   //throw mustBeLinearlyIndependent();

   my_two_factor = new twoFactor_t;

   matrix_t Q = cap::matrix<numeric_type, Rows, Columns>();
   matrix_t R = cap::matrix<numeric_type, Rows, Columns>();

   col_vector_t q1 = this->extractColumn(1);
   numeric_type R_Diag_1 = q1.magnitude();

   q1/q1.magnitude();
   Q.replaceColumn(1,q1);
   R[0][0] = R_Diag_1;

   for(int i = 1; i < Rows; i++){

       col_vector_t ai_orth = this->extractColumn(i+1);
       
       for(int j = 0; j < i; j++){

	       //std::cout << " (" << i+1 << ',' << j+1 << ')' << '\n';
	       col_vector_t qi = Q.extractColumn(j+1);
	       //qi.print(); std::cout << "\n\n\n\n";

               const numeric_type scalar_dot = ai_orth*q1;
	       //std::cout << scalar_dot << "\n\n";
	       R[j][i] = scalar_dot;
               ai_orth -= {scalar_dot,q1};
              }

       numeric_type R_Diag_i = ai_orth.magnitude();
       ai_orth/ai_orth.magnitude();
       Q.replaceColumn(i+1, ai_orth);
       R[i][i] = R_Diag_i;
       
      }
      


   



   my_two_factor->left = new matrix_t;
   my_two_factor->right = new matrix_t;

   *(my_two_factor->left) = Q;
   *(my_two_factor->right) = R;

   //return my_two_factor;

}

