#include <bits/stdc++.h>

using namespace std;

class Car {
    string make, model;
    double fuelCapacity, fuelLevel;

public:
    Car(string make, string model, double fuelCapacity, double fuelLevel) {
        this->make = make;
        this->model = model;
        this->fuelCapacity = fuelCapacity;
        this->fuelLevel = fuelLevel;
    }

    Car(string make, string model, double fuelCapacity) {
        this->make = make;
        this->model = model;
        this->fuelCapacity = fuelCapacity;
        this->fuelLevel = 0;
    }

    Car() {
        this->fuelLevel = 0;
    }

    Car& operator + (float other) {
        if(fuelLevel + other <= fuelCapacity) {
            Car* newCar = new Car(make, model, fuelCapacity, fuelLevel + other);
            return *newCar;
        }

    }

    Car& operator - (float other) {
        if(fuelLevel - other >= 0) {
            Car* newCar = new Car(make, model, fuelCapacity, fuelLevel - other);
            return *newCar;
        }
    }

    void operator += (float other) {
        if(fuelLevel + other <= fuelCapacity)
            fuelLevel += other;
    }

    void operator -= (float other) {
        if(fuelLevel - other >= 0)
            fuelLevel -= other;
    }

    bool operator == (const Car& other) const {
        return (
            make == other.make &&
            model == other.model &&
            fuelCapacity == other.fuelCapacity
        );
    }

    bool operator < (const Car& other) const {
        return fuelLevel < other.fuelLevel;
    }

    bool operator > (const Car& other) const {
        return fuelLevel > other.fuelLevel;
    }

    friend ostream& operator << (ostream& output, Car& car);
    friend istream& operator >> (istream& input, Car& car);
};

ostream& operator << (ostream& output, Car& car) {
    output << "Make: " << car.make << endl
            << "Model: " << car.model << endl
            << "Fuel Capacity: " << car.fuelCapacity << endl
            << "Fuel Level: " << car.fuelLevel << endl;
    return output;
}

istream& operator >> (istream& input, Car& car) {
    cout << "Enter Make: ";
    input >> car.make;
    cout << "Enter Model: ";
    input >> car.model;
    cout << "Enter Fuel Capacity: ";
    input >> car.fuelCapacity;
    cout << "Enter Fuel Level: ";
    input >> car.fuelLevel;
    return input;
}


int main() {
    Car c;
    cin >> c;
    cout << c << endl;

    c += 100;
    cout << c << endl;
    cout << (c+20) << endl;
    cout << (c-20) << endl;

    c -= 50;
    cout << c << endl;

    Car c2 = c + 20;
    cout << "\nCar1: \n" << c << endl;
    cout << "\nCar2: \n" << c2 << endl;
    if(c < c2) {
        cout << "The 2nd car has greater fuel level" << endl;
    } else {
        cout << "The 1st car has greater fuel level" << endl;
    }

    return 0;
}
