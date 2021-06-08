#include <iostream>

#include "myArithmetic.hpp"


int absolute(int x)
{




    if(!(x & (1 << 31)))    
        return x;


    else{
    
        return ~x+1;
    }


}
    

/*
int main()
{

cP();


return 0;
}
*/
