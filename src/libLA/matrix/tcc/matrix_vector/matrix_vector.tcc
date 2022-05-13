#pragma once

col_vector_t matrixVectorMultiplication(row_vector_t &vec){

    for(int i = 0; i < Rows; i++){
        numeric_type product = 0;
        for(int j = 0; j < Columns; j++)
                product += m_self_matrix[i][j] * vec[j];      
        m_col_result[i] = product;
       }
    return m_col_result;
   }


col_vector_t operator*(row_vector_t &vec){
    return matrixVectorMultiplication(vec);
   }
