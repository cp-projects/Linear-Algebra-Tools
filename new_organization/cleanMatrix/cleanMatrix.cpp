#include "cleanMatrix.hpp"
#include "../errorsLA/matrixErrors.hpp"

template<int R, int C>
void generateIdentity(double(&identity)[R][C]){

    if(R != C) throw mustBeSquare();

    for(int i = 0; i < R; i++){

        for(int j = 0; j < C; j++){

            if(i == j) identity[i][j] = 1;

            else{ identity[i][j] = 0;}  }   }
}




template<int R, int C>
void clearMatrix(double(&clear)[R][C]){

    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            clear[i][j] = 0;


}

