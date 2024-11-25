#include "Garage.h"
#include <iostream>

void Garage::addCarToGarage(Car carData) {
    stan.push_back(carData);
}

void Garage::deleteCarFromGarage(int index) {
    if (index >= 0 && index < stan.size()) {
        stan.erase(stan.begin() + index);
    } else {
        std::cout << "Invalid index." << std::endl;
    }
}
