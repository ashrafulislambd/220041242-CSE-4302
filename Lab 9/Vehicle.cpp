#include "Vehicle.h"

void Vehicle::setCarriageSizeLimit(float value) {
    carriageSizeLimit = value;
}

float Vehicle::getCarriageSizeLimit() const {
    return carriageSizeLimit;
}

string Vehicle::getLicensePlate() const {
    return licensePlate;
}

void Vehicle::setLicensePlate(string value) {
    licensePlate = value;
}

string Vehicle::getManufacturer() const {
    return manufacturer;
}

void Vehicle::setManufacturer(string value) {
    manufacturer = value;
}

void Vehicle::showInfo() const {
    cout << "License Plate: " << licensePlate << endl
        << "Manufacturer: " << manufacturer << endl
        << "Carriage Size Limit: " << carriageSizeLimit << endl;
}