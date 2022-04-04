#ifndef COMPLEX_H
#define COMPLEX__H

#include <iostream>
#include <cmath>
#include <iomanip>
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
        bool getNaN();

        //operator overloading
        Complex operator+(Complex);
        Complex operator-(Complex);
        Complex operator*(Complex);
        Complex operator/(Complex);
        friend ostream& operator<<(ostream&, Complex&);


        //polar and rectangular
        
        ostream& displayRect();
        ostream& displayPolar();
        
    private:
        double real;
        double imag;
        bool NaN;
};
#endif