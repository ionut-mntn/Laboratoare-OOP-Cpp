#include "Car.h"

Car::Car(int maxSpeed, string color, string model, string fuelType) {
    this->currentSpeed = 0;
    this->maxSpeed = maxSpeed;
    this->color = color;
    this->model = model;
    this->fuelType = fuelType;
}

void Car::drive() {
    currentSpeed = 1;
}

void Car::stop() {
    currentSpeed = 0;
}

void Car::accelerate(int speed) {
    if (speed < 0) {
        return;
    }
    if (currentSpeed + speed > maxSpeed) {
        currentSpeed = maxSpeed;
    } else {
        currentSpeed+=speed;
    }
}

void Car::decelerate(int speed) {
    if (speed < 0) {
        return;
    }
    if (currentSpeed < speed) {
        currentSpeed = 0;
    } else {
        currentSpeed-=speed;
    }
}

string Car::getColor() {
    return color;
}

string Car::getModel() {
    return model;
}

int Car::getSpeed() {
    return currentSpeed;
}

string Car::getFuelType() {
    return fuelType;
}