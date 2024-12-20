#ifndef GARAGE_H
#define GARAGE_H

#include <vector>
#include "Car.h"

class Garage {
private:
    std::vector<Car> stan;

public:
	// Getters
	int getCarCount() const;
	
    // Car management
    void addCarToGarage(Car carData);
    void deleteCarFromGarage(int index);
    void updateCar(int index, const Car &updatedCar);
    Car getCarByIndex(int index);

    // File actions
    void saveToFile(const std::string &filename);
    void loadFromFile(const std::string &filename);
    void createNewFile(const std::string &filename);

    // Viewing and searching
    void viewCars(int &currentIndex);
    void searchByModel(const std::string &model);
    void searchByYearRange(double minYear, double maxYear);

    // Sorting
    void sortByYear(bool ascending);

    // Program shutdown
    void confirmExit(bool &exitProgram);
};

#endif
