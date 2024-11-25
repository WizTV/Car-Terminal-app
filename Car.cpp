#include "Car.h"

// Setters
void Car::setNaped(int napedData) {
    naped = napedData;
}

void Car::setColor(std::string colorData) {
    color = colorData;
}

void Car::setModel(std::string modelData) {
    model = modelData;
}

void Car::setMarka(std::string markaData) {
    marka = markaData;
}

void Car::setRokProdukcji(double rokProdukcjiData) {
    rokProdukcji = rokProdukcjiData;
}

void Car::setPrzebieg(int przebiegData) {
    przebieg = przebiegData;
}

// Getters
int Car::getNaped() {
    return naped;
}

std::string Car::getColor() {
    return color;
}

std::string Car::getModel() {
    return model;
}

std::string Car::getMarka() {
    return marka;
}

double Car::getRokProdukcji() {
    return rokProdukcji;
}

int Car::getPrzebieg() {
    return przebieg;
}
