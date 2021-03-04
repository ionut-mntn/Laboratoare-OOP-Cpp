#include<iostream>
//#include "src/prime.h"
#include "src/sequences.h"
#include "src/divisibility.h"

using std :: cin;
using std :: cout;

int main() {
/*
    //2.a)
    int n;
    std :: cin >> n;
    int primes[Nmax];

    Prime :: find_store_primes(n, primes);
    Prime :: print_primes(n, primes);
    //2.b)

    int sir[20] = {1,2,4,6,7,8,9,10,11,12,13,14,15,16,17,20,20,20,20,20};
    int i, j;
    Sequences :: longest_rel_prime(sir,20,i,j);
    cout<<'\n'<<i<<" "<<j<<'\n';
*/
/*
    //7.a)

    int arr[25], n = 0;
    Sequences::read_sequences(arr, n);

    int maxxes[25], dim_maxxes;
    Sequences::determine_maxxes(arr,n,maxxes,dim_maxxes);
    for(int i=1; i<=dim_maxxes; i++)
        cout << maxxes[i] << " ";
    cout<<'\n';

    int global_maxx = Sequences::determine_maxx(maxxes, dim_maxxes);
    cout << global_maxx;
*/

 * 7.b)
    int v[Nmax] = {7, 15, 16, 27, 31, 4, 5, 22, 19, 18, 11, 29};
    //Sequences::longest_in_ab(v, sizeof(v), )
    int i, j;
    Sequences::longest_in_ab(v, 12, 11, 29, i, j);
    cout << i << " " << j << '\n';

    return 0;
}