#include <iostream>
#include <vector>
#include <cstdlib>
#include "random_utils.h"
using namespace std;

int generateID(int id) {
    int full_id = 220041000 + id;
    return full_id;
}

class Student {
private:
    string name;
    string department;
    string program;
    string section;
    string address;
    int ID;

    int admissionYear;
    float GPA;

    static int count;
public:
    Student() {
        GPA = 0;
        this->ID = generateID(count);
        count++;
    }

    string getName() {
        return name;
    }

    int getID() {
        return ID;
    }

    void setName(string name) {
        this->name = name;
    }

    string getDepartment() {
        return department;
    }

    void setDepartment(string department) {
        this->department = department;
    }

    string getProgram() {
        return program;
    }

    void setProgram(string program) {
        this->program  = program;
    }

    string getSection() {
        return section;
    }

    void setSection(string section) {
        this->section = section;
    }

    string getAddress() {
        return address;
    }

    void setAddress(string address) {
        this->address = address;
    }

    int getadmissionYear() {
        return admissionYear;
    }

    void setAdmissionYear(int admissionYear) {
        this->admissionYear = admissionYear;
    }

    float getGPA() {
        return GPA;
    }

    void setGPA(float GPA) {
        if(GPA < 0 || GPA > 4) {
            cout << "Invalid GPA\n";
            return;
        }

        this->GPA = GPA;
    }

    float calculateGPA(vector<float>& course_marks) {
        float total = 0;
        int n = 0;
        for(auto mark : course_marks) {
            total += mark;
            n++;
        }
        float percentage = total / n;
        float gpa = percentage * (4.0/100);
        return gpa;
    }
};

int Student::count = 1;

void EditInformationByKeyboard(Student& student) {
    string name, department, program, section, address;
    int admissionYear, ID;
    float GPA;

    cout << "Name: ";
    cin >> name;
    cout << "Name: ";
    cin >> name;
    cout << "Department: ";
    cin >> department;
    cout << "Program: ";
    cin >> program;
    cout << "Section: ";
    cin >> section;
    cout << "Admission Year: ";
    cin >> admissionYear;
    cout << "Address: ";
    getline(cin, address);
    cout << "GPA: ";
    cin >> GPA;

    student.setName(name);
    student.setDepartment(department);
    student.setProgram(program);
    student.setSection(section);
    student.setAddress(address);
    student.setAdmissionYear(admissionYear);
    student.setGPA(GPA);
}

void generateInformationRandom(Student& student) {
    int firstNameLength = randomInRange(4, 10);
    int lastNameLength = randomInRange(4, 10);
    string firstName = generateRandomString(firstNameLength);
    string lastName = generateRandomString(lastNameLength);
    student.setName(firstName + " " + lastName);

    student.setAdmissionYear(randomInRange(2020, 2023));

    string address = "";
    for(int x=5; x--;) {
        int wordLength = randomInRange(4, 10);
        string word = generateRandomString(wordLength);
        address += word + " ";
    }
    address.pop_back();
    student.setAddress(address);

    student.setGPA(randomInRange(3.0, 4.0));
}

void ShowAllAlphabetically(Student ar[]) {
    for(int i=0; i<4; i++) {
        for(int j=i+1; j<5; j++) {
            if(ar[i].getID() > ar[j].getID()) {
                swap(ar[i], ar[j]);
            }
        }
    }

    for(int i=0; i<5; i++) {
        cout << "Name: " << ar[i].getName() << ", "
            << "ID: " << ar[i].getID() << ", "
            << "GPA: " << ar[i].getGPA() << endl;
    }
}

int main() {
    Student students[5];
    for(int i=0; i<5; i++) {
        srand(i);
        generateInformationRandom(students[i]);
    }
    ShowAllAlphabetically(students);
    return 0;
}
