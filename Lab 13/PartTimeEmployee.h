#pragma once

#include "Employee.h"
#include <set>

class PartTimeEmployee : public Employee {
private:
    set<string> shifts;

public:
    PartTimeEmployee() : Employee::Employee(0, "") {}

    void addShift(string shift) {
        shifts.insert(shift);
    }

    void displayDetails() override {
        Employee::displayDetails();

        if(shifts.size() > 0) {
            cout << "\n Shifts: \n";
            for(string shift : shifts) {
                cout << shift << endl;
            }
        }
    }

    void saveData(ofstream of) {
        Employee::saveData(of);
        of.write(reinterpret_cast<char*>(shifts.size()), sizeof(shifts.size()));
        for(auto shift : shifts) {
            char shiftStr[100];
            strcpy(shiftStr, shift.c_str());
            of.write(shiftStr, sizeof(shiftStr)); 
        }
    }

    void loadData(ifstream ifile) {
        Employee::loadData(ifile);
        shifts.clear();
        int shiftSize;
        ifile.read(reinterpret_cast<char*>(shiftSize), sizeof(shiftSize));
        for(int i=0; i<shiftSize; i++) {
            char shiftStr[100];
            ifile.read(shiftStr, sizeof(shiftStr));
            shifts.insert(shiftStr);
        }
    }
};