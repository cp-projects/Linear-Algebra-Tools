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
