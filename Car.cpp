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
std::string Car::getCarInfo() const {
    std::ostringstream info;
    info << "Marka: " << marka
         << ", Model: " << model
         << ", Color: " << color
         << ", Rok produkcji: " << rokProdukcji
		 << ", Przebieg: " << przebieg;
    return info.str();
}

int Car::getNaped() const {
    return naped;
}

std::string Car::getColor() const {
    return color;
}

std::string Car::getModel() const {
    return model;
}

std::string Car::getMarka() const {
    return marka;
}

double Car::getRokProdukcji() const {
    return rokProdukcji;
}

int Car::getPrzebieg() const {
    return przebieg;
}
