//
// Created by User on 3/3/2020.
//

#include "gtest/gtest.h"
#include "divisibility.h"

TEST(DivisibilityTestSuiteBoggy, gcdEquals)
{
    //setup
    int a, b;
    a = b = 124;

    //run
    int result = Divisibility::gcd(a, b);

    //verify
    int expected = 124;
    ASSERT_EQ(result, expected);
}

TEST(DivisibilityTestSuite, gcdRelPrime) // 2 nr relativ prime intre ele: gcd(a, b) = 1
{
    //setup
    int a = 12 , b = 17;

    //run
    int result = Divisibility::gcd(a, b);

    //verify
    int expected = 1;
    ASSERT_EQ(result, expected);
}

TEST(DivisibilityTestSuite, gcdRand) // randomly selected
{
    //setup
    int a = 16, b = 2040 ;

    //run
    int result = Divisibility::gcd(a, b);

    //verify
    int expected = 8;
    ASSERT_EQ(result, expected);
}

TEST(DivisibilityTestSuite, gcdRand2) // randomly selected
{
    //setup
    int a = 9, b = 36 ;

    //run
    int result = Divisibility::gcd(a, b);

    //verify
    int expected = 9;
    ASSERT_EQ(result, expected);
}

TEST(DivisibilityTestSuite, gcdRand3) // randomly selected
{
    //setup
    int a = 42, b = 7 ;

    //run
    int result = Divisibility::gcd(a, b);

    //verify
    int expected = 7;
    ASSERT_EQ(result, expected);
}

TEST(DivisibilityTestSuite, gcdRand4) // randomly selected
{
    //setup
    int a = 105, b = 30 ;

    //run
    int result = Divisibility::gcd(a, b);

    //verify
    int expected = 15;
    ASSERT_EQ(result, expected);
}