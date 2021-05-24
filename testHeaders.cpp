#include "matrix.hpp"
#include <iostream>

int main(){


	double input[3][4] = {
	
	    {1,2,3,4},
	    {5,6,7,8},
	    {9,9,0,0}
	  
	};

	
	  for(int i = 0; i < 3; i++)
            {for(int j = 0; j < 4; j++){
                std::cout << input[i][j]  << ' ';}
            std::cout << '\n'; }
	

	std::cout << '\n';
	std::cout << '\n';
	std::cout << '\n';

 	double output[4][3];	
 
        transpose(input, output);	
	
	for(int i = 0; i < 4; i++)
	    {for(int j = 0; j < 3; j++){
	        std::cout << output[i][j]  << ' ';}
	    std::cout << '\n'; }



return 0;
}
