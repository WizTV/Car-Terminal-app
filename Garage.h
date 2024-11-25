#ifndef GARAGE_H
#define GARAGE_H

#include <vector>
#include "Car.h"

class Garage {
private:
    std::vector<Car> stan;

public:
    void addCarToGarage(Car carData);
    void deleteCarFromGarage(int index);
};

#endif
