//
// Created by User on 3/2/2020.
//
#include "gtest/gtest.h"
#include <cassert>

//#include "test/lib/googletest/include/gtest/gtest.h"
//#include "src/test/lib/googletest/include/gtest/gtest.h"
//#include "D:\ionut\Info\Faculta\sem II\POO - Programare Orientata pe Obiect ( Rusu Catalin, Manda Iulian )\Laboratoare\lab1\test\lib\googletest\include\gtest\gtest.h"
#include "sequences.h"

TEST(SequencesTestSuite, determine_maxxesNegativeArray)
{
    //setup
    int arr[] = {-2,-3,0, -4,-5,-6,0, -7,-8,0, -10,-1 };
    int n = 12;
    int maxxes[] = {};
    int dim_maxxes = 0;

    //run
    Sequences :: determine_maxxes(arr, n, maxxes, dim_maxxes);

    //verify
    int expected_maxxes[] = {-2, -4, -7, -10 };
    int expected_dim_maxxes = 4;

    ASSERT_EQ(dim_maxxes, expected_dim_maxxes);
    for(int i=0; i < dim_maxxes; i++ )
        ASSERT_EQ(maxxes[i], expected_maxxes[i]);
}

TEST(SequencesTestSuite, determine_maxxesPositiveArray)
{
    //setup
    int arr[] = {2,3,0, 4,5,6,0, 7,8,0, 10,0,-1 }; // nota: am schimbat si modul in care se incheie ultima secventa
    int n = 12;
    int maxxes[] = {};
    int dim_maxxes = 0;

    //run
    Sequences :: determine_maxxes(arr, n, maxxes, dim_maxxes);

    // verify
    int expected_maxxes[] = {3, 6, 8, 10 };
    int expected_dim_maxxes = 4;

    ASSERT_EQ(dim_maxxes, expected_dim_maxxes);
    for(int i=0; i < dim_maxxes; i++ )
        ASSERT_EQ(maxxes[i], expected_maxxes[i]);
}

TEST(SequencesTestSuite, determine_maxxesMixedArray)
{
    //setup
    int arr[] = {0, 0, 0, -2,3,0, -4,5,-6,0, -7,-8,19,-22,0, -10,-1 };
    int n = 12;
    int maxxes[] = {};
    int dim_maxxes = 0;

    //run
    Sequences :: determine_maxxes(arr, n, maxxes, dim_maxxes);

    // verify
    int expected_maxxes[] = {3, 5, 19, -10 };
    int expected_dim_maxxes = 4;

    ASSERT_EQ(dim_maxxes, expected_dim_maxxes);
    for(int i=0; i < dim_maxxes; i++ )
        ASSERT_EQ(maxxes[i], expected_maxxes[i]);
}

TEST(SequencesTestSuite, determine_maxxMixedArr)
{
    //setup
    int arr[] = {-17,22,34,-100,128,1005,-1,-17};
    int n = 8;

    //run
    int result = Sequences::determine_maxx(arr, n);

    //verify
    int expected_maxx = 1005;
    ASSERT_EQ(expected_maxx, result );
}

TEST(SequencesTestSuite, longest_in_ab_11_19)
{
    //setup
    int arr[] = {7, 15, 16, 27, 31, 4, 5, 22, 19, 18, 11, 29};
    int n = 12;
    int a = 11, b = 29;
    int i, j;

    //run
    Sequences::longest_in_ab(arr, n, a, b, i, j);

    //verify
    int expected_i = 7;
    int expected_j = 11;

    ASSERT_EQ(i, expected_i);
    ASSERT_EQ(j, expected_j);
}