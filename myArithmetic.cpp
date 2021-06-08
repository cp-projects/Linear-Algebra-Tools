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
    


double absolute(double x)
{




return x;
}

