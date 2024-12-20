#include <iostream>
#include <conio.h>
#include <cstdlib>
#include "Garage.h"
#include <limits>
#include <algorithm>

void showMenu() {
    std::cout << "\n=== Garage Management Menu ===\n";
    std::cout << "1. Add a new car\n";
    std::cout << "2. Manage trash\n";
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
        std::cout << "Invalid input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    car.setNaped(naped);

    std::cout << "Enter car year of production: ";
    while (!(std::cin >> rokProdukcji) || rokProdukcji < 0) {
        std::cout << "Invalid input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    car.setRokProdukcji(rokProdukcji);

    std::cout << "Enter car mileage: ";
    while (!(std::cin >> przebieg) || przebieg < 0) {
        std::cout << "Invalid input.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    car.setPrzebieg(przebieg);

    return car;
}

int main() {
    Garage garage, trash;
    char choice;
    int currentIndex = 0;
    int currentIndexTrash = 0;
    std::vector<int> selectedIndexes;

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
			    char nav;
			    do {
			        system("cls");
			        for (int i = 0; i < trash.getCarCount(); ++i) {
			            std::cout << i + 1 << ". " << trash.getCarByIndex(i).getCarInfo();
			            if (std::find(selectedIndexes.begin(), selectedIndexes.end(), i) != selectedIndexes.end()) {
			                std::cout << " [SELECTED]";
			            }
			            if (i == currentIndexTrash) {
			                std::cout << " <---";
			            }
			            std::cout << std::endl;
			        }
			
					//trash.viewCars(currentIndexTrash); // Alternative version of viewing
					
			        std::cout << "\n\n                         Navigate:\n";
			        std::cout << "| n - next | p - previous | r - restore | q - quit | c - clear |\n";
			        std::cout << "    | ; - select | '-' - unselect | v - restore selected |\n";
			        std::cout << "         | a - delete all | s - delete selected|\n";
			        std::cout << "\n\n*NOTE - deleting from Trash will delete the car permanently.";
			        nav = _getch();

			        if (nav == 'n') {
			            if (currentIndexTrash < trash.getCarCount() - 1) {
			                currentIndexTrash++;
			            }
			        } else if (nav == 'p') {
			            if (currentIndexTrash > 0) {
			                currentIndexTrash--;
			            }
			        } else if (nav == 'r') {
			        	if(trash.getCarCount() > 0){
			            garage.addCarToGarage(trash.getCarByIndex(currentIndexTrash));
			            trash.deleteCarFromGarage(currentIndexTrash);	
						}
			            if (currentIndexTrash >= trash.getCarCount() && trash.getCarCount() > 0) {
			                currentIndexTrash = trash.getCarCount() - 1;
			            }
			        } else if (nav == 'c') {
			            currentIndexTrash = 0;
			        } else if (nav == ';') {
			            if (std::find(selectedIndexes.begin(), selectedIndexes.end(), currentIndexTrash) == selectedIndexes.end()) {
			                selectedIndexes.push_back(currentIndexTrash);
			                std::sort(selectedIndexes.rbegin(), selectedIndexes.rend());
			            }
			        } else if (nav == '-') {
			            auto it = std::find(selectedIndexes.begin(), selectedIndexes.end(), currentIndexTrash);
			            if (it != selectedIndexes.end()) {
			                selectedIndexes.erase(it);
			            }
			        } else if (nav == 'v') {
			            std::sort(selectedIndexes.rbegin(), selectedIndexes.rend());
			            for (int i : selectedIndexes) {
			                garage.addCarToGarage(trash.getCarByIndex(i));
			                trash.deleteCarFromGarage(i);
			            }
			            selectedIndexes.clear();
			        } else if (nav == 's') {
			            std::sort(selectedIndexes.rbegin(), selectedIndexes.rend());
			            for (int i : selectedIndexes) {
			                trash.deleteCarFromGarage(i);
			            }
			            selectedIndexes.clear();
			        } else if (nav == 'a') {
						trash.emptyGarage();					}
			    	} 
				while (nav != 'q');
			    selectedIndexes.clear();
			    system("cls");
			    break;
			}
            case '3': {
                system("cls");
                int index;
                std::cout << "Enter the index of the car to update: ";
                while (!(std::cin >> index) || index <= 0) {
                    std::cout << "Invalid input.\n";
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
			        for (int i = 0; i < garage.getCarCount(); ++i) {
			            std::cout << i + 1 << ". " << garage.getCarByIndex(i).getCarInfo();
			            if (std::find(selectedIndexes.begin(), selectedIndexes.end(), i) != selectedIndexes.end()) {
			                std::cout << " [SELECTED]";
			            }
			            if (i == currentIndex) {
			                std::cout << " <---";
			            }
			            std::cout << std::endl;
			        }
			        
			        //garage.viewCars(currentIndex); // Alternative version of viewing
			
			        std::cout << "\n\n                            Navigate:\n";
			        std::cout << "| n - next | p - previous | d - delete | q - quit | e - edit | c - clear |\n";
			        std::cout << "         | ; - select | '-' - unselect | v - delete selected |\n";
			        nav = _getch();
			
			        if (nav == 'n') {
			            if (currentIndex < garage.getCarCount() - 1) {
			                currentIndex++;
			            }
			        } else if (nav == 'p') {
			            if (currentIndex > 0) {
			                currentIndex--;
			            }
			        } else if (nav == 'd') {
			            if(garage.getCarCount() > 0) {
			            	trash.addCarToGarage(garage.getCarByIndex(currentIndex));
			            	garage.deleteCarFromGarage(currentIndex);
						}
			            if (currentIndex >= garage.getCarCount() && garage.getCarCount() > 0) {
			                currentIndex = garage.getCarCount() - 1;
			            }
			        } else if (nav == 'e') {
			            Car updatedCar = createCar();
			            garage.updateCar(currentIndex, updatedCar);
			        } else if (nav == 'c') {
			            currentIndex = 0;
			        } else if (nav == ';') {
			            if (std::find(selectedIndexes.begin(), selectedIndexes.end(), currentIndex) == selectedIndexes.end()) {
			                selectedIndexes.push_back(currentIndex);
			                std::sort(selectedIndexes.rbegin(), selectedIndexes.rend());
			            }
			        } else if (nav == '-') {
			            auto it = std::find(selectedIndexes.begin(), selectedIndexes.end(), currentIndex);
			            if (it != selectedIndexes.end()) {
			                selectedIndexes.erase(it);
			            }
			        } else if (nav == 'v') {
			            std::sort(selectedIndexes.rbegin(), selectedIndexes.rend());
			            for (int i : selectedIndexes) {
			                trash.addCarToGarage(garage.getCarByIndex(i));
			                garage.deleteCarFromGarage(i);
			            }
			            selectedIndexes.clear();
			        }
			    } while (nav != 'q');
			    selectedIndexes.clear();
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
                    std::cout << "Invalid input.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                std::cout << "Enter maximum year: ";
                while (!(std::cin >> maxYear) || maxYear < 0) {
                    std::cout << "Invalid input.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                garage.searchByYearRange(minYear, maxYear);
                break;
            }
            case 'a': {
                system("cls");
                char order;
                std::cout << "Sort by year (a for ascending, d for descending): ";
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
