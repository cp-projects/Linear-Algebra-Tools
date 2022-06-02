#pragma once

matrix_t Givens(int p, int q){

   p--;
   q--;

   this->Round();

   if(m_self_matrix[p][q] == 0)
      return *(this);

   //std::cout << "(" << p+1 << " , " << q+1 << ")" << '\n';

   numeric_type a = m_self_matrix[q][q];
   //std::cout << "\n\n\n" << a << "\n\n\n";

   numeric_type b = m_self_matrix[p][q];
   //std::cout << "\n\n\n" << b << "\n\n\n";

   cap::vector col = cap::vector<numeric_type, 2>({a,b});
   numeric_type r = col.magnitude();
   //std::cout << "\n\n\n" << r << "\n\n\n";

   /*
   numeric_type c,s,t;
   if(b == 0){
       c = 1;
       s = 0;
   }

   else if(std::abs(b) > std::abs(a)){
       t = a/b;
       s = 1.0/(std::sqrt(1.0 + std::pow(r,2)));
       c = s*t;
   }

   else{
   
       t = b/a;
       c = 1.0/(std::sqrt(1.0 + std::pow(r,2)));
       s = c*t;
   }*/


   
   //std::cout << "\n\n\n" << "R = " << r << "\n\n\n";

   numeric_type c  = a/r;
   //std::cout << "\n\n\n" << "C = " << c << "\n\n\n";

   numeric_type s  = -b/r;
   //std::cout << "\n\n\n" << "S = " << s << "\n\n\n";
   
   matrix_t G = cap::matrix<numeric_type, Rows, Columns>();

   G.Identity();

   G[p][p] = c;
   G[q][q] = c;

   G[p][q] = s;
   G[q][p] = -s;

   //std::cout << "\n\n\n";
   //G.print();
   //std::cout << "\n\n\n";

   matrix_t temp = G;
   temp.Transpose();

   //std::cout << "\n\n\n";
   //temp.print();
   //std::cout << "\n\n\n";


   //temp = this->matrixMultiplication(temp);
   G = G * *(this);

   //G = G * temp;

  // G[p][q] = 0;

   m_old_givens.emplace_back(p,q);
   
   // for(int i = 0; i < m_old_givens.size(); i++)
           //G[m_old_givens.at(i).first, m_old_givens.at(i).second] = 0;

   //std::cout << "\n\n\n";
   //G.print();
   //std::cout << "\n\n\n";

   

   return G;

}


void Hessenberg(){
    matrix_t temp = *(this);
    //matrix_t temp = cap::matrix<numeric_type, Rows, Columns>();
    
    this->Round();

    for(int i = 1; i <= Rows; i++)
        for(int j = 1; j <= Columns; j++)
	    if(i > j+1){
	        temp = this->Givens(i,j);
		temp.Round();
		*(this) = temp;
		std::cout << "(" << i << " , " << j << ")" << '\n';
	      }
           }



void QR(){

   if(Rows != Columns)
	   throw mustBeSquare();

   //if(this->Determinant() == 0)
	   //throw mustBeLinearlyIndependent();
	   
   this->Hessenberg();
   this->Round();

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

	       Q.Round();
	       R.Round();

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

}

