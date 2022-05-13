#include <iostream>
#include "matrix.hpp"

int main(){

	

        cap::matrix test_constructor = cap::matrix<double, 2,2> ({{1.0,1.0},{1.0,1.0}});
	test_constructor.print();

	std::cout << "\n\n\n\n\n";


	cap::matrix first = cap::matrix<double, 4, 4>();
	cap::matrix second = cap::matrix<double, 4, 4>();


//	first.get_row_len();
//
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

	first.Random();
	first.print();

	std::cout << "\n\n\n\n\n";
	
	first.Transpose();
	first.print();

	std::cout << "\n\n\n\n\n";

	second.Random();
	second.print();

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

	std::cout << "\n\n\n\n\n";

	cap::matrix<double, 3,4> test_non_square = {{1,1,1,1},
			                            {1,1,1,1},
						    {1,1,1,1}};
        test_non_square*2; 
	test_non_square.print();
	test_non_square*0.5;
	
	std::cout << "\n\n\n\n\n";
 
	cap::matrix res3 = test_non_square*res2;
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

        res4 = resquare*test_non_square;
        res4.print();

	std::cout << "\n\n\n\n\n";

	cap::matrix res5 = res4.transpose_ns();
	res5.print();

	std::cout << "\n\n\n\n\n";

	cap::matrix<double, 3, 3> test_pow  = {{1,0,0},
		                               {0,2,0},
				               {0,0,3}};

         cap::matrix res6 = test_pow^4;
	 res6.print();

	/*cap::matrix res6 = test_pow;
	res6 = res6*test_pow;
	res6 = res6*test_pow;
        res6 = res6*test_pow;
	res6.print();*/

	std::cout << "\n\n\n\n\n";




return 0;
}
