#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <string>
#include "Garage.h"
#include "Car.h"

using namespace std;

int main() {
    char choice;
    bool running = true;
    Garage garage;

    while (running) {
        system("cls");
        cout << "Menu:" << endl;
        cout << "1. Add Car" << endl;
        cout << "2. Delete Car" << endl;
        cout << "s. Stop program" << endl;
        cout << "Wybierz opcje: ";

        choice = _getch();

        switch (choice) {
            case '1': {
                Car car;
                int naped;
                string color, model, marka;
                double rokProdukcji;
                int przebieg;

                cout << "Enter naped: ";
                cin >> naped;
                car.setNaped(naped);

                cout << "Enter color: ";
                cin >> color;
                car.setColor(color);

                cout << "Enter model: ";
                cin >> model;
                car.setModel(model);

                cout << "Enter marka: ";
                cin >> marka;
                car.setMarka(marka);

                cout << "Enter rok produkcji: ";
                cin >> rokProdukcji;
                car.setRokProdukcji(rokProdukcji);

                cout << "Enter przebieg: ";
                cin >> przebieg;
                car.setPrzebieg(przebieg);

                garage.addCarToGarage(car);

                cout << "Car added to the garage." << endl;
                break;
            }
            case '2': {
                int index;
                cout << "Enter car index to delete: ";
                cin >> index;
                garage.deleteCarFromGarage(index);
                cout << "Car deleted from the garage." << endl;
                break;
            }
            case 's':
                cout << "Stopping the program..." << endl;
                running = false;
                break;
            default:
                cout << "Unknown option, try again." << endl;
                break;
        }

        system("pause");
    }

    return 0;
}
