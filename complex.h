#ifndef COMPLEX_H
#define COMPLEX__H

#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;

#define ROW 2;

class Complex {
    
    public:
        //constructors
        Complex();
        Complex(double, double);
        Complex(double);

        //setters and getters
        void setReal(double);
        double getReal();
        void setImag(double);
        double getImag();
        void setComplex(double, double);

        //operator overloading
        Complex operator+(Complex);
        Complex operator-(Complex);
        Complex operator*(Complex);
        Complex operator/(Complex);
        Complex& operator[](int);
        friend ostream& operator<<(ostream&, Complex&);


        //polar and rectangular
        void displayRect();
        void displayPolar();
        
    private:
        double real;
        double imag;
        bool NaN;
};
ostream& operator<<(ostream& out, Complex& object) {
    out << object.getReal() << " " << object.getImag();
    return out;
};
#endif