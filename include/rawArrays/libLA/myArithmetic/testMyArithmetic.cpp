#include <iostream>
#include "myArithmetic.hpp"

void test_int(){

    for(int i = 1; i < 11; i++){
        int val = -i;
	int abs = absolute(val);
        std::cout << "absolute of " << val << " is " << abs << '\n';
    }
}


void test_dbl(){

    for(int i = 1; i < 11; i++){
        double val = -(i+0.123456789);
        double abs = absolute(val);
        std::cout << "absolute of " << val << " is " << abs << '\n';
     }
}

void test_flt(){

    for(int i = 1; i < 11; i++){
        float val = -(i+0.123456789);
        float abs = absolute(val);
        std::cout << "absolute of " << val << " is " << abs << '\n';
     }
}

int main(){

    std::cout << " Int is \n";	
    test_int();

    std::cout << "\n\n Double is \n";
    test_dbl();

    std::cout << "\n\n Float is \n";
    test_flt();

return 0;
}



