//
// Created by User on 2/28/2020.
//
#include <iostream>
#include "prime.h"
#include "divisibility.h"

using std :: cout;

bool Prime :: prime(int x)
{
    if (x < 2) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for(int d = 3; d * d <= x; d++)
        if (x % d == 0) return false;
    return true;
}

void Prime :: generate_sieve(bool arr[], int n)
{
    arr[0] = false;
    arr[1] = false;
    arr[2] = true;

    for (int i = 2 + 2; i <= n; i = i + 2)
        arr[i] = false; // daca arr[i] = 1, atunci i-prim; alfel, i-compus

    for (int i = 3; i <= n; i = i + 2)
    {
        if (prime(i)) {
            arr[i] = true;
            for (int j = i + i; j <= n; j = j + i)
                arr[j] = false;
        } else arr[i] = false;
    }
}

void Prime :: find_store_primes(int &n, int* arr)
{
    if (n <= 0) return ;
    int dim = -1;
    arr[++dim] = 2; // indexare de la zero

    int nr = 3;
    while (n)
    {
        if ( prime(nr) )
        { arr[++dim] = nr; n--; }
        nr += 2;
    }
    n = dim;
}

void Prime :: print_primes(int n, int* primes) // e ok sa am asa o functie intr un namespace ? Adica ea doar afiseaza niste elementele unui vector ...
{
    for(int i = 0; i < n; i ++)
        cout << primes[i] << " ";
}

bool Prime :: relatively_prime(int a, int b)
{
    return ( Divisibility :: gcd(a, b) == 1);
}
