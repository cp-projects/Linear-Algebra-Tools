#pragma once

           //getter and setter
           numeric_type* operator[](size_t index){
               return m_self_matrix[index];
              }

           numeric_type at(int i, int j){
	       return m_self_matrix[i][j];
	      }
           
           //comparisons
	   bool Equals(matrix_t &other){
	       
	       if(Rows != Columns)
		       return false;
		   
	       bool equal_flag = true;
	       for(int i = 0; i < Rows; i++)
	           for(int j = 0; j < Columns; j++)
		       if(this->at(i,j) != other.at(i,j))
		           equal_flag = false;

	       return equal_flag;
	     }



           bool operator==(matrix_t &other){
	       return Equals(other);
	     }


           //comparisons
           bool notEquals(matrix_t &other){

               if(Rows != Columns)
                       return true;

               for(int i = 0; i < Rows; i++)
                   for(int j = 0; j < Columns; j++)
                       if(m_self_matrix[i][j] != other[i][j])
                           return true;

               return false;
             }



           bool operator!=(matrix_t &other){
               return notEquals(other);
           }





