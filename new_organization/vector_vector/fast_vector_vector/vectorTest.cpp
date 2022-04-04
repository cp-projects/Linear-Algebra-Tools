#include <iostream>
#include "vector_vector.hpp"
#include "../../printLA/printLA.hpp"

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


    double crossVec1[3] = {1, 0, 0};
    double crossVec2[3] = {0, 1, 0};
    double result[3];

    cross(crossVec1, crossVec2, result);

    std::cout << "This";
    printVector(crossVec1);
    std::cout << " X  This";
    printVector(crossVec2);

    std::cout << " =  This";
    printVector(result);


    cross(crossVec2, crossVec1, result);

    std::cout << "This";
    printVector(crossVec2);
    std::cout << " X  This";
    printVector(crossVec1);

    std::cout << " =  This";
    printVector(result);

return 0;
}
