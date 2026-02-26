#pragma once

#ifndef __rowOps_H_
#define __rowOps_H_



template<int R, int C>
void extractRow(int rowIndex, double (&original)[R][C], double rowVector[C]){

        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if(i+1 == rowIndex) rowVector[j] = original[i][j];
            }
	}

}


template<int R, int C>
void replaceRow(int rowIndex, double (&original)[R][C], double rowVector[C]){

        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if(i+1 == rowIndex)  original[i][j] = rowVector[j];
            }
        }
}



template<int R, int C>
void extractColumn(int columnIndex, double (&original)[R][C], double columnVector[R])
{

        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if(j+1 == columnIndex) columnVector[i] = original[i][j];
            }
        }

}




template<int R, int C>
void replaceColumn(int columnIndex, double (&original)[R][C], double columnVector[R])
{

        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if(j+1 == columnIndex) original[i][j] = columnVector[i];
            }
        }

}




template<unsigned R, unsigned C>
void swapRows(int rowOne, int rowTwo, double (&original)[R][C], double (&swapped)[R][C])
{
    double tempRow1[C];
    double tempRow2[C];
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(i+1 == rowOne) tempRow1[j] = original[i][j];
            if(i+1 == rowTwo) tempRow2[j] = original[i][j];

            else{swapped[i][j] = original[i][j];}
        }
    }


    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(i+1 == rowOne) swapped[i][j] = tempRow2[j];
            if(i+1 == rowTwo) swapped[i][j] = tempRow1[j];
        }
    }
}

/*
 *
 * Remember to Make a swapCols
 *
 *
 * */




#endif
