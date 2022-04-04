#include "cleanMatrix.hpp"
#include "../printLA/printLA.hpp"

void test(){

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



int main(){

   test(); 


return 0;
}
