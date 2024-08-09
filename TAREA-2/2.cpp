#include <iostream>
#include <string>

using namespace std;

class Vehicle {
public:
    string brand;
    string model;
    int year;

    Vehicle(string _brand, string _model, int _year) {
        brand = _brand;
        model = _model;
        year = _year;
    }

    void displayDetails() {
        cout << "Brand: " << brand << ", Model: " << model << ", Year: " << year << endl;
    }
};

class Car : public Vehicle {
public:
    int numberOfDoors;

    Car(string _brand, string _model, int _year, int _numberOfDoors)
        : Vehicle(_brand, _model, _year) {
        numberOfDoors = _numberOfDoors;
    }

    void displayDetails() {
        Vehicle::displayDetails();
        cout << "Number of Doors: " << numberOfDoors << endl;
    }
};

class Motorcycle : public Vehicle {
public:
    int engineDisplacement;

    Motorcycle(string _brand, string _model, int _year, int _engineDisplacement)
        : Vehicle(_brand, _model, _year) {
        engineDisplacement = _engineDisplacement;
    }

    void displayDetails() {
        Vehicle::displayDetails();
        cout << "Engine Displacement: " << engineDisplacement << " cc" << endl;
    }
};

int main() {
    Car car("Toyota", "Corolla", 2020, 4);
    car.displayDetails();

    Motorcycle motorcycle("Yamaha", "MT-07", 2021, 689);
    motorcycle.displayDetails();

    return 0;
}
