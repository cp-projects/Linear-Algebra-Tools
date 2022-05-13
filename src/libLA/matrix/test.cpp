#include <iostream>
#include "matrix.hpp"

int main(){

	{

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
        
	test_non_square.print();
	
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


	

	}




return 0;
}
