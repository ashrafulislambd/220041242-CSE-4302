#pragma once

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Employee {
private:
    char name[100];
    int id;

public:
    Employee(int id, string name) : id(id) {
        strcpy(this->name, name.c_str());
    }

    string getName() const {
        return name;
    }

    void setName(string name) {
        strcpy(this->name, name.c_str());
    }

    int getId() const {
        return id;
    }

    void setId(int id) {
        this->id = id;
    }

    void displayDetails() {
        cout << "Employee #" << id << endl
            << "Name: " << name << endl;
    }

    void saveData(ofstream& of) {
        of.write(name, sizeof(name));
        of.write(reinterpret_cast<char*>(id), sizeof(id));
    } 

    void loadData(ifstream& ifile) {
        ifile.read(name, sizeof(name));
        ifile.read(reinterpret_cast<char*>(id), sizeof(id));
    } 
};