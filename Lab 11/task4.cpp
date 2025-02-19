// opers

#include <fstream>
#include <iostream>
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
    st.getData();
    st.showData();

    ofstream os("student.dat", ios::binary);
    os.write(reinterpret_cast<char*>(&st), sizeof(st));
    os.close();
    return 0;
}