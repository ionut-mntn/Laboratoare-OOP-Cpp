//
// Created by User on 2/28/2020.
//

#ifndef LAB1_PRIME_H
#define LAB1_PRIME_H

//const int Nmax 10005

namespace Prime {
    /**
     * Checks if number is prime
     * x - the number to be checked
     * returns True if number is prime, False otherwise
     */
    bool prime( int n );

    /**
     * Generate Eratostene's sieve, where: if arr[i] = 0, then i is prime; i is not prime, otherwise
     * arr - array to be filled with 0s and 1s accordingly
     * n - right boundary of the interval
     * does not return
     */
    void generate_sieve(bool* arr, int n); // cred ca totusi am sa ii pasez ca
    // argument si adresa de memorie unde sa stocheze ciurul; asa o
    // sa am mai mult control !!

    /**
     * Prints all prime numbers in the interval [1, n]
     * n - right boundary of the interval
     * arr - Eratostene's Sieve up to n
     * does not return
     */
    void print_primes(bool* arr, int n);

    /**
     * Finds first n primes and stores them
     * n - number of the first primes to be found
     * arr - pointer to the array in which first n primes will be stored in
     * does not return
     */
    void find_store_primes(int &n, int* arr);

    /**
     * Prints first n prime numbers
     * n - number of the first primes to be displayed
     * primes - pointer to the array where first n primes are stored
    */
    void print_primes( int n, int *primes );

    /**
     * a, b - numbers to tell if relative-prime
     * returns true if a and b are relatively-prime; false, otherwise
     */
    bool relatively_prime(int a, int b);

}
#endif //LAB1_PRIME_H
