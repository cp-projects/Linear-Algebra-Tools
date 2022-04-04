#include "matrix_vector.hpp"
#include "../printLA/printLA.hpp"
#include "../single_matrix_opps/single_matrix.hpp"

int main(){

    double A[4][4];
    generateRandom(A);

    printMatrix(A); 

    double vector[4] = {1, 2, 3, 4};
    printVector(vector);

    double result[4];

     matrixVectorMultiplication(A, vector, result);

    //printVector(result);


return 0;
}
