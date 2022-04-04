#ifndef __fastVectorVector_H_
#define __fastVectorVector_H_


constexpr double dot(double* vectorOne, double* vectorTwo, int len, double dotProduct = 0){
    for(int i = 0; i < len; i++)
        dotProduct += vectorOne[i]*vectorTwo[i];    
return dotProduct;
}


constexpr void scale(double* vector, int len,  double scaler){     
   for(int i = 0; i < len; i++)
       vector[i] *= scaler;   
}


constexpr void addVectors(double* vectorOne, double* vectorTwo, int len){
    for(int i = 0; i < len; i++)
        vectorOne[i] += vectorTwo[i];
}

constexpr void subtractVectors(double* vectorOne, double* vectorTwo, int len){
    for(int i = 0; i < len; i++)
        vectorOne[i] -= vectorTwo[i];    
}

constexpr void addScaled(double* vectorOne, double* vectorTwo, int len, double scalar){
    for(int i = 0; i < len; i++)
        vectorOne[i] += (scalar * vectorTwo[i]);
}

constexpr void subtractScaled(double* vectorOne, double* vectorTwo, int len, double scalar){
    for(int i = 0; i < len; i++)
        vectorOne[i] -= (scalar * vectorTwo[i]);
}




#endif
