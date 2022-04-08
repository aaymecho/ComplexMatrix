#include "matrix.h"

//Dynamic allocation/dealloaction---------------------------------------
Matrix::Matrix(int r, int c)
{
    matrixPtr = new Complex*[r*c];
    row = r;
    col = c;
    for (int i = 0; i < r*c; i++)
    {
        matrixPtr[i] = NULL;
    }
    cout << "Allocated array with size " << r*c << endl;
};

Matrix::~Matrix()
{
    delete [] matrixPtr;
    row = 0;
    col = 0;
    cout << "Deallocated array with size " << row*col << endl;
};

Matrix& Matrix::operator=(Complex& c) {
    int position = (row(x - 1) + y) - 1;
    getMatrixPtr()[position]->setReal(c.getReal());
    getMatrixPtr()[position]->setImag(c.getImag());
    return (*this); 
};
// -----------------------------------------------------------------------