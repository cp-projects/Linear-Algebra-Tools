#pragma once

#include<iostream>
#include<array>
#include<stdlib.h>

#include"../errorsLA/matrixErrors.hpp"

namespace cap{

template<typename numeric_type, size_t dimention>
class vector{

    private://typedefs
	    typedef numeric_type arr_t[dimention];
	    typedef numeric_type* val_ptr_t;
	    typedef const arr_t& l_literal_t;
	    typedef arr_t&& r_literal_t;
	    
	    typedef cap::vector<numeric_type, dimention> vector_t;
	    typedef vector_t* ptr_t;
	    typedef const vector_t& l_val_t;
	    typedef vector_t&& r_val_t;
	   
            typedef typename std::initializer_list<numeric_type> init_t;
	    typedef typename init_t::iterator init_Iterator;

	    typedef typename std::pair<numeric_type, vector_t> scale_pair_t;


    public: //constructors and destructors

	    //generic constructor
	    vector<numeric_type, dimention>()
	       :m_self_vector(), m_length(dimention) {
		       fill((numeric_type)0.0);
	             }

	    //declared array constructor
	    vector(arr_t& other)
	       : m_length(dimention) {
	        for(size_t i = 0; i < dimention; i++)
                    m_self_vector[i] = other[i];
	           }

	    //copy constructor
	    vector(l_literal_t other)\
	       : m_length(dimention) {
	        for(size_t i = 0; i < dimention; i++)
		    m_self_vector[i] = other[i];
	          }


	    vector(init_t initializer)
                   : m_length(dimention) {
                   int i = 0;
                   for(init_Iterator itr = initializer.begin(); itr < initializer.end(); itr++){
                        m_self_vector[i] = *(itr);
                       i++;
		      }
                    }


	    ~vector<numeric_type, dimention>() {}

	

    private: //the acutal vector object
	    numeric_type m_self_vector[dimention];
	    numeric_type m_result[dimention];
	    
	    val_ptr_t m_start_ptr = m_self_vector;
	    size_t m_length;

	    numeric_type m_dot_product;




    public: //fillers
	   void fill(numeric_type value){
	       for(size_t i = 0; i < dimention; i++)
		       m_self_vector[i] = value;
	             }

	   void random(){
	       for(size_t i = 0; i < dimention; i++)
		       m_self_vector[i] = rand() % 70;
	             }
 
           
           //printing and logging
           void print(){
                for(size_t i = 0; i < dimention; i++)
                    std::cout << m_self_vector[i] << ' ';
                std::cout << '\n';
               }

	   vector_t Result(){
	       return vector(m_result);
	   }


	   //references
	   numeric_type operator[](size_t index){
	       return m_self_vector[index];
	      }

	   std::size_t len(){
               return dimention;
              }

	   //math
	   constexpr numeric_type dot(vector_t &other){
	       m_dot_product= 0;
               for(size_t i = 0; i < dimention; i++)
                   m_dot_product += m_self_vector[i] * other[i];
               return m_dot_product;
              }
	   
	   constexpr numeric_type operator*(vector_t &other){
	          return dot(other);
	         }

	   constexpr void scale(numeric_type scaler){
               for(int i = 0; i < dimention; i++)
                   m_self_vector[i] *= scaler;
                  }

	   constexpr void operator*(numeric_type scaler){
	       scale(scaler);
	      }

	   constexpr void addInto(vector_t &other){
               for(size_t i = 0; i < dimention; i++)
                   m_self_vector[i] += other[i];
                  }

	   constexpr void operator+=(vector_t &other){
	       addInto(other);
	      }

           constexpr void subtractInto(vector_t &other){
               for(size_t i = 0; i < dimention; i++)
                   m_self_vector[i] -= other[i];
                  }

	   constexpr void operator -=(vector_t &other){
	       subtractInto(other);
	      }

	   constexpr void addScaled(vector_t &other, numeric_type scalar){
               for(size_t i = 0; i < dimention; i++)
                   m_self_vector[i] += (scalar * other[i]);	  
	          }

	   void operator+=(const scale_pair_t &pair){
	       vector_t other = pair.second;
	       numeric_type scalar = pair.first;
	       addScaled(other, scalar);
	      }

           constexpr void subtractScaled(vector_t &other, numeric_type scalar){
               for(size_t i = 0; i < dimention; i++)
                   m_self_vector[i] -= (scalar * other[i]);
                 }

	   void operator-=(const scale_pair_t &pair){
               vector_t other = pair.second;
               numeric_type scalar = pair.first;
               subtractScaled(other, scalar);
              }

        
   private:	   
	constexpr numeric_type det(numeric_type matrix2x2[2][2]){
            numeric_type result =  (matrix2x2[0][0] * matrix2x2[1][1]) - (matrix2x2[0][1] * matrix2x2[1][0]);
	    if(result == -0)
		    result = 0;
            return result;
           }

	void fill_matrix(numeric_type matrix2x2[2][2], numeric_type val){
	    matrix2x2[0][0] = val; matrix2x2[0][1] = val; matrix2x2[1][0] = val; matrix2x2[1][1] = val;
	  }

   public:
	cap::vector<numeric_type, dimention> cross(cap::vector<numeric_type, dimention> &other){

	if(dimention != 3)
                         throw notR3();

        numeric_type matrix[2][2];

	numeric_type indexZero;
	numeric_type indexOne;
	numeric_type indexTwo;

        for(size_t i = 0; i < 3; i++){

            switch(i){

                case 0:
                        matrix[0][0] = m_self_vector[1];
                        matrix[0][1] = m_self_vector[2];
                        matrix[1][0] = other[1];
                        matrix[1][1] = other[2];
                        indexZero = det(matrix);
			m_result[i] = indexZero;
                        break;

                case 1:
                        matrix[0][0] = m_self_vector[0];
                        matrix[0][1] = m_self_vector[2];
                        matrix[1][0] = other[0];
                        matrix[1][1] = other[2];
                        indexOne = -det(matrix) ? det(matrix) != 0 : 0;
			m_result[i] = indexOne;
                        break;

                case 2:
                        matrix[0][0] = m_self_vector[0];
                        matrix[0][1] = m_self_vector[1];
                        matrix[1][0] = other[0];
                        matrix[1][1] = other[1];
                        indexTwo = det(matrix);
			m_result[i] = indexTwo;
                        break;
                               }; //end switch     
                     }//end for loop
	          return m_result;
                  }//end function


      };


}
