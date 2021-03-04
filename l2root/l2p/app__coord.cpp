#include "complex.h"
#include <iostream>
//#include <string>
#include <stdio.h>

using std :: swap;
using std :: cout;
using std :: string;

//using

//double suma(Complex *arr, int larr)
void sorteaza(Complex *arr, int len)
{
    for(int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[i]) // am suprascris operatorul < in complex.cpp
            {
                swap ( arr[j], arr[i] );
            //afiseaza(arr, l);
            }
            //cout<<'\'n';
        }
        //cout<< '\n';
        //cout<<'\n';
    }
}

Complex suma(const Complex *arr, const int len)
{
    //double sum = 0;
    Complex sum;
    for(int i = 0; i <len; i++)
        sum = sum + arr[i];
    return sum;
}

void afiseaza(Complex arr[], int dim_arr) // daca nu ii pasez lungimea, nu stie sa si o ia singur ?
{
    /*
    cout << "sizeof(arr) = " << sizeof(arr) << '\n';
    if (!sizeof(arr)) { cout << " Vectorul este gol "; return ; }
    int l = sizeof(arr) / sizeof(arr[0]);
    cout << "l = " << l << '\n';
    for(int i = 0; i < l; i++)
        cout << arr[i].getReal() << " " << arr[i].getImag() << '\n';
    */
    if (!dim_arr) return;
    for(int i = 0; i < dim_arr; i++)
        cout << arr[i].getReal() << " " << arr[i].getImag() << "             " << arr[i].abs() << '\n';
}


int main()
{

    //std :: cout<<atan()

    Complex c1(2.3, 3.2);
    Complex c2(-1.2, 2.4);
    Complex c3(2.1, 3.0);
    Complex c4(1, 2);
    Complex c5(1, 1);
    Complex c6(c1 + c2);
    Complex c7(c1 - c3);
    Complex c8(c2 * c3);
    Complex c9(c4 / c5);

    std::cout<<c1.getReal()<<" "<<c1.getImag()<<'\n';
    std::cout<<c2.getReal()<<" "<<c2.getImag()<<'\n';
    std::cout<<c3.getReal()<<" "<<c3.getImag()<<'\n';
    std::cout<<c4.getReal()<<" "<<c4.getImag()<<'\n';
    std::cout<<c5.getReal()<<" "<<c5.getImag()<<'\n';
    std::cout<<'\n';
    std :: cout<<c6.getReal()<<" "<<c6.getImag()<<'\n';
    std :: cout<<c7.getReal()<<" "<<c7.getImag()<<'\n';
    std :: cout<<c8.getReal()<<" "<<c8.getImag()<<'\n';
    std :: cout<<c9.getReal()<<" "<<c9.getImag()<<'\n';



    Complex proba(1.0, 2.0);
    //Complex zero(); //Azi chiar am invatat ceva nou ! :) daca scriu asa, ar crede
    // ca zero e o functie. poti scrie ca mai jos
    //Complex zero{}; // nici asa nu merge
    //Complex zero
    Complex zero;
    std::cout<<"proba: "<<proba.abs();
    std::cout<<zero.getReal()<<" "<<zero.getImag()<<'\n';
    cout<<'\n';

    Complex arr[6] = {c1, c2, c3, c4, c5, c6, c7, c8, c9};
    //std :: cout<<sizeof(arr) / sizeof(arr[0]);
    std :: cout << "aici:" <<'\n';
    proba = Complex(2.0, 2.3);
    Complex proba2 = Complex(2.0, 3.1);
    std :: cout << proba.getReal() << " " << proba.getImag()<<'\n';
    std :: cout << proba2.getReal() << " " << proba2.getImag()<<'\n';
    // proba += proba2;
    std :: cout << proba.getReal() << " " << proba.getImag()<<'\n';
    std :: cout << '\n';
    /*
    Complex s;
    Complex arr2[6] = {c1, c2, c3, c4, c5, c6};
    int l = sizeof(arr2) / sizeof(arr[0]);
    for(int i = 0; i < l; i++)
        s = s + arr[i];
    std :: cout << "s======"s.getReal() << " " << s.getImag()<<'\n';
    */
    Complex prob1(3,4);
    Complex prob2(2,0);
    if (prob1 < prob2) std :: cout << "aici 1): " << prob1.abs()<<'\n';
    else std :: cout << "aici 2): " << prob2.abs()<<'\n';
    cout<<'\n';





    Complex elems[] = {c1, c2, c3, c4, c5, c6, c7, c8, c9};
    //cout << sizeof(elems) << '\n';
    int l = sizeof(elems) / sizeof(elems[0]);
/*
    cout << l << '\n';
    for(int i = 0; i < l; i++)
        cout << arr[i].getReal() << " " << arr[i].getImag() << '\n';
*/

    afiseaza(elems, l);
    cout<<'\n';
    //l = sizeof(elems) / sizeof(elems[0]);
    sorteaza(elems, l);
    afiseaza(elems, l);

    //cout<<suma(elems,l);
    Complex s2 = suma(elems,l);
    cout<<'\n';
    cout<<s2.getReal()<<" "<<s2.getImag()<<'\n';
/*
    std :: string aux = "cf??";
    cout << aux;

    printf("salut, %s", "boss\n");
*/

    Complex prob3(2.5,3);
    prob3.compute_polar();



    return 0;
}
