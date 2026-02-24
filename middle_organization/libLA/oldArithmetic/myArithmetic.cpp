#include "myArithmetic.hpp"


int absolute(int x)
{

    //This is the idea here, using careful bit operations I can define basic arithmatic functions to be really fast   
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

    else
        return x;
    
}


float absolute(float x)
{


    if(x < 0)
        return -x;

    else
        return x;
}

