#include <bits/stdc++.h>
using namespace std;

class MaintenanceCheck {
    private:
        string vehicleType;
        string maintenanceType;

    public:
        MaintenanceCheck() {}
        MaintenanceCheck(string vehicleType, string maintenanceType)
            : vehicleType(vehicleType), maintenanceType(maintenanceType) {}

        void print() {
            cout << "<" << vehicleType << "> - " << maintenanceType << endl;
        }
};

class CargoCheck : public MaintenanceCheck {
    public:
        CargoCheck() : MaintenanceCheck() {}
        CargoCheck(string vehicleType) : MaintenanceCheck(vehicleType, "Cargo Check") {}
};

class PassengerCheck : public MaintenanceCheck {
    public:
        PassengerCheck(string vehicleType) : MaintenanceCheck(vehicleType, "Passenger Check") {}
};

class Vehicle {
    private:
        string licensePlate, manufacturer;
        float carriageSizeLimit;
        MaintenanceCheck check;

    public:
        Vehicle() {

        }
        string getLicensePlate() {
            return licensePlate;
        }

        void setLicensePlate(string licensePlate) {
            this->licensePlate = licensePlate;
        }

        string getManufactuerer() {
            return manufacturer;
        }

        void setManufacturer(string manufacturer) {
            this->manufacturer = manufacturer;
        }

        float getCarriageSizeLimit() {
            return carriageSizeLimit;
        }

        void setCarriageSizeLimit(float carriageSizeLimit) {
            if(carriageSizeLimit < 0) {
                cout << "Cannot be negative" << endl;
                return;
            }

            this->carriageSizeLimit = carriageSizeLimit;
        }

        void setCheck(MaintenanceCheck check) {
            this->check = check;
        }

        MaintenanceCheck getCheck() {
            return this->check;
        }
};

class GasolineVehicle : public Vehicle {
    public:
        enum FuelType {
            FT_PETROL,
            FT_OCTANE
        };
    private:    
        float fuelTankCapacity;
        FuelType fuelType;
    
    public:
        GasolineVehicle() : Vehicle() {}
        float getFuelTankCapacity() {
            return fuelTankCapacity;
        }

        void setFuelTankCapacity(float fuelTankCapacity) {
            if(fuelTankCapacity < 0) {
                cout << "Cannot be negative" << endl;
                return;
            }

            this->fuelTankCapacity = fuelTankCapacity;
        }

        FuelType getFuelType() {
            return fuelType;
        }

        void setFuelType(FuelType fuelType) {
            this->fuelType = fuelType;
        }
};

class ElectricVehicle : public Vehicle {
    private:
        float batteryCapacity;
        int chargingTime;
    
    public:
        float getBatteryCapacity() {
            return batteryCapacity;
        }

        void setBatteryCapacity(float batteryCapacity) {
            if(batteryCapacity < 0) {
                cout << "Cannot be negative" << endl;
                return;
            }
            this->batteryCapacity = batteryCapacity;
        }

        int getChargingTime() {
            return chargingTime;
        }

        void setChargingTime(int chargingTime) {
            if(chargingTime < 0) {
                cout << "Cannot be negative" << endl;
                return;
            }
            this->chargingTime = chargingTime;
        }
};

class Motorcycle : public GasolineVehicle {
    public:
        Motorcycle() {}
};

class Car : public GasolineVehicle {
    private:
        int passengerCount;
    public:
        Car() {}
        int getPassengerCount() {
            return passengerCount;
        }

        void setPassengerCount(int passengerCount) {
            if(passengerCount < 0) {
                cout << "Cannot be negative" << endl;
                return;
            }
            this->passengerCount = passengerCount;
        }
};

class Truck : public GasolineVehicle {
    private:
        int cargoCapacity;
    public:
        int getCargoCapacity() {
            return cargoCapacity;
        }

        void setCargoCapacity(int cargoCapacity) {
            if(cargoCapacity < 0) {
                cout << "Cannot be negative" << endl;
                return;
            }
            this->cargoCapacity = cargoCapacity;
        }
};

class HybridVehicle : public GasolineVehicle, public ElectricVehicle {
    private:
        float regenerationEfficiency;

    public:
        float getRegenerationEfficiency() {
            return regenerationEfficiency;
        }

        void setRegenerationEfficiency(float regenerationEfficiency) {
            if(regenerationEfficiency < 0 || regenerationEfficiency > 100) {
                cout << "Invalid efficiency value." << endl;
                return;
            }
            this->regenerationEfficiency = regenerationEfficiency;
        }
};

class Employee {
    private:
        int id;
        string name;
    public:
        int getId() {
            return id;
        }

        void setId(int id) {
            if(id < 0) {
                cout << "ID cannot be negative" << endl;
                return;
            }
            this->id = id;
        }

        string getName() {
            return name;
        }

        void setName(string name) {
            this->name = name;
        }
};

class Manager : public Employee {
    public:
        string getName() {
            return "Mr. " + Employee::getName();
        }
};

class Driver : public Employee {

};

class Branch {
    private:
        Motorcycle motorcycles[10];
        Car cars[10];
        Truck trucks[10];
        ElectricVehicle electricVehicles[10];
        HybridVehicle hybridVehicles[10];

        Manager managers[10];
        Driver drivers[30];
};

int main() {
    Motorcycle motorcycle;
    motorcycle.setLicensePlate("License Plate");
    cout << motorcycle.getLicensePlate() << endl;
    return 0;
}