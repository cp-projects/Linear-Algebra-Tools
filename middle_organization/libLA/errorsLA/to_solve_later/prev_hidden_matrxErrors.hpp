#ifndef __matrixErrors_H_
#define __matrixErrors_H_

struct mustBeSquare : public std::exception mustBeSquare (std::exception::what(), std::exception::throw());

struct wrongDimentions : public exception;

struct notR3 : public exception;

#endif
