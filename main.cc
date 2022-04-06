#include <iostream>
#include <iomanip>
#include "complex.h"



int main()
{
//first let's declare an array of complex numbers
Complex a[5];
Complex result[5];
Complex test1(4.5,6.5);

//I will fill these with data
a[0].setComplex(3,4);
a[1].setComplex(-1,3);
a[2].setComplex(-1.23,-9.83);
a[3].setComplex(3.14,-98.3);
a[4].setComplex(2.71,1.61);

//Now print the data in polar format 
cout << "\nPrint Array of Complex Numbers in Polar Format" << endl;
for (int i = 0; i < 5; i++)
{
   a[i].displayPolar();
}

//Now test the add function
cout << "\nTesting add operator a[0] + a[1]" << endl;
result[0] = a[0] + a[1];
result[0].displayRect();

//Now test the sub function
cout << "\nTesting subtract operator a[1] - a[2]" << endl;
result[1] = a[1] - a[2];
cout << result[1] << endl;
//Now test the multiply function
cout << "\nTesting multiply operator a[2] * a[3]" << endl;
result[2] = a[2] * a[3];
cout << result[2] << endl;
result[2].displayRect();

//Now test the divide function
cout << "\nTesting divide operator a[3] / a[4]" << endl;
result[3] = a[3] / a[4];
result[3].displayRect();

//Now test the divide by zero 
cout << "\nTesting divide by zero a[4] / (0)" << endl;
result[4] = a[4] / Complex(0,0);
cout << result[4] << endl;

//Now display the results array in polar format 
cout << "\nNow display the results array in polar format" << endl;
for (int i = 0; i < 5 ; i++)
{
        result[i].displayPolar();
}
}