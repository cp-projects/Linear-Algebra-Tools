#include <iostream>
#include "matrix.hpp"


bool testQR(){

   cap::matrix A0 = cap::matrix<double,10,10>();

   bool passing_flag = true;
   for(int i = 0; i < 10; i++){
   
	A0.Random();
//	cap::matrix save = A0;
//	std::cout << " A \n";
//	A0.print();
//	std::cout << "\n\n\n\n\n";

       
        A0.QR();

       // std::cout << "\n Q \n";
       // A0.my_two_factor->left->print();
       // std::cout << "\n\n\n\n\n";
       // std::cout << "\n R \n";
       // A0.my_two_factor->right->print();
       // std::cout << "\n\n\n\n\n";


        cap::matrix QR_Test = *(A0.my_two_factor->left) * *(A0.my_two_factor->right);
        QR_Test.Round();

        //std::cout << "\n QR = A \n";
        //QR_Test.print();
        //std::cout << "\n\n\n\n\n";

	if(QR_Test == A0){
                std::cout << "Failed on QR_Test\n";
		QR_Test.print();
		std::cout << "\n\n\n\n\n";
		std::cout << "And QR = A\n";
		A0.print();
		std::cout << "\n\n\n\n\n";

		passing_flag = false;
	}


        delete A0.my_two_factor->left;
        delete A0.my_two_factor->right;
        delete A0.my_two_factor;
   
      }

return passing_flag;
}




