double dot(double* vectorOne, double* vectorTwo, int len){

    double dotProduct;
    for(int i = 0; i < len; i++)
        dotProduct += vectorOne[i]*vectorTwo[i];
    
return dotProduct;
}


void scale(double* vector, int len,  double scaler){  
   for(int i = 0; i < len; i++)
       vector[i] *= scaler;
}



void addVectors(double* vectorOne, double* vectorTwo, int len){
    for(int i = 0; i < len; i++)
        vectorOne[i] += vectorTwo[i];
}


void subtractVectors(double* vectorOne, double* vectorTwo, int len){
    for(int i = 0; i < len; i++)
        vectorOne[i] -= vectorTwo[i];
}


void addScaled(double* vectorOne, double* vectorTwo, int len, double scalar){
    for(int i = 0; i < len; i++)
        vectorOne[i] += (scalar * vectorTwo[i]);
}

void subtractScaled(double* vectorOne, double* vectorTwo, int len, double scalar){
    for(int i = 0; i < len; i++)
        vectorOne[i] -= (scalar * vectorTwo[i]);
}


