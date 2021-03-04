#include "complex.h"
Complex::Complex()
{
    this->re = 0;
    this->im = 0;
}

Complex::Complex(double re, double im)
{
    this->re = re;
    this->im = im;
}

double Complex::getReal()
{
    return re;
}

double Complex::getImag()
{
    return im;
}

Complex Complex::add(double alfa)
{
    return Complex(re + alfa, im);
}

Complex Complex::mult(double alfa)
{
    return Complex(re * alfa, im * alfa);
}

Complex Complex::quot(double alfa)
{
    if (!alfa) throw "Division by zero!";
    return Complex(re / alfa, im / alfa);
}

Complex operator+(const Complex &c1, const Complex &c2)
{
    return Complex(c1.re + c2.re, c1.im + c2.im);
}

Complex operator-(const Complex &c1, const Complex &c2)
{
    return Complex(c1.re - c2.re, c1.im - c2.im);
}

Complex operator*(const Complex &c1, const Complex &c2)
{
    return Complex(c1.re * c2.re - c1.im * c2.im, c1.re * c2.im + c1.im * c2.re);
}

Complex operator/(const Complex &c1, const Complex&c2)
{
    if (!c2.re && !c2.im) throw "~~!!Exception occured! Division by zero!!~~";
    return Complex( (c1.re * c2.re - c1.im * c2.im) / (c2.re * c2.re + c2.im * c2.im), (c1.re * c2.im + c2.im * c2.re) / (c2.re * c2.re - c1.im * c1.im) );
}

double Complex::abs()
{
    return sqrt(re * re + im * im );
}

bool operator<(Complex &c1, Complex &c2)
{
    return ( c1.abs() < c2.abs() );
}

void Complex :: compute_polar()
{
    double abs = this->abs();
    cout << abs << "("<< re / abs  << " + i * " << im / abs << ")" << '\n';
}