int main(){

        bool boolResult = testQR();	
	std::cout << boolResult << '\n';

/*

        cap::matrix test_constructor = cap::matrix<double, 2,2> ({{1.0,1.0},{1.0,1.0}});
	test_constructor.print();

	std::cout << "\n\n\n\n\n";

	cap::vector<double, 2> construct = {2,0};

	cap::vector construct_res = test_constructor*construct;

        construct_res.print();

	std::cout << "\n\n\n\n\n";

	cap::matrix first = cap::matrix<double, 4, 4>();
	cap::matrix second = cap::matrix<double, 4, 4>();


//	first.get_row_len();

	first.Identity();
	first.print();

	std::cout << "\n\n\n\n\n";

        first*2;
        first.print();

	std::cout << "\n\n\n\n\n";
  
	cap::vector<double, 4> row1 = first.extractRow(1);
	row1.print();

	std::cout << "\n\n\n\n\n";

        first.replaceRow(4, row1);
	first.print();

	std::cout << "\n\n\n\n\n";

	cap::vector<double, 4> col1 = first.extractColumn(1);
        col1.print();

        std::cout << "\n\n\n\n\n";

        first.replaceColumn(4, col1);
        first.print();

        std::cout << "\n\n\n\n\n";

	first = first.swapRows(1, 2);
        first.print();

        std::cout << "\n\n\n\n\n";

	first = first.swapColumns(1, 2);
        first.print();

        std::cout << "\n\n\n\n\n";

	first.scaleRow(1, 2);
        first.print();

        std::cout << "\n\n\n\n\n";

	first.scaleColumn(2, 2);
        first.print();

        std::cout << "\n\n\n\n\n";

	first.addRows(1, 2);
        first.print();

        std::cout << "\n\n\n\n\n";

	first.addColumns(2, 4);
        first.print();

        std::cout << "\n\n\n\n\n";

	first.addScaledR(2, 4, 0.5);
        first.print();

        std::cout << "\n\n\n\n\n";
	
	double min_one_third = -1.0/3.0;
	first.addScaledC(4, 2, min_one_third);
        first.print();

        std::cout << "\n\n\n\n\n";

	cap::vector<double, 4> diag1 = first.extractDiagonal();

	diag1.print();

	std::cout << "\n\n\n\n\n";

	cap::vector<double, 4> diag2 = first.extractOffDiagonal();

	diag2.print();

        std::cout << "\n\n\n\n\n";

        first.replaceDiagonal(diag2);

        first.print();

        std::cout << "\n\n\n\n\n";

	first.replaceOffDiagonal(diag1);

        first.print();

        std::cout << "\n\n\n\n\n";

	first.replaceOffDiagonal(diag2);
        first.replaceDiagonal(diag1);
	first.print();

	std::cout << "\n\n\n\n\n";

	first.rref();
	first.print();

	std::cout << "\n\n\n\n\n";

	first.Random();
	first.print();

	std::cout << "\n\n\n\n\n";

	cap::vector transformed1 = first*row1;
	transformed1.print();

        std::cout << "\n\n\n\n\n";
	
	first.Transpose();
	first.print();

	std::cout << "\n\n\n\n\n";

	second.Random();
	second.print();

	std::cout << "\n\n\n\n\n";

	cap::vector transformed2 = second*transformed1;
        transformed2.print();

        std::cout << "\n\n\n\n\n";

	col1*-1;

	transformed2 = second*col1;
        transformed2.print();

        std::cout << "\n\n\n\n\n";

	cap::matrix result = first*second;
	result.print();

	std::cout << "\n\n\n\n\n";

	second.Identity();
	cap::matrix res2 = result+second;
	res2.print();

	std::cout << "\n\n\n\n\n";

	cap::matrix res2AndAHalf = second-res2;
	res2AndAHalf.print();

	//double test_det3 = res2AndAHalf.Determinant();

	//cap::matrix invert2AndAHalf = res2AndAHalf.invert();
	
	//std::cout << "\n\n\n\n\n";
	
	//std::cout << test_det3 << std::endl;

	std::cout << "\n\n\n\n\n";

	res2AndAHalf.rref();
        res2AndAHalf.print();

	std::cout << "\n\n\n\n\n";

	cap::matrix<double, 3,4> test_non_square = {{1,1,1,1},
			                            {1,1,1,1},
						    {1,1,1,1}};
        test_non_square*2; 
	test_non_square.print();
	test_non_square*0.5;

	//double test_ns_det = test_non_square.Determinant();
	//test_non_square.invert();
	
	std::cout << "\n\n\n\n\n";
 
	cap::matrix res3 = test_non_square*res2;
	res3.print();

	//std::cout << "\n\n\n\n\n";

	//res3.print_dimentions();
	res3.rref();

	std::cout << "\n\n\n\n\n";
        res3.print();

        std::cout << "\n\n\n\n\n";

	cap::matrix resquare = cap::matrix<double, 3,3>();
	resquare.Identity();
	cap::matrix res4 = resquare*test_non_square;
	res4.print();

        std::cout << "\n\n\n\n\n";

        test_non_square.print();

        std::cout << "\n\n\n\n\n";

	resquare.Random();
	resquare.print();

	std::cout << "\n\n\n\n\n";

	cap::matrix inv_resq = resquare.invert();
        inv_resq.print();

        std::cout << "\n\n\n\n\n";

        res4 = resquare*test_non_square;
        res4.print();

	std::cout << "\n\n\n\n\n";

	cap::matrix res5 = res4.transpose_ns();
	res5.print();

	std::cout << "\n\n\n\n\n";

	cap::matrix<double, 3, 3> test_pow  = {{1,0,0},
		                               {0,2,0},
				               {0,0,3}};

        //test_pow.gauss();

        cap::matrix res6 = test_pow^4;
	res6.print();

	/cap::matrix res6 = test_pow;
	res6 = res6*test_pow;
	res6 = res6*test_pow;
        res6 = res6*test_pow;
	res6.print();/

        std::cout << "\n\n\n\n\n";

	cap::matrix invert_res6 = res6.invert();
	invert_res6.print();

	std::cout << "\n\n\n\n\n";


	cap::matrix<double,2,2> test_det = {{1, 0},
                                           {24, 2}};

	cap::matrix inverse_test_det = test_det.invert();

	inverse_test_det.print();


	std::cout << "\n\n\n\n\n";

	double det_val1 = test_det.Determinant();

	std::cout << det_val1 << std::endl;

	std::cout << "\n\n\n\n\n";


	cap::matrix<double,3,3> test_det2 = {{1, 0, 54},
		                            {24, 2, -7},
                                           {3.4, 2.7, 5.5}};

        test_det2.print();

        std::cout << "\n\n\n\n\n";

        double det_val2 = test_det2.Determinant();

        std::cout << det_val2 << std::endl;

        std::cout << "\n\n\n\n\n";

	
	cap::matrix invert_test_det2 = test_det2.invert();
        invert_test_det2.print();

	std::cout << "\n\n\n\n\n";


	test_det2.Random();
        test_det2.print();

	std::cout << "\n\n\n\n\n";

	std::cout << " QR \n";
	test_det2.QR();

	std::cout << "\n Q \n";
	test_det2.my_two_factor->left->print();
	std::cout << "\n\n\n\n\n";
        std::cout << "\n R \n";
	test_det2.my_two_factor->right->print();
	std::cout << "\n\n\n\n\n";


	cap::matrix QR_Test = *(test_det2.my_two_factor->left) * *(test_det2.my_two_factor->right);

	std::cout << "\n QR = A \n";
	QR_Test.print();
	std::cout << "\n\n\n\n\n";


        delete test_det2.my_two_factor->left;
	delete test_det2.my_two_factor->right;
	delete test_det2.my_two_factor;

	cap::matrix<double, 4, 4> symmetric = {
	                                        {1,2,-1,5},
						{2,1,3, 0},
					        {-1,3,0,4},
						{5, 0,4,2}
	                                                   };

//	symmetric.Hessenberg();
 //       symmetric.print();
	std::cout << "\n\n\n\n\n";

	cap::vector<double, 4>* eigen = symmetric.eig_vals();
	
        eigen->print();

	std::cout << "\n\n\n\n\n";

	delete eigen;

	double PI = 3.14159265;

        cap::matrix<double, 3, 3> A_giv = {
		                            {6,5,0},
	                                    {5,1,4},
	                                    {0,4,3}
	                                           };

        A_giv.Hessenberg();
	
	A_giv.print();
	std::cout << "\n\n\n\n\n";

	A_giv = A_giv.Givens(2,1);
	A_giv.print();
        std::cout << "\n\n\n\n\n";

	A_giv = A_giv.Givens(3,1);

	
	//A_giv.Hessenberg();

	A_giv.print();
        std::cout << "\n\n\n\n\n";

	A_giv = A_giv.Givens(3,2);
	A_giv.print();
        std::cout << "\n\n\n\n\n";

//	symmetric.Hessenberg();
//	symmetric.print();

       // symmetric = symmetric.Givens(3,1);
//	symmetric.print();
//	std::cout << "\n\n\n\n\n";

//	symmetric = symmetric.Givens(4,1);
//	symmetric.print();
//	std::cout << "\n\n\n\n\n";

//	symmetric = symmetric.Givens(4,2);
//	symmetric.print();
//	std::cout << "\n\n\n\n\n";



	//symmetric = symmetric.Givens(2,1);
	//symmetric = symmetric.Givens(3,1);
        //symmetric = symmetric.Givens(4,1);


*/
return 0;
}
