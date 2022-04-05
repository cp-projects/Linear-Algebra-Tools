#include "gaussian.hpp"
#include <iostream>

template<int R, int C>
void gauss(double (&input)[R][C], double (&output)[R][C])
{

int rowPivot = 0;
int columnPivot = 0;

double maxAbsolute;




//works down main diagonal of the matrix
while(rowPivot < R && columnPivot < C)
    {



        std::cout << absolute(input[rowPivot][columnPivot]) << ' ';


        if(absolute(input[rowPivot][columnPivot]) > maxAbsolute)

            maxAbsolute = input[rowPivot][columnPivot];
            std::cout << " MAX VALUE = " << maxAbsolute << '\n';


        rowPivot++;
        columnPivot++;
    }

}


