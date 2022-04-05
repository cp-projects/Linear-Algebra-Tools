#include "printLA.hpp"

void testVector(){

   double vector[6] = {1.123456789,2.123456789,3.123456789,4.123456789,5.123456789,6.123456789};

   printVector(vector);

   double vector1[12] = {1,2,3,4,5,6,7,8,9,10,11,12};

   printVector(vector1);

   double vector2[1] = {1};

   printVector(vector2);

}


void testMatrix(){

    double A[2][2] = {{1.123456789, 2.123456789},
                      {3.123456789, 4.123456789}};

    printMatrix(A);

}



int main(){

   testVector();

   testMatrix();


return 0;
}
