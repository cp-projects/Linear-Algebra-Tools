#pragma once

//retreiving values
            numeric_type get_row_len(){
                std::cout << Rows;
		return Rows;
               }

            numeric_type get_col_len(){
	        std::cout << Columns;
		return Columns;
	       }

            void print_dimentions(){
	        std::cout << "Rows: " << Rows << " ";
		std::cout  << "Columns: " << Columns << std::endl;
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

