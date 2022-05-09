#pragma once          


            template <size_t Other_Col>
            struct m_other_t : cap::matrix<numeric_type, Columns, Other_Col>{

                public:
                         //typedef numeric_type row_arr_t[Columns];
                        //typedef numeric_type col_arr_t[Other_Col];
                        //typedef numeric_type dbl_arr_t[Columns][Other_Col];
                        //typedef numeric_type* val_ptr_t;

                        typedef numeric_type res_arr_t[Rows][Other_Col];

                        typedef cap::matrix<numeric_type, Columns, Other_Col> other_t;
                        typedef cap::matrix<numeric_type, Rows, Other_Col> result_t;



                public:
                        m_other_t()
                                : o_row_len(Columns), o_col_len(Other_Col), o_start_ptr((val_ptr_t)o_self_matrix){
                                        Fill(0);}

                        m_other_t(numeric_type initializer[Columns][Other_Col])
                                : o_row_len(Columns), o_col_len(Other_Col), o_start_ptr((val_ptr_t)o_self_matrix){
                                        for(size_t i = 0; i < Columns; i++)
                                            for(size_t j = 0; j < Other_Col; j++)
                                                o_self_matrix[i][j] = initializer[i][j];

                                        for(size_t i = 0; i < Rows; i++)
                                            for(size_t j = 0; j < Other_Col; j++)
                                                o_result[i][j] = 0;
                                       }


                        m_other_t(other_t &initializer)
                                : o_row_len(Columns), o_col_len(Other_Col), o_start_ptr((val_ptr_t)o_self_matrix){
                                        for(size_t i = 0; i < Columns; i++)
                                            for(size_t j = 0; j < Other_Col; j++)
                                                o_self_matrix[i][j] = initializer[i][j];

                                        for(size_t i = 0; i < Rows; i++)
                                            for(size_t j = 0; j < Other_Col; j++)
                                                o_result[i][j] = 0;
                                       }



                        m_other_t(dbl_init_t initializer)
                                : o_row_len(Columns), o_col_len(Other_Col), o_start_ptr((val_ptr_t)o_self_matrix){
                                    int i = 0;
                                    for(dbl_init_Iterator itr = initializer.begin(); itr < initializer.end(); itr++){
                                        int j = 0;
                                        for(init_Iterator jtr = itr->begin(); jtr != itr->end(); jtr++){
                                            numeric_type *ptr1 = const_cast <numeric_type*>(jtr);
                                            o_self_matrix[i][j] = *(ptr1);
                                            j++;}
                                        i++;}

                                    for(size_t i = 0; i < Rows; i++)
                                        for(size_t j = 0; j < Other_Col; j++)
                                            o_result[i][j] = 0;
                                       }

                        ~m_other_t(){}



                private:
                        numeric_type o_self_matrix[Columns][Other_Col];
                        val_ptr_t o_start_ptr;
                        size_t o_row_len, o_col_len;

                public:
                        result_t o_result;

                public:
                        void Fill(numeric_type value){
                            for(size_t i = 0; i < Columns; i++)
                                for(size_t j = 0; j < Other_Col; j++)
                                    o_self_matrix[i][j] = value;

                            for(size_t i = 0; i < Rows; i++)
                                for(size_t j = 0; j < Other_Col; j++)
                                    o_result[i][j] = 0;

                              }

                         result_t Result(){
                             return o_result;
                            }

			  

			  //#include "other_getters.tcc" //(broken) Result() Print()

                     };

