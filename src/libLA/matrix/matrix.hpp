#pragma once

#include "../vector/vector.hpp"
#include "../errorsLA/matrixErrors.hpp"


namespace cap{

template<typename numeric_type, size_t Rows, size_t Columns>
class matrix{
	
        /*
	 *  My Types
	 *
	 * */

	private:
	    typedef numeric_type row_arr_t[Columns];
            typedef cap::vector<numeric_type, Columns> row_vector_t;

	    typedef numeric_type col_arr_t[Rows];
	    typedef cap::vector<numeric_type, Rows> col_vector_t;


	    typedef numeric_type dbl_arr_t[Rows][Columns];
	    typedef numeric_type* val_ptr_t;

	    typedef cap::matrix<numeric_type, Rows, Columns> matrix_t;

	    typedef typename std::initializer_list<numeric_type> init_t;
	    typedef typename std::initializer_list<init_t> dbl_init_t;
	    typedef typename dbl_init_t::iterator dbl_init_Iterator;
	    typedef typename init_t::iterator init_Iterator;

	    typedef struct twoFactor{

              matrix_t *left, *right;

            }twoFactor_t;

       
        /*
	 * Constructors/Destructors
	 *
	 */

	public:
            #include "tcc/normal/constructors.tcc" //empty, array, initializer list (all stack)
           
                  

	/*
	 *
	 * My Data
	 *
	 * */

       private:
            numeric_type m_self_matrix[Rows][Columns];
            val_ptr_t m_start_ptr;
            size_t m_row_len, m_col_len;
      
            dbl_arr_t m_result;  
	    row_arr_t m_row_result;
	    col_arr_t m_col_result;

       public:

            twoFactor_t* my_two_factor;

	    
        /*
	 * Getters and Setters: Then Math
	 *
	 * */

       public:
             #include "tcc/normal/getters.tcc"//get_row_len(),Result(),Print()
             #include "tcc/normal/double_access_get_set.tcc" //[]
             #include "tcc/normal/universal_setters.tcc" //Random(), Fill()
             #include "tcc/normal/cleaners.tcc"
           
	  
	     /*
	      * 
	      * Only Defined For Square Matricies
	      * 
	      * */
             #include "tcc/normal/square_setters.tcc" //Identity(), Transpose()
             #include "tcc/normal/square_math.tcc"  // *, +, -, scale
	     

	     /*
	      *
	      * Only Defined for Non-Square Matricies
	      *
	      * */
             #include "tcc/normal/non_square_math.tcc" //mult


    /*
     *
     * Row Operations
     *
     * */
	    
    public:
           
            #include "tcc/row_ops/basic_io.tcc"
            #include "tcc/row_ops/math_operations.tcc"


     /*
      * 
      * Matrix Vector Operations
      *
      *
      * */
 
      public:

	     #include "tcc/matrix_vector/matrix_vector.tcc"


     /*
      *
      * Determinant
      *
      * */
      
      public:

             #include "tcc/det/determinant.tcc"

      /*
       *  Elimination
       *
       * */

      public:

             #include "tcc/elimination/elimination.tcc"


       /*
	*
	* Invert
	*
	* */

	public:
	    
	     #include "tcc/invert/invert.tcc"


        /*
	 *
	 * Factorizations
	 *
	 * */

	 public:
             #include "tcc/factorizations/QR.tcc"


	 /*
	  * Eigen-Stuff
	  *
	  * */

	  public:
              #include "tcc/eigen/eigen.tcc"


     };//end class

  }//end namespace


