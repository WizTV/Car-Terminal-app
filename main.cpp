#include <iostream>
#include <conio.h>
#include <cstdlib>
#include "Garage.h"

void showMenu() {
    std::cout << "\n=== Garage Management Menu ===\n";
    std::cout << "1. Add a new car\n";
    std::cout << "2. Delete a car\n";
    std::cout << "3. Update car details\n";
    std::cout << "4. View cars\n";
    std::cout << "5. Save garage to file\n";
    std::cout << "6. Load garage from file\n";
    std::cout << "7. Create a new file\n";
    std::cout << "8. Search by model\n";
    std::cout << "9. Search by year range\n";
    std::cout << "a. Sort cars by year\n";
    std::cout << "s. Exit program\n";
}

Car createCar() {
    Car car;
    std::string marka, model, color;
    int naped, przebieg;
    double rokProdukcji;
    
    system("cls");

    std::cout << "Enter car marka: ";
    std::cin >> marka;
    car.setMarka(marka);

    std::cout << "Enter car model: ";
    std::cin >> model;
    car.setModel(model);

    std::cout << "Enter car color: ";
    std::cin >> color;
    car.setColor(color);

    std::cout << "Enter car naped (1 for AWD, 2 for FWD, etc.): ";
    std::cin >> naped;
    car.setNaped(naped);

    std::cout << "Enter car year of production: ";
    std::cin >> rokProdukcji;
    car.setRokProdukcji(rokProdukcji);

    std::cout << "Enter car mileage: ";
    std::cin >> przebieg;
    car.setPrzebieg(przebieg);

    return car;
}

int main() {
    Garage garage;
    char choice;
	int currentIndex = 0;
   
   do{
        showMenu();
        choice = _getch();

        switch (choice) {
            case '1': {
                Car car = createCar();
                garage.addCarToGarage(car);
                break;
            }
            case '2': {
                int index;
                std::cout << "Enter the index of the car to delete: ";
                std::cin >> index;
                garage.deleteCarFromGarage(index - 1);
                break;
            }
            case '3': {
                int index;
                std::cout << "Enter the index of the car to update: ";
                std::cin >> index;
                Car updatedCar = createCar();
                garage.updateCar(index - 1, updatedCar);
                break;
            }
            case '4': {
                char nav;
                garage.viewCars(currentIndex);
                std::cout << "Navigate (n for next, p for previous, q to quit): ";
                std::cin >> nav;
                if (nav == 'n') currentIndex++;
                else if (nav == 'p') currentIndex--;
                break;
            }
            case '5': {
                std::string filename;
                std::cout << "Enter filename to save to: ";
                std::cin >> filename;
                garage.saveToFile(filename);
                break;
            }
            case '6': {
                std::string filename;
                std::cout << "Enter filename to load from: ";
                std::cin >> filename;
                garage.loadFromFile(filename);
                break;
            }
            case '7': {
                std::string filename;
                std::cout << "Enter filename to create: ";
                std::cin >> filename;
                garage.createNewFile(filename);
                break;
            }
            case '8': {
                std::string model;
                std::cout << "Enter model to search for: ";
                std::cin >> model;
                garage.searchByModel(model);
                break;
            }
            case '9': {
                double minYear, maxYear;
                std::cout << "Enter minimum year: ";
                std::cin >> minYear;
                std::cout << "Enter maximum year: ";
                std::cin >> maxYear;
                garage.searchByYearRange(minYear, maxYear);
                break;
            }
            case 'a': {
                char order;
                std::cout << "Sort by year (a for ascending, d for descending): ";
                std::cin >> order;
                garage.sortByYear(order == 'a');
                break;
            }
            case 's': {
                std::cout << "DO WIDZENIA" << std::endl;
                break;
            }
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }while(choice != 's');

    return 0;
}
