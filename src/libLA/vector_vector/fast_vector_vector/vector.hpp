#pragma once

#include<iostream>
#include<array>
#include<stdlib.h>
#include<ostream>

namespace cap{

template<typename numeric_type, size_t dimention>
class vector{

    private://typedefs
	    typedef numeric_type vector_t[dimention];


    public: //constructors and destructors
	    vector<numeric_type, dimention>()
	       :m_self_vector()  {
		       fill(0);
	             }

	    vector(const vector_t &other){
	        for(size_t i = 0; i < dimention; i++)
		    m_self_vector[i] = other[i];
	          }

	    ~vector<numeric_type, dimention>() {}

	

    private: //the acutal vector object
	    numeric_type m_self_vector[dimention];




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

	   
	   void operator<<(void){
                
              print();
		   /*
		 static std::ostream stream;
		 for(size_t i = 0; i < other.len(); i++)
                     stream << other[i] << '\n';
                 return stream;*/
              }

	   std::size_t len(){
	       return dimention;
	      }

	   /*void operator<<(std::ostream& ret, cap::vector<numeric_type, dimention> &other){
	          other.print();
	      }*/


	   //reference values
	   numeric_type operator[](size_t index){
	       return m_self_vector[index];
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
 

};

/*
std::ostream& operator<<(const cap::vector<> &other){
                 static std::ostream stream;
                 for(size_t i = 0; i < other.len(); i++)
                     stream << other[i] << '\n';
                 return stream;
              }
*/

}
