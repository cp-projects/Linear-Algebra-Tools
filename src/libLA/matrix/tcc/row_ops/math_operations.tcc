#pragma once


/*
 *
 *  Scale
 *
 * */

row_vector_t scaleRow(int rowIndex, numeric_type scalar){
	
	if(rowIndex > Rows)
		throw out_of_bounds();

        for(int i = 0; i < Rows; i++)
            for(int j = 0; j < Columns; j++)
                if(i+1 == rowIndex){
		       	m_row_result[j] = scalar * m_self_matrix[i][j];
			m_self_matrix[i][j] = scalar * m_self_matrix[i][j];
		      }

	return m_row_result;
      }

  

col_vector_t scaleColumn(int columnIndex, numeric_type scalar){

	if(columnIndex > Columns)
                throw out_of_bounds();

        for(int i = 0; i < Rows; i++)
            for(int j = 0; j < Columns; j++)
                if(j+1 == columnIndex){
		       	m_col_result[i] = scalar * m_self_matrix[i][j];
                        m_self_matrix[i][j] = scalar * m_self_matrix[i][j];
		       }
        
	return m_col_result;
      }


/*
 * Add
 *
 * */

row_vector_t addRows(int rowIndex1, int rowIndex2){
    
    row_arr_t tempRow1;
    row_arr_t tempRow2;

    for(int i = 0; i < Rows; i++)
        for(int j = 0; j < Columns; j++){
            if(i+1 == rowIndex1)
		    tempRow1[j] = m_self_matrix[i][j];
            if(i+1 == rowIndex2)
		    tempRow2[j] = m_self_matrix[i][j];
          }

    for(int i = 0; i < Rows; i++)
        for(int j = 0; j < Columns; j++)
            if(i+1 == rowIndex2){
		    m_row_result[j] = tempRow1[j] + tempRow2[j];
		    m_self_matrix[i][j] = tempRow1[j] + tempRow2[j];
                  }    
 return m_row_result;}



col_vector_t addColumns(int colIndex1, int colIndex2){

    col_arr_t tempCol1;
    col_arr_t tempCol2;

    for(int i = 0; i < Rows; i++)
        for(int j = 0; j < Columns; j++){
            if(j+1 == colIndex1)
                    tempCol1[i] = m_self_matrix[i][j];
            if(j+1 == colIndex2)
                    tempCol2[i] = m_self_matrix[i][j];
          }

    for(int i = 0; i < Rows; i++)
        for(int j = 0; j < Columns; j++)
            if(j+1 == colIndex2){
                    m_col_result[j] = tempCol1[i] + tempCol2[i];
		    m_self_matrix[i][j] = tempCol1[i] + tempCol2[i];
                  }
 return m_col_result;}



/*
 * Add Scaled
 *
 * */

row_vector_t addScaledR(int rowIndex1, int rowIndex2, numeric_type scalar){

    row_arr_t tempRow1;
    row_arr_t tempRow2;

    for(int i = 0; i < Rows; i++)
        for(int j = 0; j < Columns; j++){
            if(i+1 == rowIndex1)
                    tempRow1[j] = m_self_matrix[i][j];
            if(i+1 == rowIndex2)
                    tempRow2[j] = m_self_matrix[i][j];
          }

    for(int i = 0; i < Rows; i++)
        for(int j = 0; j < Columns; j++)
            if(i+1 == rowIndex2){
                    m_row_result[j] = scalar*tempRow1[j] + tempRow2[j];
                    m_self_matrix[i][j] = scalar*tempRow1[j] + tempRow2[j];
                  }
 return m_row_result;}



col_vector_t addScaledC(int colIndex1, int colIndex2, numeric_type scalar){

    col_arr_t tempCol1;
    col_arr_t tempCol2;

    for(int i = 0; i < Rows; i++)
        for(int j = 0; j < Columns; j++){
            if(j+1 == colIndex1)
                    tempCol1[i] = m_self_matrix[i][j];
            if(j+1 == colIndex2)
		    tempCol2[i] = m_self_matrix[i][j];
          }

    for(int i = 0; i < Rows; i++)
        for(int j = 0; j < Columns; j++)
            if(j+1 == colIndex2){
                    m_col_result[j] = scalar*tempCol1[i] + tempCol2[i];
                    m_self_matrix[i][j] = scalar*tempCol1[i] + tempCol2[i];
                  }
 return m_col_result;}
