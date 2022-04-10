#include "matrix.h"

//Dynamic allocation/dealloaction---------------------------------------
Matrix::Matrix(int r, int c)
{
    matrixPtr = new Complex[r*c];
    row = r;
    col = c;
    cout << "Allocated array with size " << r*c << endl;
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
    
}



//Overload functions------------------------------------------------------
Matrix& Matrix::operator=(Matrix& c) {
    for (int i=0; i<row*col; i++) {
        this->getMatrixPtr()[i] = c.getMatrixPtr()[i];
    }
    return (*this);
};

Complex& Matrix::operator()(int r, int c) {
    position = (row*(r - 1) + c) - 1;
    return this->getMatrixPtr()[position];
};

ostream& operator<<(ostream& out, Matrix& object) {
    if (false) {
        return out << "NaN" << endl;
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
    if (false) {
        return cout << "NaN" << endl;
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
    this->transpose();
    return *(this);
};

//Matrix operations-------------------------------------------------------
// Matrix& Matrix::operator+ (Matrix& c) {
//     Matrix add = Matrix(row, col);
//     add.setMatrixPtr(new Complex[row*col]);
//     if (getRow() == c.getRow() && getCol() == c.getCol()) {
//         for (int i=0; i<row*col; i++) {
//             add.getMatrixPtr()[i] = this->getMatrixPtr()[i] + c.getMatrixPtr()[i];
//         }
//         (*this) = add;
//     } else {
//         cout << "Matrices are not the same size" << endl;
//         // delete [] add.getMatrixPtr();
//     }
//     return (*this);
// };

void Matrix::transpose() {
    Matrix Transpose(row, col);
    Transpose.setMatrixPtr(new Complex[row*col]);
    for (int i=0; i<row; ++i) {
        for (int j=0; j<col; ++j) {
            int indexOne = i*col+j; //original index
            int indexTwo = (j*row)+i; //transpose index

            Transpose.getMatrixPtr()[indexOne] = (*this).getMatrixPtr()[indexTwo];
        }
    }
    (*this) = Transpose;
    // delete [] Transpose.getMatrixPtr();
};

Matrix& Matrix::operator*(Matrix& m) {
    if (col != m.getRow()) {
        invalidMatrix = true;
        return (*this);
    } else {
        Matrix Multiply(row, m.getCol());
        Multiply.setMatrixPtr(new Complex[row*m.getCol()]);
        for (int i=0; i<row; ++i) {
            for (int j=0; j<m.getCol(); ++j) {
                for (int k=0; k<col; ++k) {
                    Multiply.getMatrixPtr()[i*m.getCol()+j] =  Multiply.getMatrixPtr()[i*m.getCol()+j] + (*this).getMatrixPtr()[i*col+k] * m.getMatrixPtr()[k*m.getCol()+j];
                }
            }
        }
        (*this) = Multiply;
        return (*this);
    }
};

