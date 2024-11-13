#include <bits/stdc++.h>
#include "Vehicle.h"
#include "GasolineVehicle.h"
#include "ElectricVehicle.h"
using namespace std;

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

    float getEnergyRegenerationEfficiency() const {
        return energyRegenerationEfficiency;
    }

    void setEnergyRegenerationEfficiency(float value) {
        energyRegenerationEfficiency = value;
    }

    void showInfo() {
        GasolineVehicle::showInfo();
        ElectricVehicle::showInfo();

        cout << "Energy Regeneration Efficiency: "
            << energyRegenerationEfficiency << endl;
    }
};

void sort_vehicles_by_capacity(Vehicle** vehicles, int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(vehicles[i] > vehicles[j]) {
                swap(vehicles[i], vehicles[j]);
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of vehicles: " << endl;
    cin >> n;
    Vehicle* vehicles[n];
    for(int i=0; i<n; i++) {
        cout << "Vehicle index #" << i+1 << ": " << endl;
        vehicles[i] = new GasolineVehicle();
        float carriageSizeLimit;
        string licensePlate;
        string manufacturer;
        cout << "Enter License Plate: ";
        cin >> licensePlate;
        cout << "Enter Manufacturer: ";
        cin >> manufacturer;
        cout << "Enter carriage size limit: ";
        cin >> carriageSizeLimit;
        vehicles[i]->setCarriageSizeLimit(carriageSizeLimit);
        vehicles[i]->setLicensePlate(licensePlate);
        vehicles[i]->setManufacturer(manufacturer);
    }

    sort_vehicles_by_capacity(vehicles, n);

    cout << "After sorting: " << endl;
    for(int i=0; i<n; i++) {
        cout << "Vehicle index #" << i+1 << ": " << endl;
        vehicles[i]->showInfo();
    }

    return 0;
}