//
// Created by User on 3/2/2020.
//

#include "gtest/gtest.h"
#include "prime.h"
/*
TEST(PrimeTestSuite, find_store_primes10)
{
    //setup
    int result[] = {};
    int n;

    //run
    Prime::find_store_primes(n, result);


    //verify
    int expected_result[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    int expected_result_dim = 10;
//    ASSERT_EQ(sizeof(expected_result) / sizeof(*expected_result), n);
    ASSERT_EQ(expected_result_dim, n);
    for(int i = 0; i < n; i++)
        ASSERT_EQ(result[i], expected_result[i]);
}
*/
TEST(PrimeTestSuite, primeNeg)
{
    //setup
    int nr = -5;

    //run
    bool result = Prime::prime(nr);

    //verify
    bool expected = false;
    ASSERT_EQ(result, expected);
}

TEST(PrimeTestSuite, primeZero)
{
    //setup
    int nr = 0;

    //run
    bool result = Prime::prime(nr);

    //verify
    bool expected = false;
    ASSERT_EQ(result, expected);
}

TEST(PrimeTestSuite, primeOne) // un nr compus, nu prim
{
    //setup
    int nr = 1;

    //run
    bool result = Prime::prime(nr);

    //verify
    bool expected = false;
    ASSERT_EQ(result, expected);
}

TEST(PrimeTestSuite, primeComposite) // copmound, as in not prime
{
    //setup
    int nr = 15;

    //run
    bool result = Prime::prime(nr);

    //verify
    bool expected = false;
    ASSERT_EQ(result, expected);
}

TEST(PrimeTestSuite, primeComposite2)
{
    //setup
    int nr = 25;

    //run
    bool result = Prime::prime(nr);

    //verify
    bool expected = false;
    ASSERT_EQ(result, expected);
}

TEST(PrimeTestSuite, prime1) // first prime to be checked
{
    //setup
    int nr = 2;

    //run
    bool result = Prime::prime(nr);

    //verify
    bool expected = true;
    ASSERT_EQ(result, expected);
}

TEST(PrimeTestSuite, prime2) // second prime to be checked
{
    //setup
    int nr = 3;

    //run
    bool result = Prime::prime(nr);

    //verify
    bool expected = true;
    ASSERT_EQ(result, expected);
}

TEST(PrimeTestSuite, prime3) // un nr compus, nu prim
{
    //setup
    int nr = 19;

    //run
    bool result = Prime::prime(nr);

    //verify
    bool expected = true;
    ASSERT_EQ(result, expected);
}