#include <iostream>
#include <conio.h>
#include <cstdlib>
#include "Garage.h"
#include <limits>

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
    while (!(std::cin >> naped) || naped < 0) {
        std::cout << "Invalid input. Please enter a positive integer value.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    car.setNaped(naped);

    std::cout << "Enter car year of production: ";
    while (!(std::cin >> rokProdukcji) || rokProdukcji < 0) {
        std::cout << "Invalid input. Please enter a positive numeric value.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    car.setRokProdukcji(rokProdukcji);

    std::cout << "Enter car mileage: ";
    while (!(std::cin >> przebieg) || przebieg < 0) {
        std::cout << "Invalid input. Please enter a positive integer value.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    car.setPrzebieg(przebieg);

    return car;
}

int main() {
    Garage garage;
    char choice;
    int currentIndex = 0;

    do {
        showMenu();
        choice = _getch();

        switch (choice) {
            case '1': {
                system("cls");
                Car car = createCar();
                garage.addCarToGarage(car);
                break;
            }
            case '2': {
                system("cls");
                int index;
                std::cout << "Enter the index of the car to delete: ";
                while (!(std::cin >> index) || index <= 0) {
                    std::cout << "Invalid input. Please enter a positive integer value.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                garage.deleteCarFromGarage(index - 1);
                break;
            }
            case '3': {
                system("cls");
                int index;
                std::cout << "Enter the index of the car to update: ";
                while (!(std::cin >> index) || index <= 0) {
                    std::cout << "Invalid input. Please enter a positive integer value.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                Car updatedCar = createCar();
                garage.updateCar(index - 1, updatedCar);
                break;
            }
            case '4': {
                char nav;
                do {
                    system("cls");
                    garage.viewCars(currentIndex);
                    std::cout << "\n\n                                   Navigate                                   \n|n - next | p - previous | d - delete | e - edit | q - quit | c - clear|: ";
                    nav = _getch();
                    if (nav == 'n') currentIndex++;
                    else if (nav == 'p') currentIndex--;
                    else if (nav == 'd') {
                        garage.deleteCarFromGarage(currentIndex);
                    } else if (nav == 'e') {
                        std::cout << "Editing car...\n";
                        Car updatedCar = createCar();
                        garage.updateCar(currentIndex, updatedCar);
                    }
                    else if(nav == 'c') currentIndex = 0;
                } while (nav != 'q');
                system("cls");
                break;
            }
            case '5': {
                system("cls");
                std::string filename;
                std::cout << "Enter filename to save to: ";
                std::cin >> filename;
                garage.saveToFile(filename);
                break;
            }
            case '6': {
                system("cls");
                std::string filename;
                std::cout << "Enter filename to load from: ";
                std::cin >> filename;
                garage.loadFromFile(filename);
                break;
            }
            case '7': {
                system("cls");
                std::string filename;
                std::cout << "Enter filename to create: ";
                std::cin >> filename;
                garage.createNewFile(filename);
                break;
            }
            case '8': {
                system("cls");
                std::string model;
                std::cout << "Enter model to search for: ";
                std::cin >> model;
                garage.searchByModel(model);
                break;
            }
            case '9': {
                system("cls");
                double minYear, maxYear;
                std::cout << "Enter minimum year: ";
                while (!(std::cin >> minYear) || minYear < 0) {
                    std::cout << "Invalid input. Please enter a positive numeric value.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                std::cout << "Enter maximum year: ";
                while (!(std::cin >> maxYear) || maxYear < 0) {
                    std::cout << "Invalid input. Please enter a positive numeric value.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                garage.searchByYearRange(minYear, maxYear);
                break;
            }
            case 'a': {
                system("cls");
                char order;
                std::cout << "Sort by year (a for ascending, d for descending): \n";
                do{
                	order = _getch();
                	if (order == 'a') {
                    	garage.sortByYear(true);
                    	break;
                	}
					else if (order == 'd') {
                    	garage.sortByYear(false);
                    	break;
                	} 
					else {
                    	std::cout << "Invalid input. Sorting aborted.\n";
                	}
				}while(order != 'a' || order != 'b');
                break;
            }
            case 's': {
                system("cls");
                std::cout << "Goodbye Mister/Missus" << std::endl;
                break;
            }
            default:
                system("cls");
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 's');

    return 0;
}
