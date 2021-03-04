#include "gtest/gtest.h"
#include "Car.h"

Car createAttributeTestCar() {
    return Car(100, "blue", "Opel", "gasoline");
}

TEST(CarAttributeSuite, Color) {
    Car car = createAttributeTestCar();

    ASSERT_EQ("blue", car.getColor());
}

TEST(CarAttributeSuite, Model) {
    Car car = createAttributeTestCar();

    ASSERT_EQ("Opel", car.getModel());
}

TEST(CarAttributeSuite, FuelType) {
    Car car = createAttributeTestCar();

    ASSERT_EQ("gasoline", car.getFuelType());
}