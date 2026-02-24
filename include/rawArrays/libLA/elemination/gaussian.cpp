#include <iostream>
#include "gaussian.hpp"
#include "../myArithmetic/myArithmetic.hpp"

template<int R, int C>
void gauss(double (&input)[R][C], double (&output)[R][C])
{

int rowPivot = 0;
int columnPivot = 0;

double maxAbsolute;




//works down main diagonal of the matrix
while(rowPivot < R && columnPivot < C)
    {


	//should be absolute    
	double abs =  input[rowPivot][columnPivot];

	std::cout << abs << ' ';

        if(abs > maxAbsolute)

            maxAbsolute = input[rowPivot][columnPivot];
            std::cout << " MAX VALUE = " << maxAbsolute << '\n';


        rowPivot++;
        columnPivot++;
    }

}


