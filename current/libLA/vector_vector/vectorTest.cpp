#include <iostream>
#include "vector_vector.hpp"
#include "../printLA/printLA.hpp"

int main(){

    double vec1[5] = {1,2,3,4,5};
    double vec2[5] = {1,1,1,1,1};

    double DOT = dot(vec1, vec2, 5);

    std::cout << "DOT Product is " << DOT << '\n';

    scale(vec2, 5, 2);

    DOT = dot(vec1, vec2, 5);

    std::cout << "DOT Product after scaling is " << DOT << '\n';

    std::cout << " Adding ";
    printVector(vec1);
    std::cout << " and ";
    printVector(vec2);


    std::cout << " To Get ";
    addVectors(vec1, vec2, 5);
    printVector(vec1);

    std::cout << " Subtracting it back off ";
    subtractVectors(vec1, vec2, 5);
    printVector(vec1);

    std::cout << " Scaling it back down ";
    scale(vec2, 5, 0.5);
    printVector(vec2);

    std::cout << "Adding Scaled back Version";
    addScaled(vec1, vec2, 5, 2);
    printVector(vec1);

    std::cout << "Subtracting back off scaled";
    subtractScaled(vec1, vec2, 5, 2);
    printVector(vec1);

	

return 0;
}
