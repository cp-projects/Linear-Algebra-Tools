#pragma once

//#define erase_debug_eig
#ifndef erase_debug_eig
#define LOG1eig(x) x.print(); std::cout << "\n\n\n\n\n\n";
#else
#define LOG1eig(x)
#endif


col_vector_t* eig_vals(){

    col_vector_t* ret_vec = new col_vector_t;
    col_vector_t eigen = cap::vector<numeric_type, Rows>();

    matrix_t A0 = *(this);
    //`A0.Hessenberg();
    A0.Round();


    A0.QR();

    matrix_t A1 = *(A0.my_two_factor->right) * *(A0.my_two_factor->left);
    A1.Round();                                                                           LOG1eig(A1)

    A1.QR();
    matrix_t A2 = *(A1.my_two_factor->right) * *(A1.my_two_factor->left);
    A2.Round();                                                                           LOG1eig(A2)

    //A2.Hessenberg();

    delete A1.my_two_factor->left;
    delete A1.my_two_factor->right;
    delete A1.my_two_factor;


    A2.QR();
    matrix_t Ai = *(A2.my_two_factor->right) * *(A2.my_two_factor->left);
    Ai.Round();                                                                           LOG1eig(Ai)
    
    //Ai.Hessenberg();

    delete A2.my_two_factor->left;
    delete A2.my_two_factor->right;
    delete A2.my_two_factor;


    //matrix_t temp = Ai;
    for(int i = 0; i < std::pow(Rows,3); i++){
    
	 Ai.QR();
         matrix_t temp = *(Ai.my_two_factor->right) * *(Ai.my_two_factor->left);
	 temp.Round();                                                                   LOG1eig(temp)
          
	 //temp.Hessenberg();


         delete Ai.my_two_factor->left;
         delete Ai.my_two_factor->right;
         delete Ai.my_two_factor;

	 Ai = temp;                                                                       LOG1eig(Ai)
    }


    Ai.print();
    std::cout << "\n\n\n\n\n\n";

    numeric_type temp[Rows];
    for(int i = 0; i < Rows; i++)
        for(int j = 0; j < Columns; j++)
		if(i == j)
			temp[i] = Ai[i][j];

    *(ret_vec) = temp;

    delete A0.my_two_factor->left;
    delete A0.my_two_factor->right;
    delete A0.my_two_factor;


    return ret_vec;

}
