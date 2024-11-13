#include <bits/stdc++.h>
#include "Vehicle.h"
#include "GasolineVehicle.h"
#include "ElectricVehicle.h"
using namespace std;

class Motorcycle : public GasolineVehicle {
public:
    void performMaintenance() {
        cout << "Motorcycle - maintenance" << endl;
    }

    double calculateFuelConsumption(double distance) {
        return (distance/100) * fuelTankCapacity; // litters per 100 km
    } 
};

class Car : public GasolineVehicle {
protected:
    int passengerCapacity;
public:
    void performMaintenance() {
        cout << "Car - maintenance" << endl;
    }

    double calculateFuelConsumption(double distance) {
        return (distance/50) * fuelTankCapacity; // litters per 50 km
    } 
};

class Truck : public GasolineVehicle {
protected:
    int cargoCapacity;
public:
    void performMaintenance() {
        cout << "Truck - maintenance" << endl;
    }

    double calculateFuelConsumption(double distance) {
        return (distance/1000) * fuelTankCapacity; // litters per 1000 km
    } 
};

class HybridVehicle : public GasolineVehicle, public ElectricVehicle {
protected:
    float energyRegenerationEfficiency;
public:
    void performMaintenance() {
        cout << "Hybrid Vehicle - maintenance" << endl;
    }

    double calculateFuelConsumption(double distance) {
        return distance*chargingTime + distance*fuelTankCapacity;
    }
};

int main() {
    Motorcycle m;
    Car c;
    Truck t;
    HybridVehicle h;
    m.performMaintenance();
    c.performMaintenance();
    t.performMaintenance();
    h.performMaintenance();

    m.setFuelTankCapacity(10);
    c.setFuelTankCapacity(15);
    t.setFuelTankCapacity(16);
    h.setFuelTankCapacity(19);
    h.setBatteryCapacity(20);

    cout << m.calculateFuelConsumption(1000) << endl;
    cout << c.calculateFuelConsumption(1000) << endl;
    cout << t.calculateFuelConsumption(1000) << endl;
    cout << h.calculateFuelConsumption(1000) << endl;
    return 0;
}