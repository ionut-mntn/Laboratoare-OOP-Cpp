#ifndef LAB2_RATIONAL_H
#define LAB2_RATIONAL_H

#include <iostream>
#include <algorithm>
class Rational{
private:
    int m, n;
public:
    /*
    / Constructor
    */
    Rational(int m, int n);

    // observatie pentru mine( a nu se lua in considerare )
    // am pus const la astea 2 care urmeaza(gettere)
    // pentru ca altfel, as fi apelat:
    // o metoda non-const pe un obiect const( prin
    // 'obiect' referindu ma aici la ce primeste
    // functia aia ca parametrii ). Eu ce faceam practic?
    // ii spuneam programului: ba, apeleaza pe obiectul
    // asta ( care nu vreau sa fie modificat, pentru ca l-am
    // pasat eu cu mana mea cu 'const' in fata, in signatura
    // functiei ) o metoda care nu garanteaza ca va ramane
    // 'const' obiectul, adica nu garanteaza ca va ramane
    // nealterat !!
    // cred ca, daca lasi in functia aia ( pe la operatori )
    // obiectul pasat prin valoare, atunci nu o sa mai ai problema..
    // de fapt nu... nu cred asta

    /*
    / Getter: m attribute
    */
    int getNom() const; // !amintesc: const garanteaza ca starea obiectului (*this) nu va fi alterata in vreun fel

    /*
    / Getter: n attribute
    */
    int getDenom() const;

    /*
    / Setter: n attribute
    */
    void setNom(int value);
    /*
    / Setter: m attribute
    */
    void setDenom(int value);

    /*
    / Add a rational number to another rational number
    */
    Rational add(int p, int q);

    /*
    / Substract a rational number from another rational number.
    */
    Rational sub(int p, int q);

    /*
    / Multiply a rational number with another rational number.
    */
    Rational mul(int p, int q);

    /*
    / Divide a rational number to another rational number
    */
    Rational quot(int p, int q);

    /*
    / Simplifica numarul prin cel mai mare divizor comun
    */
    Rational simplify();
};

Rational operator+(const Rational &r1, const Rational &r2);
Rational operator-(const Rational &r1, const Rational &r2);
Rational operator*(const Rational &r1, const Rational &r2);
Rational operator/(const Rational &r1, const Rational &r2);
bool operator<(const Rational &r1, const Rational &r2);
#endif
