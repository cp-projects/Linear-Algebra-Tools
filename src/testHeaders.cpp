#include "libLA.hpp"

int main(){	

	cap::matrix identity = cap::matrix<double,4,4>();

	identity.Identity();

	identity.print();

	std::cout << "\n\n\n\n\n";


	cap::matrix<double,3,4> input = {
	                                  {1,2,3,4},
	                                  {5,6,7,8},
	                                  {9,9,0,0}
	                                            };

	std::cout << "This is Input\n";	
	input.print();

	std::cout << "\n\n\n\n\n";

        cap::matrix output = input.transpose_ns();

	std::cout << "This is the output of input transposed\n";
	output.print();	


	std::cout << "\n\n\n\n\n";



	cap::matrix result = input*output;

	std::cout << "This is intput * output\n";
	result.print();

	std::cout << "\n\n\n\n\n";
        std::cout << result.Determinant() << '\n';
	std::cout << "\n\n\n\n\n";

	

	cap::matrix<double,3,3> A  = {
			              {1,2,1},
			              {3,8,1},
			              {0,4,1}
			                      };


	cap::matrix Aswap = A.swapRows(3,2);

        A.print();

	std::cout << "\n\n\n\n\n";

	Aswap.print();

	std::cout << "\n\n\n\n\n";

       


	
	
	cap::vector columnVector = A.extractColumn(1);

	columnVector.print();

	std::cout << "\n\n\n\n\n";


	cap::matrix<double, 2,2> test = {
                  		          {1,2},
	                                  {3,4}
	                                       };
	
	test.print();
	
	std::cout << "\n\n\n\n\n";
	
        std::cout << test.Determinant() << '\n';
	
	
	cap::matrix<char,3,3> letters = {
                                            {'a', 'b', 'c'},
                                            {'d', 'e', 'f'},
                                            {'g', 'h', 'i'}
                                                             };


	std::cout << "\n\n\n\n\n";
        letters.print();
        std::cout << "\n\n\n\n\n";
	


	cap::matrix<double,4,4>testTwo = {
				
			 	            {4,3,5,21},
				            {2,4,5,11},	
				           {13,41,2,2},
			                   {2,4,5,4}	
				                       };
	

        testTwo.print();
	std::cout << "\n\n\n\n\n";


	cap::vector testVector = testTwo.extractRow(1);
        testVector.print();
        std::cout << "\n\n\n\n\n";

	
	cap::vector testVectorTwo = testTwo.extractColumn(1);

	testVectorTwo.print();

	std::cout << "\n\n\n\n\n";

	
	double dotProduct = testVector*testVectorTwo;
	
	std::cout <<  dotProduct;


	std::cout << "\n\n\n\n\n";

	testVector*2;

	testVector.print();

	std::cout << "\n\n\n\n\n";

        
	testVector-=testVectorTwo;
	testVector.print();
	std::cout << "\n\n\n\n\n";


	cap::vector transform = identity*testVectorTwo;
        transform.print();

        std::cout << "\n\n\n\n\n";
	
	testTwo.print();

	std::cout << "\n\n\n\n\n";

	testTwo.rref();
	testTwo.print();

	std::cout << "\n\n\n\n\n";

	
	cap::vector<double, 3> crossVecOne = {-2,5,4};
	cap::vector<double, 3> crossVecTwo = {2,-3,-9};
	cap::vector crossResVector = crossVecOne.cross(crossVecTwo);
	crossResVector.print();

	std::cout << "\n\n\n\n\n";

	
	std::cout << "This is the Invert Method\n";

	cap::matrix<double, 2,2> myHomeWork = {
		                               {3, 1},
	                                       {-4, 6}
              				               };

	std::cout << "This is the input to invert\n";

        myHomeWork.print();
	std::cout << "\n\n\n\n\n";
	
	cap::matrix invertOutput = myHomeWork.invert();
        std::cout << "This is invert Output\n";
        invertOutput.print();

	std::cout << "\n\n\n\n\n";

	

	cap::vector transformInput = cap::vector<double, 2>({148,440});
	
	cap::vector appliedTransform = myHomeWork*transformInput;

	appliedTransform.print();

	std::cout << "\n\n\n\n\n";

         


return 0;

}
