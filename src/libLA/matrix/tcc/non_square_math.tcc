#pragma once


                template <size_t Other_Col>
                typename cap::matrix<numeric_type, Rows, Other_Col>::m_other_t<Columns>::result_t matrixMultiplication(cap::matrix<numeric_type, Columns, Other_Col> &other){
                    if(Columns != Columns)
                           throw wrongDimentions();

                    static m_other_t m_other = m_other_t<Other_Col>(other);
                    for(int i = 0; i < Rows; i++)
                        for(int j = 0; j < Other_Col; j++)
                            for(int v = 0; v < Columns; v++)
                                m_other.o_result[i][j] += m_self_matrix[i][v] * other[v][j];

                    typename cap::matrix<numeric_type,Rows,Other_Col>::m_other_t<Other_Col>::result_t ret_val = m_other.Result();
                    return Result(ret_val);
                               }

