#include "complex_test.h"
#include "Complex.h"
//const double eps = 0.00001; // daca assert urile de mai jos nu merg ( floating-point error ), atunci se poate schimba conditia de evaluat dintre paranteze
// la: aux.getReal() - rezultat_asteptat < eps, unde 'eps' este eroarea considerata

void addTestC()
{
    Complex aux(1.0, 2.4);

    aux = aux.add(0.2);
    assert(aux.getReal() == 1.2);

    aux = aux.add(2);
    assert(aux.getReal() == 3.2);
}

void multTestC()
{
    Complex aux(3.0, 1.5);
    aux = aux.mult(3);

    assert(aux.getReal() == 9.0);
    assert(aux.getImag() == 4.5);
}

void quotTestC()
{
    Complex aux(5.8, 1.4);

    aux = aux.quot(2);
    assert(aux.getReal() == 2.9);
    assert(aux.getImag() == 0.7);

    bool exceptionThrown = false;
    try
    {
        aux = aux.quot(0);
    }
    catch(...)
    {
        exceptionThrown = true;
    }
    assert(exceptionThrown == true);

}

void run_all_tests()
{
    addTestC();
    multTestC();
    quotTestC();
}
