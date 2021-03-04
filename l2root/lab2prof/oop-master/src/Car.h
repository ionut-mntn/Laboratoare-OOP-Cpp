#ifndef LAB2_CAR_H
#define LAB2_CAR_H

#include "string"
using namespace std;

class Car {

private:
    int currentSpeed;
    int maxSpeed;
    string color;
    string model;
    string fuelType;

public:

    /*
     * Constructor
     */
    Car(int maxSpeed, string color, string model, string fuelType);

    /*
     * Starts the car.
     */
    void drive();

    /*
     * Accelerates the car with the given speed.
     * speed - the amount of speed to accelerate.
     */
    void accelerate(int speed);

    /*
     * Decelerates the car with the given speed.
     * speed - the amount of speed to accelerate.
     */
    void decelerate(int speed);

    /*
     * Stops the car.
     */
    void stop();

    /*
     * Returns the current speed of the car.
     */
    int getSpeed();

    /*
     * Returns the color of the car.
     */
    string getColor();

    /*
     * Returns the model of the car.
     */
    string getModel();

    /*
     * Returns the fuel type of the car.
     */
    string getFuelType();

};

#endif //LAB2_CAR_H
