#include "gtest/gtest.h"
#include "Car.h"

Car createDriveTestCar() {
    return Car(120, "black", "Volkswagen", "diesel");
}

TEST(CarDriveTest, Drive) {
    Car car = createDriveTestCar();

    car.drive();

    ASSERT_EQ(1, car.getSpeed());
}

TEST(CarDriveTest, Accelerate) {
    Car car = createDriveTestCar();

    car.accelerate(50);

    ASSERT_EQ(50, car.getSpeed());
}

TEST(CarDriveTest, AccelerateOverLimit) {
    Car car = createDriveTestCar();

    car.accelerate(150);

    ASSERT_EQ(120, car.getSpeed());
}

TEST(CarDriveTest, AccelerateNegative) {
    Car car = createDriveTestCar();

    car.accelerate(30);
    car.accelerate(-10);

    ASSERT_EQ(30, car.getSpeed());
}

TEST(CarDriveTest, Decelerate) {
    Car car = createDriveTestCar();

    car.accelerate(100);
    car.decelerate(50);

    ASSERT_EQ(50, car.getSpeed());
}

TEST(CarDriveTest, DecelerateUnder0) {
    Car car = createDriveTestCar();

    car.accelerate(30);
    car.decelerate(50);

    ASSERT_EQ(0, car.getSpeed());
}

TEST(CarDriveTest, DecelerateNegative) {
    Car car = createDriveTestCar();

    car.accelerate(10);
    car.decelerate(-30);

    ASSERT_EQ(10, car.getSpeed());
}