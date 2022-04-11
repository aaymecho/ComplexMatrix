#include "complex.h" 

//constructor setup
Complex::Complex() {
    cout << fixed;
    cout<< setprecision(6);
    real = 0;
    imag = 0;
    NaN = false;
};

Complex::Complex(const double inputReal, const double inputImag) {
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
void Complex::setNaN(const bool inputNaN) {
    NaN = inputNaN;
};
void Complex::setReal(const double value) {
    real = value;
};

void Complex::setImag(const double value) {
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

void Complex::setComplex(const double realInput, const double imagInput) {
    real = realInput;
    imag = imagInput;
};
//-------------------------------------------------------------------

ostream& operator<<(ostream& out, Complex& object) {
    string result;
    if (object.getNaN() == true) {
        object.setNaN(false);
        out << "NaN" << endl;
    } 
    else if (object.getImag() == 0 && object.getReal() == 0){
        result = to_string(object.getReal());
    }
    else if (object.getReal() != 0 && object.getImag() == 0) {
            result =  to_string(object.getReal());
        }
    else if (object.getImag() != 0 && object.getReal() == 0) {
        result =  to_string(object.getImag()) + "j";
    }

    else {
        result = to_string(object.getReal()) + " + " + to_string(object.getImag()) + "j";

        // out << object.getReal() << " + " << object.getImag() << "j" ;//<< setw(20);
    }
    out << result << setw(20);
    return out;
};

ostream& Complex::displayPolar() {
    double amp = sqrt(pow(imag, 2) + pow(real, 2));
    double angle;
    if (real == 0 && imag == 0) {
        NaN = true;
    }
    if (real == 0 && imag != 0) {
        real = 1;
    }
    if (real != 0 && imag == 1) {
        imag = 1;
    }
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
     string lol;
    if (NaN == true) {
        lol =  "NaN";
    } 
    else {
        lol = to_string(real) + " + " + to_string(imag) + "j";
    }
    return cout << lol;
};

// ostream& Complex::displayRectTwo(ostream& in) {
//     if (NaN == true) {
//         in << "NaN" << endl;
//     } 
//     else if (imag == 0 && real == 0) {
//         in << real << endl;
//     } 
//     else if (imag == 0 && real != 0) {
//         in << real << endl;
//     } 
//     else if (real == 0 && imag != 0) {
//         in << imag << endl;
//     } 
//     else {
//         in << real << " + " << imag << "j" << endl;
//     }
//     return in;
// };