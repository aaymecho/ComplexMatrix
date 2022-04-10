#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include "complex.h"
#include <string>
#define MATRIX_FIELD 30

class Matrix {
    public:
        Matrix(int r, int c); //constructor
        Matrix(Matrix&); //copy constructor
        ~Matrix(); //destructor

        //matrix operations and overloads
        Complex* getMatrixPtr() { return matrixPtr; };
        Matrix& operator=(Matrix&);
        Complex& operator()(int r, int c);
        Matrix& operator*(Matrix&);
        friend ostream& operator<<(ostream&, Matrix&);
        Matrix& operator~();
        Matrix& operator+(Matrix&);
        Matrix& operator*(Complex&);


        //setters and getters
        int getPosition() { return position; };
        int getRow() { return row; };
        int getCol() { return col; };
        void setCol(int c) { col = c; };
        void setRow(int r) { row = r; };
        void setPosition(int p) { position = p; };


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