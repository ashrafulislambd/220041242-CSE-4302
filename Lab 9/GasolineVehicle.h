#pragma once
#include "Vehicle.h"

class GasolineVehicle : public Vehicle {
protected:
    double fuelTankCapacity;
    enum FuelType {
        FUEL_TYPE_PETROL,
        FUEL_TYPE_OCTANE,
        FUEL_TYPE_CNG
    };
    FuelType fuelType;
public:
    virtual void performMaintenance();
    virtual double calculateFuelConsumption(double distance);
    void setFuelTankCapacity(double value);
};