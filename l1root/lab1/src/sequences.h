//
// Created by User on 2/29/2020.
//

#ifndef LAB1_SEQUENCES_H
#define LAB1_SEQUENCES_H

#define Nmax 10005

namespace Sequences{
/*
    struct seq{
        int i;
        int j;
    };
*/

    /**
     * Finds longest sequence of relatively-prime integers
     * arr - array to search in
     * n - number of elements in the array
     * i - left end (index) of the sequence
     * j - right end (index) of the sequence
     * does not return; after the call, i and j will be the left, respectively the right end of the longest sequence of
     * relatively_prime elements
     */
    //seq longest_equal(int* arr, int n);
    void longest_rel_prime(const int* arr, int n, int &i, int &j);

    /**
     * Reads and stores integers as long as last read integer is not 0 or -1
     * @param arr - array to store numbers in
     * @param n - array's dimension
     * does not retun
     */
    void read_sequence(int* arr, int &n);

    /**
     * Reads and stores sequences of integers as long as last read integer of the last read sequence is not -1
     * @param arr - array to store sequences in
     * @param n - array's dimension
     */
    void read_sequences(int* arr, int &n);

    /**
     * Determines the the maximum value of eqch sequence in the array ( Sequences are separated by zeros - I am not
     * validating input data )
     * @param arr - array to determine maximum values for
     * @param n - dimension of the arr array
     * @param maxxes - array to store maximum values in
     * @param dim_maxxes - dimension of the maxxes array
     */
    void determine_maxxes(int* arr, int n, int* maxxes, int &dim_maxxes);

    /**
     * Determines maximum value in the array
     * @param arr - the array to search maximum value in
     * @param n - the dimension of the array
     * @return Returns the maximum value in the array
     */
    int determine_maxx(int* arr, int n);

    /**
     * Determines longest sequence of elements in the array lying in the given interval
     * arr - array to search in
     * n - dimension of array to search in
     * a - left end of given interval
     * b - right end of given interval
     * i - left end of longest found sequence
     * j - right end of longest found sequence
     * does not return; modifies i and j  parameters accordingly
     */
    void longest_in_ab(const int* arr, const int n, const int a, const int b, int &i, int &j);
}

#endif //LAB1_SEQUENCES_H
