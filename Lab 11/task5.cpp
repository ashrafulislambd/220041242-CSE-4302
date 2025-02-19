// opers
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
    Student st;
    ifstream is("student.dat", ios::binary);
    is.read(reinterpret_cast<char*>(&st), sizeof(st));
    is.close();

    st.showData();

    return 0;
}