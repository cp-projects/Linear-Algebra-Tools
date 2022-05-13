#pragma once


            void Identity(){
                 if(Rows != Columns)
                         throw mustBeSquare();
                 for(size_t i = 0; i < Rows; i++){
                     for(size_t j = 0; j < Columns; j++){
                         if(i == j)
                                 m_self_matrix[i][j] = 1;
                         else
                                 m_self_matrix[i][j] = 0;  }   }
                               }

             void Transpose(){
                 if(Rows != Columns)
                         throw mustBeSquare();
                 for(size_t i = 0; i < Rows; i++)
                     for(size_t j = i+1; j < Columns; j++){
                        numeric_type temp = m_self_matrix[i][j];
                        m_self_matrix[i][j] = m_self_matrix[j][i];
                        m_self_matrix[j][i] = temp;
                      }
                    }

