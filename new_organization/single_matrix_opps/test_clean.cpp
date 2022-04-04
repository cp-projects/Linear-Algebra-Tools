#include "cleanMatrix.hpp"
#include "../printLA/printLA.hpp"

void test_identity(){

   double identity[6][6];
   generateIdentity(identity);
   printMatrix(identity);
   clearMatrix(identity);
   printMatrix(identity);

   double identity1[2][2];
   generateIdentity(identity1);
   printMatrix(identity1);
   clearMatrix(identity1);
   printMatrix(identity1);

   double identity2[9][9];
   generateIdentity(identity2);
   printMatrix(identity2);
   clearMatrix(identity2);
   printMatrix(identity2);

}


void test_rand_transp(){

   double randMatrix[6][6];
   generateRandom(randMatrix);
   printMatrix(randMatrix);

   double trans[6][6];
   transpose(randMatrix, trans);
   printMatrix(trans);
   clearMatrix(trans);
   printMatrix(trans);

   double randMatrix1[2][2];
   generateRandom(randMatrix1);
   printMatrix(randMatrix1);

   double trans1[2][2];
   transpose(randMatrix1, trans1);
   printMatrix(trans1);
   clearMatrix(trans1);
   printMatrix(trans1);

   double randMatrix2[9][9];
   generateRandom(randMatrix2);
   printMatrix(randMatrix2);

   double trans2[9][9];
   transpose(randMatrix2, trans2);
   printMatrix(trans2);
   clearMatrix(trans2);
   printMatrix(trans2);
}


int main(){

   test_identity();
   test_rand_transp(); 

return 0;
}
