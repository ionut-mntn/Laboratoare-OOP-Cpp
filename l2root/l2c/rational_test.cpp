#include <cassert>
#include "Rational.h"

void addTestR()
{
    Rational aux(1, 2);

    aux = aux.add(2,1);
    assert(aux.getNom() == 5); // 1/2 + 2 = 5/2
    assert(aux.getDenom() == 2);

    aux = aux.add(3, 1);
    assert(aux.getNom() == 11); // 5/2 + 3 = 11/2
    assert(aux.getDenom() == 2);
}

void multTestR()
{
    Rational aux(3, 2);
    aux = aux.mul(3, 1);

    assert(aux.getNom() == 9);
    assert(aux.getDenom() == 2);
}

void quotTestR()
{
    Rational aux(5, 4);

    aux = aux.quot(1, 2);
    assert(aux.getNom() == 5); // 5/4 : 1/2 = 5/4 * 2/1 = 10/4 = 5/2
    assert(aux.getDenom() == 2);

    bool exceptionThrown = false;
    try
    {
        aux = aux.quot(0, 1); // 5/2 : 0/1 = 5/2 * 1/0 = !!??!!
    }
    catch(...)
    {
        exceptionThrown = true;
    }
    assert(exceptionThrown == true);
}

void run_all_testsR()
{
    addTestR();
    multTestR();
    quotTestR();
}
