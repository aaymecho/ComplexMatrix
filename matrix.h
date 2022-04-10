#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include "complex.h"
#include <string>
#define MATRIX_FIELD 30

class Matrix;
Matrix& operator*(Complex, Matrix &);
Matrix& operator*(Matrix &, Complex);

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
        friend Matrix& operator*(Complex, Matrix &);
        friend Matrix& operator*(Matrix &, Complex);
        Matrix& operator!();
        Matrix& operator-(Matrix&);



        //setters and getters
        int getPosition() { return position; };
        int getRow() { return row; };
        int getCol() { return col; };
        void setCol(int c) { col = c; };
        void setRow(int r) { row = r; };
        void setPosition(int p) { position = p; };
        bool getInvalidMatrix() { return invalidMatrix; };
        void setInvalidMatrix(bool i) { invalidMatrix = i; };


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