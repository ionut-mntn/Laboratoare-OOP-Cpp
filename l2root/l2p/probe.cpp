#include <iostream>

using namespace std;

/*
double my_abs(double x)
{
    return x < 0 ? -x:x;
}

double my_sqrt(double x)
{
    double eps = 0.00001;
    double st = 0, dr = x;    // a = (b + x/b) / 2;
    double mij;

    //while (x - mij * mij > eps )
    do
    {
//        std::cout<<st<<"   "<<dr<<'\n';
        mij = (st + dr) / 2;
        if (mij * mij < x) st = mij;
        else dr = mij;
    }while(my_abs(x - mij * mij) > eps);

    return mij;
}
*/
int probe()
{

/*
 if (__cplusplus == 201703L) std::cout << "C++17\n";
    else if (__cplusplus == 201402L) std::cout << "C++14\n";
    else if (__cplusplus == 201103L) std::cout << "C++11\n";
    else if (__cplusplus == 199711L) std::cout << "C++98\n";
    else std::cout << "pre-standard C++\n";
*/

/*
    cout << "Size of char : " << sizeof(char) << endl;
   cout << "Size of int : " << sizeof(int) << endl;
   cout << "Size of short int : " << sizeof(short int) << endl;
   cout << "Size of long int : " << sizeof(long int) << endl;
   cout << "Size of float : " << sizeof(float) << endl;
   cout << "Size of double : " << sizeof(double) << endl;
   cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;
*/

/*
    char arr1[10];
    int arr2[] = {0};
    int arr3[] = {1};
    int arr4[] = {1,2};
    int arr5[] = {1,2,3,4,5};

    std:: cout<<sizeof(arr1)<<" ";
    std:: cout<<sizeof(arr2)<<" ";
    std:: cout<<sizeof(arr3)<<" ";
    std:: cout<<sizeof(arr4)<<" ";
    std:: cout<<sizeof(arr5)<<" ";
*/

// de probatL a = b += c
    int a = 7;
    //    cout << (*a);
    //    cout << (&a);
    int *p = &a;
    cout << 2;
    cout << p;
    cout << *p;


    return 0;
}
