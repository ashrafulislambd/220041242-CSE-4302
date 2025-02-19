// seekg.cpp
#include <iostream>
#include <fstream>

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
    ifstream is;
    is.open("students.dat", ios::binary | ios::in);
    Student st;

    is.seekg(0, ios::end);
    int endpos = is.tellg();
    int n = endpos / sizeof(Student);

    cout << "There are " << n << " students" << endl;
    cout << "Enter student number: " << endl;
    int i; cin >> i;
    int pos = (i-1) * sizeof(Student);

    is.seekg(pos);
    is.read(reinterpret_cast<char*>(&st), sizeof(st));
    st.showData();
    cout << endl;
    is.close();
    return 0;
}