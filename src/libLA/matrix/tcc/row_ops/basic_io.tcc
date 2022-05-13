#pragma once


row_vector_t extractRow(int rowIndex){
	
	if(rowIndex > Rows)
		throw out_of_bounds();

        for(int i = 0; i < Rows; i++)
            for(int j = 0; j < Columns; j++)
                if(i+1 == rowIndex)
		       	m_row_result[j] = m_self_matrix[i][j];

	return m_row_result;
      }



void replaceRow(int rowIndex, row_vector_t &insertVector){

	if(rowIndex > Rows)
                throw out_of_bounds();

        for(int i = 0; i < Rows; i++)
            for(int j = 0; j < Columns; j++)
                if(i+1 == rowIndex)
		    m_self_matrix[i][j] = insertVector[j];
                  }



col_vector_t extractColumn(int columnIndex){

	if(columnIndex > Columns)
                throw out_of_bounds();

        for(int i = 0; i < Rows; i++)
            for(int j = 0; j < Columns; j++)
                if(j+1 == columnIndex)
		       	m_col_result[i] = m_self_matrix[i][j];
        
	return m_col_result;
      }



void replaceColumn(int columnIndex, col_vector_t &insertVector){
	if(columnIndex > Columns)
                throw out_of_bounds();

        for(int i = 0; i < Rows; i++)
            for(int j = 0; j < Columns; j++)
                if(j+1 == columnIndex)
		       	m_self_matrix[i][j] = insertVector[i];
                      }



matrix_t swapRows(int rowIndex1, int rowIndex2){
    
    static matrix_t swapped;
    row_arr_t tempRow1;
    row_arr_t tempRow2;

    for(int i = 0; i < Rows; i++)
        for(int j = 0; j < Columns; j++){
            if(i+1 == rowIndex1)
		    tempRow1[j] = m_self_matrix[i][j];
            if(i+1 == rowIndex2)
		    tempRow2[j] = m_self_matrix[i][j];
            else
		    swapped[i][j] = m_self_matrix[i][j];
          }    
    for(int i = 0; i < Rows; i++)
        for(int j = 0; j < Columns; j++){
            if(i+1 == rowIndex1) 
		    swapped[i][j] = tempRow2[j];
            if(i+1 == rowIndex2)
		    swapped[i][j] = tempRow1[j];
                  }    
 return swapped;}



 matrix_t swapColumns(int colIndex1, int colIndex2){

    static matrix_t swapped;
    col_arr_t tempCol1;
    col_arr_t tempCol2;

    for(int i = 0; i < Rows; i++)
        for(int j = 0; j < Columns; j++){
            if(j+1 == colIndex1)
                    tempCol1[i] = m_self_matrix[i][j];
            if(j+1 == colIndex2)
                    tempCol2[i] = m_self_matrix[i][j];
            else
                    swapped[i][j] = m_self_matrix[i][j];
          }
    for(int i = 0; i < Rows; i++)
        for(int j = 0; j < Columns; j++){
            if(j+1 == colIndex1)
                    swapped[i][j] = tempCol2[i];
            if(j+1 == colIndex2)
                    swapped[i][j] = tempCol1[i];
                  }
 return swapped;}
