#include "gaussian.hpp"
#include "../single_matrix_opps/single_matrix.hpp"
#include "../printLA/printLA.hpp"

int main(){

double test[4][4];
generateRandom(test);
std::cout << "I randomly generated a matrix called test, it is printed below: " << std::endl;
printMatrix(test);

double gaussOutput[4][4];
gauss(test,gaussOutput);
printMatrix(gaussOutput);

return 0;
}
