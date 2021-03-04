/*
#ifndef LAB2_COMPLEX_H
#define LAB2_COMPLEX_H

#include "complex.h"
const int Nmax = 10005;

class ComplexContainer
{
private:
//    Complex elems[Nmax]={}; // declar de o anumita dimensiune
    Complex elems[Nmax]; // las sa se dea ceva random
public:

    /*
    / Constructor without arguments.
    */
    ComplexContainer();

    /*
    / Constructor with arguments.
    */
    ComplexContainer(Complex elems[]); // elems

    /*
    / sorteaza elementele vectorului, dupa valoarea modului acestora
    */
    void sort_me();
};

#endif // LAB2_COMPLEX_H

