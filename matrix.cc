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
// ------------------------------------------------------------------------

