// diskfun.cpp
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Student {
    private:
        char name[80];
        float cgpa;

    public:
        void getData() {
            cout << "Enter Name: " << endl;
            cin >> name;
            cout << "Enter CGPA: " << endl;
            cin >> cgpa;
        }

        void showData() {
            cout << "Name: " << name << endl;
            cout << "CGPA: " << cgpa << endl;
        }
};

int main() {
    fstream file;
    char ch;
    Student st;

    file.open("students.dat", ios::app | ios::binary | ios::in | ios::out);
    do {
        cout << "Enter student's data: " << endl;
        st.getData();
        file.write(reinterpret_cast<char*>(&st), sizeof(st));
        cout << "Enter another student? (y/n)";
        cin >> ch;
    } while(ch == 'y');
    file.seekg(0);
    
    while(true) {
        cout << "\nPerson: " << endl;
        file.read(reinterpret_cast<char*>(&st), sizeof(st));
        if(file.eof())
            break;
        st.showData();
    }
    return 0;
}