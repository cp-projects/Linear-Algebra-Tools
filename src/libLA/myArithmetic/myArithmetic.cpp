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

    
    if(x < 0)
	return -x;


return x;
}


float absolute(float x)
{


    if(x < 0)
        return -x;


return x;
}

