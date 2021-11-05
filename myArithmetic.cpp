#include "myArithmetic.hpp"


int absoluteInt(int x)
{


    if(!(x & (1 << 31)))    
        return x;


    else{
    
        return ~x+1;
    }

}
    


double absoluteDouble(double x)
{

    
    if(x < 0)
	return -x;


return x;
}

