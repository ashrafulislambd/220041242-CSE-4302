#include "GasolineVehicle.h"

void GasolineVehicle::performMaintenance() {
    cout << "Gasoline Vehicle Maintenance" << endl;
}

double GasolineVehicle::calculateFuelConsumption(double distance) {
    return fuelTankCapacity * distance;
}

void GasolineVehicle::setFuelTankCapacity(double value) {
    fuelTankCapacity = value;
}