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


constexpr double det2by2(double matrix2x2[2][2]){
        double result =  (matrix2x2[0][0] * matrix2x2[1][1]) - (matrix2x2[0][1] * matrix2x2[1][0]);
        return result;
}

void cross( double (&vectorOne)[3], double (&vectorTwo)[3], double (&output)[3]){
        
	double matrix[2][2] = {{1,1},{1,1}};
        
	for(int i = 0; i < 3; i++){
            
	    switch(i){

                case 0:
                        matrix[0][0] = vectorOne[1];
                        matrix[0][1] = vectorOne[2];
                        matrix[1][0] = vectorTwo[1];
                        matrix[1][1] = vectorTwo[2];
                        output[0] = det2by2(matrix);
                        break;

                case 1:
                        matrix[0][0] = vectorOne[0];
                        matrix[0][1] = vectorOne[2];
                        matrix[1][0] = vectorTwo[0];
                        matrix[1][1] = vectorTwo[2];
                        output[1] = -det2by2(matrix);
                        break;

                case 2:
                        matrix[0][0] = vectorOne[0];
                        matrix[0][1] = vectorOne[1];
                        matrix[1][0] = vectorTwo[0];
                        matrix[1][1] = vectorTwo[1];
			output[2] = det2by2(matrix);
                        break;                  
	                                               };

        }

}



#endif
