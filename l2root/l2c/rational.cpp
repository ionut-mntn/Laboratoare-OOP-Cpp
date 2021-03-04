#include "Rational.h"

Rational::Rational(int m, int n)
{
    if(!n) throw "Division by zero!";
    this->m = m;
    this->n = n;
}

int Rational::getNom() const
{
    return m;
}

int Rational::getDenom () const
{
    return n;
}

void Rational::setNom(int value)
{
    m = value;
}

void Rational::setDenom(int value)
{
    if(!n) throw "Division by zero!";
    n = value;
}

Rational Rational::simplify()
{
    int a = m, b = n;
    int r;
    while(b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    int gcd = a;
    return Rational(m / gcd, n / gcd);
}

Rational operator+(const Rational &r1, const Rational &r2)
{
    int nominator = r1.getNom() * r2.getDenom() + r1.getDenom() * r2.getNom();
    int denominator = r1.getDenom() * r2.getDenom();
    return Rational(nominator, denominator).simplify();
}

Rational operator-(const Rational &r1, const Rational &r2)
{
    int nominator = r1.getNom() * r2.getDenom() - r1.getDenom() * r2.getNom();
    int denominator = r1.getDenom() * r2.getDenom();
    return Rational(nominator, denominator).simplify();
}

Rational operator*(const Rational &r1, const Rational &r2)
{
    return Rational(r1.getNom() * r2.getNom(), r1.getDenom()* r2.getDenom()).simplify();
}

Rational operator/(const Rational &r1, const Rational &r2)
{
    if (!r2.getNom()) throw "Divison by zero";
    return Rational(r1.getNom()*r2.getDenom(), r1.getDenom()*r2.getNom()).simplify();
}

/*
Rational& operator+=(const Rational &r1, const Rational &r2)
{
    r1.getNom() = r1.getNom() * r2.getDenom() + r1.getDenom() * r2.getNom();
    r2.getDenom() = r1.getDenom() * r2.getDenom();
    return *this
}
*/
/*
Rational& operator+=(const Rational &r2)
{
    this->setNom(this->getNom() * r2.getDenom() + this.getDenom() * r2.getNom());
    this->setDenom(this->getDenom() * r2.getDenom());
    return *this
}
*/
inline bool operator<(const Rational &r1, const Rational &r2)
{
    return ( r1.getNom() * r2.getDenom() < r2.getDenom() * r2.getNom() );
}

Rational Rational::add(int p, int q) //             m / n + p / q = ( m * q + n * p ) / p * n
{
    return Rational(m * q + n * p, n * q).simplify();
}

Rational Rational::sub(int p, int q) //             m / n - p / q = ( m * q - n * p ) / p * n
{
    return Rational(m * q - n * p, n * q).simplify() ;
}

Rational Rational::mul(int p, int q)
{
    return Rational(m * p, n * q).simplify();
}

Rational Rational::quot(int p, int q)
{
    if (!p) throw "Division by zero!";
    else return Rational(m * q, n * p).simplify();
}
