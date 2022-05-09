#pragma once

             
             
             /*
            template <size_t Other_Col>
            matrix(matrix_t::m_other_t &initializer)
                     : m_row_len(Rows), m_col_len(Columns), m_start_ptr((val_ptr_t)m_self_matrix){
                     for(size_t i = 0; i < Rows; i++)
                         for(size_t j = 0; j < Column; j++)
                             m_self_matrix[i][j] = initializer[i][j];

                      for(size_t i = 0; i < Rows; i++)
                          for(size_t j = 0; j < Other_Col; j++)
                             m_result[i][j] = initializer.o_result[i][j];
                                       }          */

            //template <size_t Other_Col>
            //cap::matrix<double, 3, 3>::matrix(cap::matrix<double, 3, 3>::m_other_t<4>::result_t&

           /* matrix.hpp:203:25: error: no matching function for call to
            ‘cap::matrix<double, 3, 3>::matrix(cap::matrix<double, 3, 3>::m_other_t<4>::result_t&)’
  203 |                  return matrix(ret_val);
      |                         ^~~~~~~~~~~~~~~
             matrix.hpp:68:13: note: candidate:

             ‘template<long unsigned int Other_Col> cap::matrix<numeric_type, Rows, Columns>::matrix(typename cap::matrix<numeric_type, Columns, Other_Col>::m_other_t<Other_Col>::result_t&) [with long unsigned int Other_Col = Other_Col; numeric_type = double; long unsigned int Rows = 3; long unsigned int Columns = 3]*/
/*
            matrix(typename cap::matrix<numeric_type, Rows, Columns>::m_other_t<Other_Col>::result_t &initializer)
                : m_row_len(Rows), m_col_len(Columns), m_start_ptr((val_ptr_t)m_self_matrix){

                    for(size_t i = 0; i < Rows; i++)
                         for(size_t j = 0; j < Columns; j++)
                             for(size_t k = 0; k < Other_Col; k++)
                                 m_self_matrix[i][j] = initializer[i][k];

                }
*/
