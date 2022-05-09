#pragma once          


          matrix()
                : m_row_len(Rows), m_col_len(Columns), m_start_ptr((val_ptr_t)m_self_matrix){
                    Fill(0);
                  }

            matrix(dbl_arr_t initializer)
                : m_row_len(Rows), m_col_len(Columns), m_start_ptr((val_ptr_t)m_self_matrix){
                    for(size_t i = 0; i < Rows; i++){
                        for(size_t j = 0; j < Columns; j++){
                                m_self_matrix[i][j] = initializer[i][j];
                                m_result[i][j] = 0;
                               }}
                              }

            matrix(dbl_init_t initializer)
                    : m_row_len(Rows), m_col_len(Columns), m_start_ptr((val_ptr_t)m_self_matrix){
                    int i = 0;
                    for(dbl_init_Iterator itr = initializer.begin(); itr < initializer.end(); itr++){
                        int j = 0;
                        for(init_Iterator jtr = itr->begin(); jtr != itr->end(); jtr++){
                                numeric_type *ptr1 = const_cast <numeric_type*>(jtr);
                                m_self_matrix[i][j] = *(ptr1);
                                m_result[i][j] = 0;
                               j++;}
                        i++;}
                              }


             ~matrix(){}
