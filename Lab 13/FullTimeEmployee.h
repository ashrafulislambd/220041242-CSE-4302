#pragma once

#include "Employee.h"
#include <set>

class FullTimeEmployee : public Employee {
private:
    set<string> workSchedule;

public:
    FullTimeEmployee() {}
    
    void addSchedule(string schedule) {
        workSchedule.insert(schedule);
    }

    void displayDetails() override {
        Employee::displayDetails();

        if(workSchedule.size() > 0) {
            cout << "\n Work Schedule: \n";
            for(string schedule : workSchedule) {
                cout << schedule << endl;
            }
        }
    }

    void saveData(ofstream of) {
        Employee::saveData(of);
        of.write(reinterpret_cast<char*>(workSchedule.size()), sizeof(workSchedule.size()));
        for(auto schedule : workSchedule) {
            char scheduleStr[100];
            strcpy(scheduleStr, schedule.c_str());
            of.write(scheduleStr, sizeof(scheduleStr)); 
        }
    }

    void loadData(ifstream ifile) {
        Employee::loadData(ifile);
        workSchedule.clear();
        int scheduleSize;
        ifile.read(reinterpret_cast<char*>(scheduleSize), sizeof(scheduleSize));
        for(int i=0; i<scheduleSize; i++) {
            char scheduleStr[100];
            ifile.read(scheduleStr, sizeof(scheduleStr));
            workSchedule.insert(scheduleStr);
        }
    }
};