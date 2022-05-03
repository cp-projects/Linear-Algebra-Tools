#pragma once

#include "../errorsLA/matrixErrors.hpp"

namespace cap{

template<typename numeric_type, size_t Rows, size_t Columns>
class matrix{
	private:
	    typedef numeric_type row_arr_t[Rows];
	    typedef numeric_type col_arr_t[Columns];
	    typedef numeric_type dbl_arr_t[Rows][Columns];
	    typedef numeric_type* val_ptr_t;

	    typedef cap::matrix<numeric_type, Rows, Columns> matrix_t;


	public:
	    matrix()
	        : m_row_len(Rows), m_col_len(Columns), m_start_ptr((val_ptr_t)m_self_matrix){
		    fill(0);
		  }

	    matrix(dbl_arr_t &initializer)
                : m_row_len(Rows), m_col_len(Columns), m_start_ptr((val_ptr_t)m_self_matrix){
                    for(size_t i = 0; i < Rows; i++){
                        for(size_t j = 0; j < Columns; j++){
                                m_self_matrix[i][j] = initializer[i][j];
                                m_result[i][j] = 0;
                               }}
                              }
                  

	    ~matrix(){}


	private:
            numeric_type m_self_matrix[Rows][Columns];
            val_ptr_t m_start_ptr;
            size_t m_row_len, m_col_len;

            dbl_arr_t m_result;

	public:
            void get_row_len(){
	        std::cout << Rows;
	       }

	    void fill(numeric_type value){
	        for(size_t i = 0; i < Rows; i++){
			for(size_t j = 0; j < Columns; j++){
				m_self_matrix[i][j] = value;
				m_result[i][j] = 0;
	                       }}
	                      }
	    
            void print(){
	       for(size_t i = 0; i < m_row_len; i++){
		    for(size_t j = 0; j < m_col_len; j++) 
		         std::cout << m_self_matrix[i][j] << " ";
	       std::cout << '\n';}
	              }

	   //references
           numeric_type* operator[](size_t index){
               return m_self_matrix[index];
              }
	    
	      
	     void Identity(){
                 if(Rows != Columns)
			 throw mustBeSquare();
                 for(size_t i = 0; i < Rows; i++){
                     for(size_t j = 0; j < Columns; j++){
                         if(i == j) 
				 m_self_matrix[i][j] = 1;
                         else
				 m_self_matrix[i][j] = 0;  }   }
                               }

	     void Random(){
	         for(size_t i = 0; i < Rows; i++)
                     for(size_t j = 0; j < Columns; j++)
                         m_self_matrix[i][j] = rand() % 70;
	               }

	     void Transpose(){
		 if(Rows != Columns)
			 throw mustBeSquare();
	         for(size_t i = 0; i < Rows; i++)
                     for(size_t j = i+1; j < Columns; j++){
                        numeric_type temp = m_self_matrix[i][j];
                        m_self_matrix[i][j] = m_self_matrix[j][i];
			m_self_matrix[j][i] = temp;
		      }
	            }

	      matrix_t Result(){
	         return matrix(m_result);
	      }

 
	      void matrixMultiplication(matrix_t &other){
	          if(Rows != Columns || other.m_row_len != other.m_col_len || Rows != other.m_row_len)
			  throw mustBeSquare();
	      
	          numeric_type temp;
                  for(size_t v = 0; v < Rows; v++){
                      for(size_t i = 0; i < Rows; i++){

                  temp = m_self_matrix[i][v];
                  for(size_t j = 0; j < Rows; j++)
                    m_result[i][j] += temp * other[v][j];
                     } 
		    }
	          }

	
	      /*
              * Remember to come back and and do the non_square transpose
              *  maybe define with a macro if
              * */



     };//end class

  }//end namespace


/*


template<int R, int C>
void clearMatrix(double(&clear)[R][C]);

template<unsigned R, unsigned C>
void transpose(double (&original)[R][C], double (&transposed)[C][R]);

template<int N>
void matrixMultiplication(double (&matrixOne)[N][N], double (&matrixTwo)[N][N], double (&result)[N][N]);

template<int M, int N, int P>
void matrixMultiplication(double (&matrixOne)[M][N], double (&matrixTwo)[N][P], double (&result)[M][P]);

template<int N>
void matrixAddition(double (&matrixOne)[N][N], double (&matrixTwo)[N][N], double (&result)[N][N]);
*/
