#pragma once

#ifndef __errors_H_
#define __errors_H_


#include <iostream>
#include <fstream>
#include <exception>



using namespace std;



/*
 * Defining Custom Errors to Control for
 *
 * Problems with attemps to call my matrix operations
 *
 * */



//custom exeption for an attempt to
//call a method which will give
//misleading results for non-square
//matricies
struct mustBeSquare : public exception
{

   const char* what() const throw(){

       return "This Method Requires a Square Matrix!!!!!!!";
   }

};




struct wrongDimentions : public exception
{

   const char* what() const throw(){

       return "This Method Should Not be Used with Those Dimentions!!!!!!!";
   }

};





//custom exception for attempts to take
//a cross product in any other dimention
//space than R3
struct notR3 : public exception
{

   const char* what() const throw(){

       return "You Cannot Take a Cross Product Using Vectors Which are not 3 Dimentional!!!!!!";
   }

};


struct out_of_bounds : public exception
{

   const char* what() const throw(){

       return "A Row or Column involved in this operation is out of bounds of the matrix in question";
   }

};


#endif

