#include "gaussian.hpp"

int main(){

 double test[3][3] = {{5,2,3},
	              {2,3,4},
		      {3,4,1}};

 double output[3][3];

 gauss(test, output);


return 0;
}
