#pragma once

//fillers/setters
           void Fill(numeric_type value){
                for(size_t i = 0; i < Rows; i++){
                        for(size_t j = 0; j < Columns; j++){
                                m_self_matrix[i][j] = value;
                                m_result[i][j] = 0;
                               }}
                              }

           void Random(){
                 for(size_t i = 0; i < Rows; i++)
                     for(size_t j = 0; j < Columns; j++)
                         m_self_matrix[i][j] = rand() % 70;
                       }


           cap::matrix<numeric_type, Columns, Rows> transpose_ns(){
                static numeric_type transposed[Columns][Rows];
	        for(int i = 0; i < Rows; i++)
                   for(int j = 0; j < Columns; j++)
                       transposed[j][i] = m_self_matrix[i][j];

                return transposed;
	      }
