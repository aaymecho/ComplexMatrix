#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include "complex.h"
#include <string>
#define MATRIX_FIELD 30

class Matrix {
    public:
        Matrix(int r, int c); //constructor
        ~Matrix(); //destructor
        Complex** getMatrixPtr() { return matrixPtr; };
    private:
        Complex** matrixPtr;
        int row;
        int col;
};
#endif