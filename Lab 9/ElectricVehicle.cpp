#include "ElectricVehicle.h"
#include <iostream>
using namespace std;

void ElectricVehicle::performMaintenance() {
    cout << "Electric Vehicle Maintenance" << endl;
}

void ElectricVehicle::setBatteryCapacity(double value) {
    batteryCapacity = value;
}

double ElectricVehicle::electricityConsumption(double distance) {
    return batteryCapacity * distance;
}