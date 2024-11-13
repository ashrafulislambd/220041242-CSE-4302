#pragma once
#include "Vehicle.h"

class ElectricVehicle : public Vehicle {
protected:
    double batteryCapacity, chargingTime;

public:
    virtual void performMaintenance();
    virtual double electricityConsumption(double distance);

    void setBatteryCapacity(double value);
};