//
// Created by User on 3/2/2020.
//
#include "gtest/gtest.h"
//#include "test/lib/googletest/include/gtest/gtest.h"
//#include "src/test/lib/googletest/include/gtest/gtest.h"
//#include "D:\ionut\Info\Faculta\sem II\POO - Programare Orientata pe Obiect ( Rusu Catalin, Manda Iulian )\Laboratoare\lab1\test\lib\googletest\include\gtest\gtest.h"
#include "sequences.h"

/*
TEST(SequencesTestSuite, longest_rel_prime_2el)
{
    int v[Nmax]={1,2};
    int dv = 2;

    int expected_i

    int i, j;
}

TEST(SequencesTestSuite, read_sequence)
{
    int
}
*/

TEST(SequencesTestSuite, determine_maxxesNullArray)
{
int arr[Nmax] = {}, n = 0;
int maxxes[Nmax], dim_maxxes;

int expected_maxxes[Nmax];
int expected_dim_maxxes = 0;

ASSERT_EQ ( expected_dim_maxxes == n == 0 )

}

TEST(SequencesTestSuite, determine_maxxesNegativeArray)
{
int arr[Nmax] = {-1,-2,-3,0, -4,-5,-6,0, 2,3,0, 10,-1 };
int n = 13;
int maxxes[Nmax];
int dim_maxxes = 0;

int expected_maxxes = {0, -1, -4, 3, 10 };
int expected_dim_maxxes = 4;

Sequences :: determine_maxxes(arr, n, maxxes, dim_maxxes);

ASSERT_EQ(dim_maxxes, expected_dim_maxxes)

for(int i=1; i <= dim_maxxes; i++ )
ASSERT_EQ(maxxes[i], expected_maxxes[i])
}

TEST(SequencesTestSuite, determine_maxxesPositiveArray)
{
int arr[Nmax] = {1,2,3};
}

TEST(SequencesTestSuite, determine_maxxesMixedArray)
{
int arr[Nmax] = {1,2,3};
}