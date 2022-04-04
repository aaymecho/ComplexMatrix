#include "complex.h" 

//constructor setup
Complex::Complex() {
    real = 0;
    imag = 0;
    NaN = false;
};

Complex::Complex(double inputReal, double inputImag) {
    real = inputReal;
    imag = inputImag;
};

Complex::Complex(double inputReal) {
    real = inputReal;
    imag = 0;
};

//setters and getters setup--------------------------------------
void Complex::setReal(double value) {
    real = value;
};

void Complex::setImag(double value) {
    imag = value;
};

double Complex::getReal() {
    return real;
};

double Complex::getImag() {
    return imag;
};
//end of setters and getters-------------------------------------


//operator overloading setup-------------------------------------------
Complex Complex::operator+(Complex input) {
    Complex sum;
    sum.real = getReal() + input.getReal();
    sum.imag = getImag() + input.getImag();
    return sum;
};

Complex Complex::operator-(Complex input) {
    Complex sum;
    sum.real = getReal() - input.getReal();
    sum.imag = getImag() - input.getImag();
    return sum;
};

Complex Complex::operator*(Complex input) {
    Complex sum;
    sum.real = getReal() * input.getReal();
    sum.imag = getImag() * input.getImag();
    return sum;
};

Complex Complex::operator/(Complex input) {
    Complex sum;
    if (input.getReal() == 0 && input.getImag() == 0) {
        sum.NaN = true;
    }
    else {
        sum.real = getReal() / input.getReal();
        sum.imag = getImag() / input.getImag();
    }
    return sum;
};

void Complex::setComplex(double realInput, double imagInput) {
    real = realInput;
    imag = imagInput;
};
//-------------------------------------------------------------------

void Complex::displayRect() {
    fstream myFile;
    myFile.open("output.txt", ios::app);
    myFile << real << " " << imag << "j" << endl;
    myFile.close();
};

void Complex::displayPolar() {
    double amp = sqrt(pow(imag, 2) + pow(real, 2));
    double angle = atan(imag/real);
    fstream myFile;
    myFile.open("output.txt", ios::app);
    myFile << amp << " < " << angle << endl;
    myFile.close();
};