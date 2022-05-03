#include <iostream>
#include "fast_vector_vector.hpp"
#include "../../printLA/printLA.hpp"
#include "vector.hpp"

int main(){

    cap::vector vec0 = cap::vector<double, 5>();
    vec0.print();
    vec0.random();
    vec0.print();
    vec0.fill(12);
    vec0.print();

    cap::vector vec1({1.1,2.2,3.3,4.4,5.5});
    vec1.print();

    vec0.random();
    vec0.print();

    double dot0 = vec0.dot(vec1);
    double dot1 = vec1*vec0;
    std::cout << "The Dot Product Taken two ways " << dot0 << "  " << dot1 << '\n';

    vec1.scale(2.0);
    vec1.print();

    vec1*0.5;
    vec1.print();



    cap::vector vec2({1.0,1.0,1.0,1.0,1.0});

    double DOT = vec2*vec1;

    std::cout << "DOT Product is " << DOT << '\n';

    vec2*2;

    DOT = vec0*vec2;

    std::cout << "DOT Product after scaling is " << DOT << '\n';


    std::cout << " Adding ";
    vec2.print();
    std::cout << " and ";
    vec1.print();


    std::cout << " To Get ";
    vec2 += vec1;
    vec2.print();

    
    std::cout << " Subtracting it back off ";
    vec2 -= vec1;
    vec2.print();

    std::cout << " Scaling it back down ";
    vec2*0.5;
    vec2.print();


    
    std::cout << "Adding Scaled back Version ";
    vec1.addScaled(vec2, 2);
    vec1.print();

    std::cout << "Subtracting back off scaled ";
    vec1.subtractScaled(vec2, 2);
    vec1.print();
    


    cap::vector crossVec1({1.0, 0.0, 0.0});
    cap::vector crossVec2({0.0, 1.0, 0.0});

    cap::vector<double, 3> *Res = crossVec1.cross(crossVec2);
    cap::vector<double, 3> result(*Res);

    std::cout << "This" << "   ";
    crossVec1.print();
    std::cout << " X  \nThis" << "   ";
    crossVec2.print();

    std::cout << " =  \nThis" << "    ";
    result.print();
    


    Res = crossVec2.cross(crossVec1);
    cap::vector<double, 3> result2(*Res);

    std::cout << "\n\nThis" << "   ";
    crossVec2.print();
    std::cout << " X  \nThis" << "   ";
    crossVec1.print();

    std::cout << " =  \nThis" << "   ";
    result2.print();

return 0;
}
