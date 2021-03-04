#ifndef LAB2_COMPLEX_H
#define LAB2_COMPLEX_H

#include <cmath>
#include <iostream>

using std :: cout;
using std :: string;

class Complex{

private:
    double re;
    double im;

public:
    /*
    * Constructor without arguments
    */
    Complex();

    /*
    * Constructor with arguments
    */
    Complex(double re, double im);

    /*
    / Getter; returns: re attribute
    */
    double getReal();

    /*
    / Getter; returns: im attribute
    */
    double getImag();

    /*
    / Add the alfa constant to the number.
    */
    Complex add(double alfa);

    /*
    / Multiply the complex number with the alfa constant.
    */
    Complex mult(double alfa);

    /*
    / Divide the complex number by a constant alfa.
    */
    Complex quot(double alfa);

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
    / Function to override / operator ( so that one can divide one Complex object to another)
    */
    friend Complex operator/(const Complex &c1, const Complex &c2);

    /*
    / Returns the absolute value of the current instance of Complex
    */
    double abs();

    /*
    / Returns the Complex object smaller between the two ( comparison by absolute value )
    */
    friend bool operator<(Complex &c1, Complex &c2);

    /*
    / Functuin to display the complex number in its polar form
    */
    void compute_polar();
};

#endif // COMPLEX_H
