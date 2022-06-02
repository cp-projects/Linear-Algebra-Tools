#pragma once

void pos_zero(){
    for(int i = 0; i < Rows; i++)
        for(int j = 0; j < Columns; j++)
	    if(m_self_matrix[i][j] == (numeric_type) -0)
		    m_self_matrix[i][j] = (numeric_type)0;
                  }

void Round(){
    for(int i = 0; i < Rows; i++)
        for(int j = 0; j < Columns; j++)
	    if(std::abs(m_self_matrix[i][j]) < 0.000001)
		    m_self_matrix[i][j] = (numeric_type)0;
                  }
