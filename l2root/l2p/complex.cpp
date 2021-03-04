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

// aici de ce nu trebuie sa ii precizez namespace ul ????
Complex operator+(const Complex &c1, const Complex &c2)
{
    return Complex(c1.re + c2.re, c1.im + c2.im);
}

/*
Complex operator+(const Complex &c2)
{
    return Complex(re + c2.re, im + c2.im);
}
*/



Complex operator-(const Complex &c1, const Complex &c2)
{
    return Complex(c1.re - c2.re, c1.im - c2.im);
}
/*
Complex operator-(const Complex &c2)
{
    return Complex(re - c2.re, im - c2.im);
}
*/



Complex operator*(const Complex &c1, const Complex &c2)
{
    return Complex(c1.re * c2.re - c1.im * c2.im, c1.re * c2.im + c1.im * c2.re);
}
/*
Complex :: Complex operator*(const Complex &c2)
{
    return Complex(re * c2.re - im * c2.im, re * c2.im + im * c2.re);
}
*/
double Complex::abs()
{
    //return sqrt(this->re * this->re + this->im * this->im );
    //return sqrt(this.re * this.re + this.im * this.im );
    return sqrt(re * re + im * im );
}




/*
Complex operator/(const Complex &c1, const Complex &c2)
{
    if (!c2.re && !c2.im) throw ("Impartire la zero");
    return Complex(c1.re - c2.re, c1.im - c2.im);
}
*/



/*
void operator+=(Complex &c1, const Complex &c2)
//Complex operator+=(Complex &c1, const Complex &c2)
//Complex operator+=(const Complex &c2)
*/
/*
void Complex :: operator+=(const Complex c1, const Complex &c2)
{
    //this->re += this->re + re;
    //this->im += this->im + im;

    c1.re += c2.re;
    c1.im += c2.im;
/*
    re += c2.re;
    im += c2.im
    //return *this;

}
*/



/*
Complex operator<(const Complex &c1, const Complex &c2)
{
    return c1.abs() < c2.abs() ? c1 : c2;
}
*/


bool operator<(Complex &c1, Complex &c2)
{
    return ( c1.abs() < c2.abs() );
}
/*
Complex compute_polar(const &c1) // stim ca
{
    return polar( c1.abs(), atan(c1.re / c2.re) )
}
*/


void Complex :: compute_polar()
{
    double abs = this->abs();
    cout << abs << "("<< re / abs  << " + i * " << im / abs << ")" << '\n';
}

