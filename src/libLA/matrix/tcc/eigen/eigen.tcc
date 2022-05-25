#pragma once


col_vector_t* eig_vals(){

    col_vector_t* ret_vec = new col_vector_t;
    
    col_vector_t eigen = cap::vector<numeric_type, Rows>();

    this->QR();

    matrix_t A1 = *(this->my_two_factor->right) * *(this->my_two_factor->right);
    //A1.print();
    //std::cout << "\n\n\n\n\n\n";

    A1.QR();
    matrix_t A2 = *(A1.my_two_factor->right) * *(A1.my_two_factor->left);
    //A2.print();
    delete A1.my_two_factor->left;
    delete A1.my_two_factor->right;
    delete A1.my_two_factor;
    //std::cout << "\n\n\n\n\n\n";


    A2.QR();
    matrix_t Ai = *(A2.my_two_factor->right) * *(A2.my_two_factor->left);
    //Ai.print();
    delete A2.my_two_factor->left;
    delete A2.my_two_factor->right;
    delete A2.my_two_factor;
    //std::cout << "\n\n\n\n\n\n";


    for(int i = 0; i < 100; i++){
    
	 Ai.QR();
         matrix_t temp = *(Ai.my_two_factor->right) * *(Ai.my_two_factor->left);
        // temp.print();
         delete Ai.my_two_factor->left;
         delete Ai.my_two_factor->right;
         delete Ai.my_two_factor;
        // std::cout << "\n\n\n\n\n\n";
	// Ai = temp;
    }


    Ai.print();
    std::cout << "\n\n\n\n\n\n";

    numeric_type temp[Rows];
    for(int i = 0; i < Rows; i++)
        for(int j = 0; j < Columns; j++)
		if(i == j)
			temp[i] = Ai[i][j];

    *(ret_vec) = temp;

    delete this->my_two_factor->left;
    delete this->my_two_factor->right;
    delete this->my_two_factor;


    return ret_vec;

}
