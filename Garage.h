#ifndef GARAGE_H
#define GARAGE_H

#include <vector>
#include "Car.h"

class Garage {
private:
    std::vector<Car> stan; // Lista samochodów w garażu

public:
	// Getters
	int getCarCount() const;
	
    // Zarządzanie samochodami
    void addCarToGarage(Car carData);
    void deleteCarFromGarage(int index);
    void updateCar(int index, const Car &updatedCar);
    Car getCarByIndex(int index);

    // Operacje na plikach
    void saveToFile(const std::string &filename);
    void loadFromFile(const std::string &filename);
    void createNewFile(const std::string &filename);

    // Wyświetlanie i wyszukiwanie
    void viewCars(int &currentIndex);
    void searchByModel(const std::string &model);
    void searchByYearRange(double minYear, double maxYear);

    // Sortowanie
    void sortByYear(bool ascending);

    // Zakończenie programu
    void confirmExit(bool &exitProgram);
};

#endif
