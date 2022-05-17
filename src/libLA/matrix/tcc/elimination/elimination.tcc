#pragma once

void gauss(){

   int leading_col = 0;
   for(int leading_row = 0; leading_row < Rows; leading_row++){
       for(int i = 0; i < Rows; i++){
       
           numeric_type leading_val = m_self_matrix[leading_row][leading_col];
           std::cout << "Leading Val is " << leading_val << '\n';
       
           if(leading_val == 0)
	       return;

           row_vector_t one = extractRow(leading_row+1);
           one.print();
           std::cout << "\n\n\n\n";

	   for(int j = 2; leading_row+j < Rows+1; j++){
	       row_vector_t two = extractRow(leading_row+j);
	       two.print();
	       std::cout << "\n\n\n\n";
	       if(one == two)
	           two.fill(0);
	           replaceRow(leading_row+j, two);
	          }

           if(leading_val != 1)
	       scaleRow(leading_row+1, 1/leading_val);

           if(i != leading_row && m_self_matrix[i][leading_col] != 0)
	       addScaledR(leading_row+1, i+1 , -m_self_matrix[i][leading_col]);
             }

         if(leading_col < Columns)
		 leading_col++;
               }


    this->pos_zero();
}
