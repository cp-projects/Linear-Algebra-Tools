#pragma once

template <size_t Other_Col>
matrix(numeric_type &initializer[Rows][Other_Col])
    : m_row_len(Rows), m_col_len(Other_Col){
        for(size_t i = 0; i < Rows; i++)
            for(size_t j = 0; j < Other_Col; j++)
                m_result[i][j] = initializer[i][j];               
              }
