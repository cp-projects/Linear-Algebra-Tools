#pragma once

#include<iostream>
#include<array>
#include<stdlib.h>
#include <cassert>

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
	    



    public: //constructors and destructors

	    //generic constructor
	    vector<numeric_type, dimention>()
	       :m_self_vector()  {
		       fill((numeric_type)0.0);
	             }

	    //copy constructor
	    vector(l_literal_t other){
	        for(size_t i = 0; i < dimention; i++)
		    m_self_vector[i] = other[i];
	          }

	    ~vector<numeric_type, dimention>() {}

	

    private: //the acutal vector object
	    numeric_type m_self_vector[dimention];
	    val_ptr_t m_start_ptr = m_self_vector;
	    size_t m_length;




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


	   //references
	   numeric_type operator[](size_t index){
	       return m_self_vector[index];
	      }

	   std::size_t len(){
               return dimention;
              }

	   //math
	   constexpr numeric_type dot(cap::vector<numeric_type, dimention> other){
	       numeric_type dotProduct;
               for(size_t i = 0; i < dimention; i++)
                   dotProduct += m_self_vector[i] * other[i];
                   return dotProduct;
                  }
	   
	   constexpr numeric_type operator*(cap::vector<numeric_type, dimention> other){
	          return dot(other);
	         }

	   constexpr void scale(numeric_type scaler){
               for(int i = 0; i < dimention; i++)
                   m_self_vector[i] *= scaler;
                 }

	   constexpr void operator*(numeric_type scaler){
	           scale(scaler);
	      }

	   constexpr void addInto(cap::vector<numeric_type, dimention> &other){
               for(size_t i = 0; i < dimention; i++)
                   m_self_vector[i] += other[i];
                 }
	   constexpr void operator+=(cap::vector<numeric_type, dimention> &other){
	       addInto(other);
	      }

           constexpr void subtractInto(cap::vector<numeric_type, dimention> &other){
               for(size_t i = 0; i < dimention; i++)
                   m_self_vector[i] -= other[i];
                 }

	   constexpr void operator -=(cap::vector<numeric_type, dimention> &other){
	       subtractInto(other);
	      }

	   constexpr void addScaled(cap::vector<numeric_type, dimention> &other, numeric_type scalar){
               for(size_t i = 0; i < dimention; i++)
                   m_self_vector[i] += (scalar * other[i]);
                 }

           constexpr void subtractScaled(cap::vector<numeric_type, dimention> &other, numeric_type scalar){
               for(size_t i = 0; i < dimention; i++)
                   m_self_vector[i] -= (scalar * other[i]);
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
	ptr_t cross(cap::vector<numeric_type, dimention> &other){

	/*	
	std::assert((dimention == 3));
	std::assert((other.len() == 3));
	std::assert((result.len() == 3));
        */

        numeric_type matrix[2][2];
	//fill_matrix(matrix, 0.0);

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
                        break;

                case 1:
                        matrix[0][0] = m_self_vector[0];
                        matrix[0][1] = m_self_vector[2];
                        matrix[1][0] = other[0];
                        matrix[1][1] = other[2];
                        indexOne = -det(matrix) ? det(matrix) != 0 : 0;
                        break;

                case 2:
                        matrix[0][0] = m_self_vector[0];
                        matrix[0][1] = m_self_vector[1];
                        matrix[1][0] = other[0];
                        matrix[1][1] = other[1];
                        indexTwo = det(matrix);
                        break;
                               }; //end switch     
                     }//end for loop

	          static cap::vector result({indexZero, indexOne, indexTwo});
		  return &result;
		  //return result;
                  }//end function




 

      };


}
