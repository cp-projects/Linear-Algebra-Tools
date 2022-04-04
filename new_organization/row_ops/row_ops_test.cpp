#include "row_ops.hpp"
#include "../single_matrix_opps/single_matrix.hpp"
#include "../printLA/printLA.hpp"

int main(){

   double random1[9][9];
   generateRandom(random1);

   printMatrix(random1);

   for(int i = 1; i < 10; i++){
   
       double eRow[9];
       extractRow(i, random1, eRow);
       printVector(eRow);

       double eCol[9];
       extractColumn(i, random1, eCol);
       printVector(eCol);
   }

   printMatrix(random1);
   double swapped[9][9];

   swapRows(1, 7, random1, swapped);
   printMatrix(swapped);

   double newCol1[9];
   extractColumn(1, swapped, newCol1);
   
   double newCol2[9];
   extractColumn(7, swapped, newCol2);

   replaceColumn(7, swapped, newCol1);
   replaceRow(1, swapped, newCol2);

   printMatrix(swapped);

   


return 0;
}
