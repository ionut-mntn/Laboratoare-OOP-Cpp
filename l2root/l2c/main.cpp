#include <iostream>

#include "complex.h"
#include "rational.h"

using std :: swap;
using std :: cout;
using std :: cerr;
using std :: string;

void print_rational(Rational *r)
{
    cout<<r->getNom()<<" "<<r->getDenom()<<'\n';
}

void print_complex(Complex *z)
{
    cout<<z->getReal()<<" "<<z->getImag()<<'\n';
}

void sorteaza(Complex *arr, int len)
{
    for(int i = 0; i < len - 1; i++)
        for (int j = i + 1; j < len; j++)
            if (arr[j] < arr[i]) swap ( arr[j], arr[i] );
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
    if (!dim_arr) return;
    for(int i = 0; i < dim_arr; i++)
        cout << arr[i].getReal() << " " << arr[i].getImag() << "     " << arr[i].abs() << '\n';
}

int main()
{

    Complex zero;
    Complex c1(2.3, 3.2);
    Complex c2(-1.2, 2.4);
    Complex c3(2.1, 3.0);
    Complex c4(1, 2);
    Complex c5(1, 1);
    Complex c6(c1 + c2);
    Complex c7(c1 - c3);
    Complex c8(c2 * c3);
    Complex c9(c4 / c5);
    Complex elems[] = {zero, c1, c2, c3, c4, c5, c6, c7, c8, c9};
    int dim = sizeof(elems) / sizeof(elems[0]);
    afiseaza(elems, dim);

    cout<<'\n';

/*
    Complex prob1(3,4);
    Complex prob2(2,0);
    cout<<"verificare suprascriere operator '<'"<<'\n';
    if (prob1 < prob2) std::cout<<"prob1 < prob2"<<'\n';
    else std::cout<<"prob2 < prob1"<<'\n';
*/


    cout<<'\n';

    sorteaza(elems, dim);
    afiseaza(elems, dim);

    cout<<'\n';

    Complex s2 = suma(elems, dim);
    cout<<"suma numerelor complexe din sirul considerat este: "<<s2.getReal()<<" + "<<s2.getImag()<<" * i "<<'\n';

    cout<<'\n';


    Complex z1(2.5,3);
    cout<<"Numarul complex z1 = "<<z1.getReal()<<" + "<<z1.getImag()<<" * i scris sub forma polara este:"<<'\n';
    z1.compute_polar();
    cout<<'\n';

    Complex z2(7.8,2.3);
    cout<<"Numarul complex z2 = "<<z2.getReal()<<" + "<<z2.getImag()<<" * i scris sub forma polara este:"<<'\n';
    z2.compute_polar();
    cout<<'\n';

    Complex z3(1.89,2.46);
    cout<<"Numarul complex z3 = "<<z3.getReal()<<" + "<<z3.getImag()<<" * i scris sub forma polara este:"<<'\n';
    z3.compute_polar();
    cout<<'\n';


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///De aici, in jos, lucruri legate de clasa Rational:

    Rational r1(2, 3);
    Rational r2(2, 4);
    print_rational(&r1);
    print_rational(&r2);

    r1 = r1.add(1,1);
    print_rational(&r1);

    r1 = r1.sub(1,3);
    print_rational(&r1);

    r1 = r1.mul(2,1);
    print_rational(&r1);
    r1 = r1.mul(3,1);
    print_rational(&r1);

    r2 = r2.add(2,1).quot(4,1);
    print_rational(&r2);


    cout<<'\n'<<'\n';
    Rational r3(1,1);
    print_rational(&r3);
    r3 = r3 + Rational(2,1);
    print_rational(&r3);
    r3 = r3 - Rational(1,1);
    print_rational(&r3);
    r3 = r3 * Rational(5,2);
    print_rational(&r3);

    return 0;
}
