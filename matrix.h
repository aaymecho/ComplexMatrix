#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include "complex.h"
#include <string>
#define MATRIX_FIELD 30

class Matrix;

ostream& operator<< (ostream &, const Matrix &);
Matrix operator*(Complex, Matrix &);

class Matrix {
    friend ostream& operator<< (ostream &, const Matrix &);
    friend Matrix operator*(Complex, Matrix &)
    public:
        Complex & operator()(int, int);
    private:
}
#endif