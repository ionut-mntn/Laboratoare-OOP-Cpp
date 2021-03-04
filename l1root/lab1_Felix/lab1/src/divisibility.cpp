//
// Created by User on 2/29/2020.
//
#include "divisibility.h"

int Divisibility :: gcd(int a, int b)
{
    int r;
    while (b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}