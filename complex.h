#ifndef COMPLEX_H
#define COMPLEX__H

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

#define ROW 2;

class Complex {
    
    public:
        //constructors
        Complex();
        Complex(const double, const double);
        Complex(double);

        //setters and getters
        void setReal(const double);
        double getReal();
        void setImag(const double);
        double getImag();
        void setComplex(const double, const double);
        bool getNaN();
        void setNaN(const bool);

        //operator overloading
        Complex operator+(Complex);
        Complex operator-(Complex);
        Complex operator*(Complex);
        Complex operator/(Complex);
        friend ostream& operator<<(ostream&, Complex&);


        //polar and rectangular
        
        ostream& displayRect();
        ostream& displayRectTwo(ostream&);
        ostream& displayPolar();
        
    private:
        double real;
        double imag;
        bool NaN;
};
#endif