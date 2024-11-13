#pragma once
#include <iostream>
using namespace std;

class Vehicle {
protected:
    string licensePlate;
    string manufacturer;
    float carriageSizeLimit;

public:
    virtual void performMaintenance() = 0;

    float getCarriageSizeLimit() const;
    void setCarriageSizeLimit(float value);
    virtual void showInfo() const;
    string getLicensePlate() const;
    void setLicensePlate(string value);
    string getManufacturer() const;
    void setManufacturer(string value);
};