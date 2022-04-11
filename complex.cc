#include "complex.h" 

//constructor setup
Complex::Complex() {
    cout << fixed;
    cout<< setprecision(6);
    real = 0;
    imag = 0;
    NaN = false;
};

Complex::Complex(double inputReal, double inputImag) {
    real = inputReal;
    imag = inputImag;
    NaN = false;
};

Complex::Complex(double inputReal) {
    real = inputReal;
    imag = 0;
    NaN = false;
};

//setters and getters setup--------------------------------------
void Complex::setNaN(bool inputNaN) {
    NaN = inputNaN;
};
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

bool Complex::getNaN() {
    return NaN;
}
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
//-------------------------------------------------------------------

ostream& operator<<(ostream& out, Complex& object) {

    if (object.getNaN() == true) {
        object.setNaN(false);
        return out << "NaN" << endl;
    } else {
        return out << object.getReal() << " + " << object.getImag() << "j\t";
    }
};

ostream& Complex::displayPolar() {
    double amp = sqrt(pow(imag, 2) + pow(real, 2));
    double angle;
    if (NaN == false) {
        if (real > 0) {
            angle = atan(imag/real);
        }
        else if (real < 0 && imag > 0) {
            angle = atan(imag/real) + M_PI;
        }
        else if (real < 0 && imag < 0) {
            angle = atan(imag/real) - M_PI;
        }
        else {
            angle = 0;
        }
        return cout << amp << " < " << angle << endl;
    }
    else {
        return cout << "NaN" << endl;
    }
};

ostream& Complex::displayRect() {
    if (NaN == true) {
        cout << "NaN" << endl;
    } 
    else if (imag == 0 && real == 0) {
        cout << real << endl;
    } 
    else if (imag == 0 && real != 0) {
        cout << real << endl;
    } 
    else if (real == 0 && imag != 0) {
        cout << imag << endl;
    } 
    else {
        cout << real << " + " << imag << "j" << endl;
    }
    return cout;
};