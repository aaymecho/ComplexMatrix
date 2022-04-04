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
    sum.real = (getReal() * input.getReal()) - (getImag() * input.getImag());
    sum.imag = (getReal() * input.getImag()) + ( getImag() * input.getReal());
    return sum;
};

Complex Complex::operator/(Complex input) {
    Complex sum;
    if (input.getReal() == 0 && input.getImag() == 0) {
        sum.NaN = true;
    }
    else {
        sum.NaN = false;
        sum.real = (((real)*(input.real))+((imag)*(input.imag)))/(pow(input.real,2)+pow(input.imag,2));
        sum.imag = (((input.real)*(imag))-((real)*(input.imag)))/(pow(input.real,2)+pow(input.imag,2));    }
    return sum;
};

void Complex::setComplex(double realInput, double imagInput) {
    real = realInput;
    imag = imagInput;
};

bool Complex::getNaN() {
    return NaN;
}
//-------------------------------------------------------------------

ostream& operator<<(ostream& out, Complex& object) {

    if (object.getNaN() == true) {
        return out << "NaN" << endl;
    } else {
        return out << object.getReal() << " " << object.getImag() << "j" << endl;
    }
};

ostream& Complex::displayPolar() {
    double amp = sqrt(pow(imag, 2) + pow(real, 2));
    double angle;
    if (real < 0) {
        angle = atan(real/imag);
    }
    else if (real > 0) {
        angle = atan(real/imag) + 2;
    }
    else {
        angle = 0;
    }
    if (NaN == true) {
        return cout << "NaN" << endl;
    } else {
        return cout << amp << " < " << angle << endl;
    }
};

ostream& Complex::displayRect() {
    if (NaN == true) {
        return cout << "NaN" << endl;
    } else {
        return cout << real << " + " << imag << "j" << endl;
    }
};