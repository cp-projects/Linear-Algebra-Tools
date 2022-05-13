#pragma once
               
               /*
		*  Matrix Multiplication
		*
		* */

               matrix_t matrixMultiplication(matrix_t &other){
                  if(Rows != Columns || other.m_row_len != other.m_col_len || Rows != other.m_row_len)
                          throw mustBeSquare();

                  numeric_type temp;
                  for(size_t v = 0; v < Rows; v++){
                      for(size_t i = 0; i < Rows; i++){

                  temp = m_self_matrix[i][v];
                  for(size_t j = 0; j < Rows; j++)
                    m_result[i][j] += temp * other[v][j];
                     }
                    }
                 return m_result;
                  }

               matrix_t operator*(matrix_t &other){
                   return matrixMultiplication(other);
                  }


               
               /*
		*  
		*  Matrix Addition
		*
		* */

               matrix_t matrixAddition(matrix_t &other){
                   if(Rows != Columns || other.m_row_len != other.m_col_len || Rows != other.m_row_len)
                          throw mustBeSquare();
                   for(int i = 0; i < Rows; i++)
                       for(int j = 0; j < Columns; j++)
                            m_result[i][j] = m_self_matrix[i][j] + other[i][j];
                   return m_result;       
	          }

               matrix_t operator+(matrix_t &other){
                   return matrixAddition(other);
               }


              /*
	       *
	       * Matrix Subtraction
	       *
	       *
	       * */

              matrix_t matrixSubtraction(matrix_t &other){
                   if(Rows != Columns || other.m_row_len != other.m_col_len || Rows != other.m_row_len)
                          throw mustBeSquare();
                   for(int i = 0; i < Rows; i++)
                       for(int j = 0; j < Columns; j++)
                            m_result[i][j] = m_self_matrix[i][j] - other[i][j];
                   return m_result;
                  }

               matrix_t operator-(matrix_t &other){
                   return matrixSubtraction(other);
               }



              /*
	       *
	       * Scale
	       *
	       * */


               void scale(numeric_type scalar){
                   for(int i = 0; i < Rows; i++)
                       for(int j = 0; j < Columns; j++)
                            m_self_matrix[i][j] = m_self_matrix[i][j]*scalar;
                          }

               void operator*(numeric_type scalar){
	           scale(scalar);
	          }


