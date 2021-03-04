//
// Created by User on 2/29/2020.
//
#include <iostream>
#include "sequences.h"
#include "divisibility.h"
#define LOWEST_POSSIBLE_INT -2000000000 // 2 million
using std :: cin;
using std :: cout;

//seq Sequences :: longest_equal(int *arr, int n)
//Sequences :: seq Sequences :: longest_equal(int *arr, int n)
//Sequences :: struct seq longest_equal(int *arr, int n)
//Sequences :: seq Sequences :: longest_equal(int *arr, int n)
void Sequences :: longest_rel_prime(const int *arr, int n, int &i, int &j) // e ok sa returnez un pointer la ceva declarat local ???
{
    i = 0; j = i + 1;
    int lmax = -1, iR = -1, jR =-1 ; // lmax ar trebui sa fie 1 sau -1 ?
    while ( j < n )
    {
        if ( Divisibility :: gcd(arr[j - 1], arr[j]) == 1 ) { cout << arr[j-1] <<" "<< arr[j] << '\n'; j ++;}            // daca extrema stanga inca e egala cu extrema dreapta a intervalului, incrementeaza pozitia extremei drepte
        else                                                        // altfel:
        {
            if (j - i > lmax) { lmax = j - i; iR = i; jR = j - 1; }     // daca lungimea curenta a secventei(indexare de la 0) este mai mare decat lungimea maxima actuala,
            i = j;                                                  // actualizeaza: lungimea maxima actuala, pozitia de start si pozitia de final a secventei de lungime maxima
            j = i + 1;                                              // si continua cautarea, cu noii indecsi actualizati corespunzator
        }
    }
    if (j - i > lmax) { lmax = j - i; iR = i; jR = j - 1; }             // o verificare suplimentara, in cazul in care cea mai lunga secventa se afla la finalul sirului
    if (lmax > 1) {i = iR; j = jR; return ;}                        // daca am gasit intr-adevar o secventa, actualizeaza i si j cu valorile reprezentand capetele secventei de lungime maxima
    i = -1; j = -1;                                                 // altfel, returneaza valori semnificative
}

void Sequences :: read_sequence(int* arr, int &n)
{
    do
    {
        cin >> arr[++n];
    }while(arr[n] and arr[n] != -1);
}

void Sequences :: read_sequences(int* arr, int &n)
{
    do
    {
        Sequences :: read_sequence(arr, n);
        for(int i=1; i<=n;i++)
            cout<<arr[i]<<" ";
        cout<<'\n';
    }while(arr[n] != -1);
}

void Sequences :: determine_maxxes(int* arr, int n, int* maxxuri, int &dim_maxxes)
{
    int i = 1, maxx = LOWEST_POSSIBLE_INT;
    dim_maxxes = 0; // !
    while(i < n)
    {
        if (arr[i] == -1) return ; // nu zice ca orice secventa trebuie musai sa se termin cu 0 !! de asta, mai copiez o data instructiunea de atribuire
        else
        {
            if(arr[i] == 0)
            {
                maxxuri[++dim_maxxes] = maxx;
//                if ( maxx > maxxG ) maxxG = maxx;
            }
            else
            {
                if (arr[i] > maxx) maxx = arr[i];
            }
        }
    i++;
    }
}

int Sequences::determine_maxx(int* arr, int n)
{
    int maxx = arr[1];
    for(int i=2; i<=n; i++)
        if (arr[i] > maxx) maxx = arr[i];
    return maxx;
}

void Sequences :: longest_in_ab(const int * arr, const int n, const int a, const int b, int &i, int &j)  // stiu ca sunt cam multi parametrii aici, dar nu mi a iesit sa moedelez o structura ('seq')
// cum voiam...sorry !!
{
    i = 0; j = i;
    int lmaxx = -1, iR = -1, jR = -1;                                       // [11, 29]
    while(j < n)                                                            // 7 15 16 27 31 4 5 22 19 18 11 29
    {
        if (a <= arr[j] and arr[j] <= b) j ++; // the requirements do not specify whether the interval is open / closed; I have chosen to consider it closed
        else
        {
            if (j - i > lmaxx) { lmaxx = j - i; iR = i; jR = j - 1; }
            i = j + 1;
            j = i;
        }
    }
    if (j - i > lmaxx) { lmaxx = j - i; iR = i; jR = j - 1; } // atentie si la asta verificarea suplimentara ( in cazul in care secventa ce ma intereseaza incheie sirul chiar ) !!

    if (lmaxx > 0) { i = iR; j = jR; }
    else { i = -1; j = - 1; }
}