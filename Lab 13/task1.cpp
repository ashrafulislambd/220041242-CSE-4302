#include <iostream>
#include <map>
#include "Employee.h"
#include "FullTimeEmployee.h"
#include "PartTimeEmployee.h"
using namespace std;

map<int, Employee*> employees;

void addEmployee(const Employee& employee) {
    employees[employee.getId()] = (Employee*)(&employee);
}

void assignSchedule(FullTimeEmployee& employee, string schedule) {
    employee.addSchedule(schedule);
}

void assignShift(PartTimeEmployee& employee, string shift) {
    employee.addShift(shift);
}

void saveData() {
    ofstream of_full("fulltime_employees.txt", ios::binary);
    ofstream of_part("parttime_employees.txt", ios::binary);

    if(!of_full || !of_part) {
        cout << "Couldn't open output file(s). Aborting..." << endl;
        return;
    }

    int count_full = 0, count_part = 0;
    for(auto& [id, employee] : employees) {
        if(typeid(*employee) == typeid(FullTimeEmployee)) {
            count_full++;
        } else if(typeid(*employee) == typeid(PartTimeEmployee)) {
            count_part++;
        }
    }

    of_full.write(reinterpret_cast<char*>(count_full), sizeof(count_full));
    of_part.write(reinterpret_cast<char*>(count_part), sizeof(count_part));
    for(auto& [id, employee] : employees) {
        if(typeid(*employee) == typeid(FullTimeEmployee)) {
            employee->saveData(of_full);
        } else if(typeid(*employee) == typeid(PartTimeEmployee)) {
            employee->saveData(of_part);
        }
    }
}

void loadData() {
    ifstream if_full("fulltime_employees.txt", ios::binary);
    ifstream if_part("parttime_employees.txt", ios::binary);

    if(!if_full || !if_part) {
        cout << "Failed to load employee data(s). Aborting..." << endl;
        return;
    }

    int count_full = 0, count_part = 0;
    employees.clear();

    if_full.read(reinterpret_cast<char*>(count_full), sizeof(count_full));
    if_part.read(reinterpret_cast<char*>(count_part), sizeof(count_part));

    for(int i=0; i<count_full; i++) {
        Employee* employee = new FullTimeEmployee();
        employee->loadData(if_full);
        addEmployee(*employee);
    }

    for(int i=0; i<count_part; i++) {
        Employee* employee = new PartTimeEmployee();
        employee->loadData(if_part);
        addEmployee(*employee);
    } 
}


int main() {
    int com;
    do {
        cout << "1. Add Employee" << endl
             << "2. Assign Work Schedule" << endl
             << "3. Assign Shift" << endl
             << "4. Display Data" << endl
             << "5. Save Data" << endl
             << "6. Load Data" << endl
             << "7. Exit" << endl;
        
        cin >> com;
        if(com == 1) {
            int empId;
            string empName, empType;
            cout << "Enter employee ID: ";
            cin >> empId;
            cout << "Enter employee name: ";
            cin >> empName;
            cout << "Enter employee type (Full-Time/Part-Time): ";
            cin >> empType;

            if(empType == "Full-Time") {
                FullTimeEmployee* employee = new FullTimeEmployee();
                employee->setId(empId);
                employee->setName(empName);
                addEmployee(*employee);
            } else if(empType == "Part-Time") {
                PartTimeEmployee* employee = new PartTimeEmployee();
                employee->setId(empId);
                employee->setName(empName);
                addEmployee(*employee);
            }
        }
    } while(com != 7);
    return 0;
}