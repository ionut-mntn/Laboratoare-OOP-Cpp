#ifndef LAB2_COMPLEX_H
#define LAB2_COMPLEX_H
#include <cmath>
#include <iostream>

//#include <complex>
//#include <string>
using std :: cout;
using std :: string;

class Complex{

private:
    double re;
    double im;

public:
    /*
    * Constructor with arguments
    */
    Complex();

    /*
    * Constructor with arguments
    */
    Complex(double re, double im);

    /*
    / Getter: re attribute
    */
    double getReal();

    /*
    / Getter: im attribute
    */
    double getImag();

    /*
    / Function to override + operator ( so that one can add two Complex objects )
    */
    friend Complex operator+(const Complex &c1, const Complex &c2);

    /*
    / Function to override - operator ( so that one can substract two Complex objects )
    */
    friend Complex operator-(const Complex &c1, const Complex &c2);

    /*
    / Function to override * operator ( so that one can multiply two Complex objects )
    */
    friend Complex operator*(const Complex &c1, const Complex &c2);

    /*
    / Function to override / operator ( so that one can substract two Complex objects )
    */
    //friend Complex operator/(const Complex &c1, const Complex &c2);

    //friend Complex operator+=(Complex &c1, const Complex &c2);

    /*
    / Returns the absolute value of the current instance of Complex
    */
    double abs();

    /*
    / Returns the Complex object smaller between the two ( comparison by absolute value )
    */
    friend bool operator<(Complex &c1, Complex &c2);

    //friend Complex operator+=(const Complex &c1, const Complex &c2);

    /*
    / Displays the complex number in its polar form
    */
    void compute_polar();
};

    //double my_sqrt(double x);
/*
double my_abs(void *numar)
{
    while(numar)
}
*/
#endif // COMPLEX_H
