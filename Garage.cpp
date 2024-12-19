#include "Garage.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <string>

void Garage::addCarToGarage(Car carData) {
    stan.push_back(carData);
    std::cout << "Car added to garage.\n";
}

Car Garage::getCarByIndex(int index) {
    if (index >= 0 && index < stan.size()) {
        return stan[index];
    } else {
        throw std::out_of_range("Invalid index");
    }
}

void Garage::deleteCarFromGarage(int index) {
    if (index >= 0 && index < stan.size()) {
        stan.erase(stan.begin() + index);
        std::cout << "Car deleted from garage.\n";
    } else {
        std::cout << "Invalid index.\n";
    }
}

void Garage::updateCar(int index, const Car &updatedCar) {
    if (index >= 0 && index < stan.size()) {
        stan[index] = updatedCar;
        std::cout << "Car updated successfully.\n";
    } else {
        std::cout << "Invalid index.\n";
    }
}

void Garage::saveToFile(const std::string &filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto &car : stan) {
            file << car.getMarka() << " " << car.getModel() << " " << car.getColor() << " "
                 << car.getNaped() << " " << car.getRokProdukcji() << " " << car.getPrzebieg() << "\n";
        }
        file.close();
        std::cout << "Data saved to file.\n";
    } else {
        std::cout << "Failed to open file.\n";
    }
}

void Garage::loadFromFile(const std::string &filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        stan.clear();
        std::string marka, model, color;
        int naped, przebieg;
        double rokProdukcji;

        while (file >> marka >> model >> color >> naped >> rokProdukcji >> przebieg) {
            Car car;
            car.setMarka(marka);
            car.setModel(model);
            car.setColor(color);
            car.setNaped(naped);
            car.setRokProdukcji(rokProdukcji);
            car.setPrzebieg(przebieg);
            stan.push_back(car);
        }

        file.close();
        std::cout << "Data loaded from file.\n";
    } else {
        std::cout << "Failed to open file.\n";
    }
}

void Garage::createNewFile(const std::string &filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file.close();
        std::cout << "New file created: " << filename << "\n";
    } else {
        std::cout << "Failed to create file.\n";
    }
}

void Garage::viewCars(int &currentIndex) {
    if (stan.empty()) {
        std::cout << "No cars in the garage.\n";
        return;
    }

    if (currentIndex < 0) currentIndex = 0;
    if (currentIndex >= stan.size()) currentIndex = stan.size() - 1;

    const auto &car = stan[currentIndex];
    std::cout << "Car " << currentIndex + 1 << "/" << stan.size() << ":\n";
    std::cout << "Marka: " << car.getMarka() << "\n"
              << "Model: " << car.getModel() << "\n"
              << "Color: " << car.getColor() << "\n"
              << "Naped: " << car.getNaped() << "\n"
              << "Rok produkcji: " << car.getRokProdukcji() << "\n"
              << "Przebieg: " << car.getPrzebieg() << "\n";
}

void Garage::searchByModel(const std::string &model) {
    auto it = std::find_if(stan.begin(), stan.end(), [&model](const Car &car) {
        return car.getModel() == model;
    });

    if (it != stan.end()) {
        std::cout << "Found car with model " << model << ":\n";
        std::cout << "Marka: " << it->getMarka() << "\n"
                  << "Color: " << it->getColor() << "\n"
                  << "Naped: " << it->getNaped() << "\n";
    } else {
        std::cout << "No car with model " << model << " found.\n";
    }
}

void Garage::searchByYearRange(double minYear, double maxYear) {
    for (const auto &car : stan) {
        if (car.getRokProdukcji() >= minYear && car.getRokProdukcji() <= maxYear) {
            std::cout << "Marka: " << car.getMarka() << ", Model: " << car.getModel()
                      << ", Year: " << car.getRokProdukcji() << "\n";
        }
    }
}

void Garage::sortByYear(bool ascending) {
    std::sort(stan.begin(), stan.end(), [ascending](const Car &a, const Car &b) {
        return ascending ? a.getRokProdukcji() < b.getRokProdukcji()
                         : a.getRokProdukcji() > b.getRokProdukcji();
    });
    std::cout << "Cars sorted by year.\n";
}

void Garage::confirmExit(bool &exitProgram) {
    char confirmation;
    std::cout << "Are you sure you want to exit? (y/n): ";
    std::cin >> confirmation;
    if (confirmation == 'y' || confirmation == 'Y') {
        exitProgram = true;
        std::cout << "Exiting program.\n";
    } else {
        std::cout << "Returning to menu.\n";
    }
}


