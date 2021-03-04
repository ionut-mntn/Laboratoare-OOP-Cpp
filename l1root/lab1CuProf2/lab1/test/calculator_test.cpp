/*
#include "gtest/gtest.h"
#include "calculator.h"

TEST(CalculatorTestSuite, AddTest) {
    int result = Calculator::add(1, 1);

    ASSERT_EQ(2, result);
}

TEST(CalculatorTestSuite, AddNegativeTest) {
    int result = Calculator::add(-1, 1);

    ASSERT_EQ(0, result);
}
*/



#include "gtest/gtest.h"
#include "calculator.h"

TEST(CalculatorTestSuite, AddTest) {
    int result = Calculator::add(1, 1);

    ASSERT_EQ(2, result);
}

TEST(CalculatorTestSuite, AddNegativeTest) {
    int result = Calculator::add(-1, 1);

    ASSERT_EQ(0, result);
}
// de aici in jos eu

TEST(CalculatorTestSuite, AddPositive) {
    // setup
    int a = 1;
    int b = 1;

    // run
    int result = Calculator :: add(a, b);

    // verify
    int expected = 2;
    ASSERT_EQ(expected, result);
}

TEST(CalculatorTestSuite, AddNegative){
    // setup
    int a = 1;
    int b = 1;

    // run
    int result = Calculator :: add(a, b);

    //verify
    int expected = 2;
    ASSERT_EQ(expected, result);

}

