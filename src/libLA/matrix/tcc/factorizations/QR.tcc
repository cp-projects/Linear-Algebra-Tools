#pragma once

#define erase_debug_Givens
#ifndef erase_debug_Givens
#define LOG1() std::cout << "(" << p+1 << " , " << q+1 << ")" << '\n';
#define LOG2(x) std::cout << "\n\n\n" << x << "\n\n\n";
#define LOG3(x,y) std::cout << "\n\n\n" << x << y << "\n\n\n";
#define LOG4(x) std::cout << "\n\n\n"; x.print(); std::cout << "\n\n\n";
#else
#define LOG1()
#define LOG2(x)
#define LOG3(x,y)
#define LOG4(x)
#endif

#define erase_debug_Hess
#ifndef erase_debug_Hess
#define LOG5() std::cout << "(" << i << " , " << j << ")" << '\n';
#else
#define LOG5()
#endif

#define erase_debug_QR
#ifndef erase_debug_QR
#define LOG6() std::cout << " (" << i+1 << ',' << j+1 << ')' << '\n';
#define LOG7(x) x.print(); std::cout << "\n\n\n\n";
#define LOG8(x) std::cout << x << "\n\n";
#else
#define LOG6()
#define LOG7(x)
#define LOG8(x)
#endif

matrix_t Givens(int p, int q){

   p--;                                                        
   q--;                                                                     LOG1()

   this->Round();

   if(m_self_matrix[p][q] == 0)                                                     
      return *(this);       

   numeric_type a = m_self_matrix[q][q];                                    LOG2(a)

   numeric_type b = m_self_matrix[p][q];                                    LOG2(b)

   cap::vector col = cap::vector<numeric_type, 2>({a,b});
   numeric_type r = col.magnitude();                                        LOG2(r)


   numeric_type c  = a/r;                                                   LOG3("C = ",c)

   numeric_type s  = -b/r;                                                  LOG3("S = ", s)
   
   matrix_t G = cap::matrix<numeric_type, Rows, Columns>();

   G.Identity();

   G[p][p] = c;
   G[q][q] = c;

   G[p][q] = s;
   G[q][p] = -s;                                                            LOG4(G)

   matrix_t temp = G;
   temp.Transpose();                                                        LOG4(temp)

   G = G * *(this);

   m_old_givens.emplace_back(p,q);
  
   return G;

}


void Hessenberg(){
    matrix_t temp = *(this);    
    temp.Round();

    for(int i = 1; i <= Rows; i++)
        for(int j = 1; j <= Columns; j++)
	    if(i > j+1){
	        temp = this->Givens(i,j);
		temp.Round();
		*(this) = temp;                                               LOG5()
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

	       Q.Round(); R.Round();                                            LOG6()          
	       col_vector_t qi = Q.extractColumn(j+1);                          LOG7(qi)
               const numeric_type scalar_dot = ai_orth*q1;                      LOG8(scalar_dot)
	       
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

