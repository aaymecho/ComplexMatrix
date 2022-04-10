#include "matrix.h"

Matrix TEMPORARY(4,3);


//Dynamic allocation/dealloaction---------------------------------------
Matrix::Matrix(int r, int c)
{
    matrixPtr = new Complex[r*c];
    row = r;
    col = c;
    cout << "Allocated array with size " << r*c << endl;
    invalidMatrix = false;
};

Matrix::~Matrix() {
    if (matrixPtr!=NULL) {
        delete matrixPtr;
        matrixPtr = NULL;
    }
    cout << "Deallocated array with size " << row*col << endl;
    row = 0;
    col = 0;
};

Matrix::Matrix(Matrix& c) {
    row = c.row;
    col = c.col;
    matrixPtr = new Complex[row*col];
    for (int i = 0; i < row*col; i++) {
        matrixPtr[i] = c.matrixPtr[i];
    }
    cout << "Allocated array with size " << row*col << endl;
};



//Overload functions------------------------------------------------------
Matrix& Matrix::operator=(Matrix& c) {
    for (int i=0; i<row*col; i++) {
        this->getMatrixPtr()[i] = c.getMatrixPtr()[i];
    }
    this->setInvalidMatrix(c.getInvalidMatrix());
    return (*this);
};

Complex& Matrix::operator()(int r, int c) {
    position = (row*(r - 1) + c) - 1;
    return this->getMatrixPtr()[position];
};

ostream& operator<<(ostream& out, Matrix& object) {
    if (object.getInvalidMatrix() == true) {
        return out << "Matrix Mismatch Error!" << endl << "This matrix has zero elements" << endl;
    } else {
        int checkCol=0;
        for (int i=0; i<object.getRow()*object.getCol(); i++) {
            out << object.getMatrixPtr()[i] << setw(5);
            checkCol++;
            if (checkCol == object.getCol()) {
                out << endl;
                checkCol = 0;
            }
        }
        return out << endl;
    }
};

ostream& Matrix::printMatrix() {
    if (this->getInvalidMatrix() == true) {
        return cout << "Matrix Mismatch Error!" << endl << "This matrix has zero elements" << endl;
    } else {
        int checkCol=0;
        for (int i=0; i<getRow()*getCol(); i++) {
            cout << getMatrixPtr()[i] << setw(5);
            checkCol++;
            if (checkCol == getCol()) {
                cout << endl;
                checkCol = 0;
            }
        }
        return cout << endl;
    }
};

Matrix& Matrix::operator~() {
    (*this).transpose();
    return (*this);
};

//Matrix operations-------------------------------------------------------
Matrix& Matrix::operator+ (Matrix& c) {
    if (this->getRow() == c.getRow() && this->getCol() == c.getCol()) {
        for (int i=0; i<this->getRow()*this->getCol(); i++) {
            this->getMatrixPtr()[i] = this->getMatrixPtr()[i] + c.getMatrixPtr()[i];
        }
    } else {
        invalidMatrix = true;
    }
    return *(this);
};


void Matrix::transpose() {
    Matrix Transpose(row, col);
    for (int i=0; i<row; ++i) {
        for (int j=0; j<col; ++j) {
            int indexOne = i*col+j; //original index
            int indexTwo = (j*row)+i; //transpose index

            Transpose.getMatrixPtr()[indexOne] = (*this).getMatrixPtr()[indexTwo];
        }
    }
    (*this) = Transpose;
};

Matrix& Matrix::operator*(Matrix& m) {
    if (col != m.getRow()) {
        TEMPORARY.setInvalidMatrix(true);
        return (TEMPORARY);
    } else {
        Matrix Multiply(row, m.getCol());
        for (int i=0; i<row; ++i) {
            for (int j=0; j<m.getCol(); ++j) {
                for (int k=0; k<col; ++k) {
                    Multiply.getMatrixPtr()[i*m.getCol()+j] =  Multiply.getMatrixPtr()[i*m.getCol()+j] + (*this).getMatrixPtr()[i*col+k] * m.getMatrixPtr()[k*m.getCol()+j];
                }
            }
        }
        int zeroMatrix = 0;
        for (int i=0; i<Multiply.getRow()*Multiply.getCol(); i++) {
            if (Multiply.getMatrixPtr()[i].getReal() == 0 && Multiply.getMatrixPtr()[i].getImag() == 0) {
                zeroMatrix++;
            }
            if (zeroMatrix == Multiply.getRow()*Multiply.getCol()) {
                Multiply.setInvalidMatrix(true);
            }
        }
        (TEMPORARY) = Multiply;
        return (TEMPORARY);
    }
};



Matrix& operator*(Complex c, Matrix& m) {
    for (int i=0; i<m.getRow()*m.getCol(); i++) {
        TEMPORARY.getMatrixPtr()[i] = c * m.getMatrixPtr()[i];
    }
    return TEMPORARY;
};

Matrix& operator*(Matrix& m, Complex c) {
    for (int i=0; i<m.getRow()*m.getCol(); i++) {
        TEMPORARY.getMatrixPtr()[i] = c * m.getMatrixPtr()[i];
    }
    return TEMPORARY;
};

Matrix& Matrix::operator!() {
    for (int i=0; i<row; ++i) {
        for (int j=0; j<col; ++j) {
            int indexOne = i*col+j; //original index
            int indexTwo = (j*row)+i; //transpose index

            TEMPORARY.getMatrixPtr()[indexOne] = (*this).getMatrixPtr()[indexTwo];
        }
    }
    for (int i=0; i<getRow()*getCol(); i++) {
        TEMPORARY.getMatrixPtr()[i].setImag(-TEMPORARY.getMatrixPtr()[i].getImag());
    }
    (*this) = TEMPORARY;
    return (*this);
}

Matrix& Matrix::operator-(Matrix& m) {
    if (row!=m.getRow() && col != getCol()) {
        invalidMatrix = true;
    }
    else {
        for (int i=0; i<this->row*this->col; i++) {
            TEMPORARY.getMatrixPtr()[i] = this->getMatrixPtr()[i] - m.getMatrixPtr()[i];
        }
    }
    return TEMPORARY;
};