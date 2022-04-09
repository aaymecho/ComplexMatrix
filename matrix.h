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
        Complex* getMatrixPtr() { return matrixPtr; };
        Matrix& operator=(Matrix&);
        Complex& operator()(int r, int c);
        friend ostream& operator<<(ostream&, Matrix&);

        //setters and getters
        int getPosition() { return position; };
        int getRow() { return row; };
        int getCol() { return col; };
        ostream& printMatrix();
        void transpose();
        void setMatrixPtr(Complex* Ptr) { matrixPtr = Ptr;};
        
    private:
        Complex* matrixPtr;
        int row;
        int col;
        int position;
        bool invalidMatrix;
};
#endif