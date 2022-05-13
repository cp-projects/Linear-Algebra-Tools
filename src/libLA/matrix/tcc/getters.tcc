#pragma once

//retreiving values
            void get_row_len(){
                std::cout << Rows;
               }

            matrix_t Result(){
                 return matrix(m_result);
              }


	    void print(){
               for(size_t i = 0; i < m_row_len; i++){
                    for(size_t j = 0; j < m_col_len; j++)
                         std::cout << m_self_matrix[i][j] << " ";
               std::cout << '\n';}
              }

