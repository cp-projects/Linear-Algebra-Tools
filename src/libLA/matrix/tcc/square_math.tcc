#pragma once

               void matrixMultiplication(matrix_t &other){
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
                  }

               void operator*(matrix_t &other){
                   matrixMultiplication(other);
                  }





               void matrixAddition(matrix_t &other){
                   if(Rows != Columns || other.m_row_len != other.m_col_len || Rows != other.m_row_len)
                          throw mustBeSquare();
                   for(int i = 0; i < Rows; i++)
                       for(int j = 0; j < Columns; j++)
                            m_result[i][j] = m_self_matrix[i][j] + other[i][j];
                          }

               void operator+(matrix_t &other){
                   matrixAddition(other);
               }

