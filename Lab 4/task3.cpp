#include <bits/stdc++.h>
using namespace std;

class Employee {
    private:
        string name;
        int id;
        int age;
        float salary;

    public:
        Employee(string name, int id, int age, float salary)
            : name(name), id(id), age(age), salary(salary) {

        }

        Employee() {

        }

        void FeedInfo() {
            cout << "Enter Name: " << endl;
            cin >> name;
            cout << "Enter ID: " << endl;
            cin >> id;
            cout << "Enter Age: " << endl;
            cin >> age;
            cout << "Enter Salary: " << endl;
            cin >> salary;
        }

        void ShowInfo() {
            cout << "Name: " << name << endl
                << "ID: " << id << endl
                << "Age: " << age << endl
                << "Salary: " << salary << endl;

            if(age <= 25 && salary > 20000) {
                cout << "Status: Moderate" << endl;
            }

            if(age <= 25 && salary <= 20000) {
                cout << "Status: Low" << endl;
            }

            if(age > 25) {
                if(salary <= 21000) {
                    cout << "Status: Low" << endl;
                } else if(salary > 21000 && salary <= 60000) {
                    cout << "Status: Moderate" << endl;
                } else if(salary > 60000) {
                    cout << "Status: High" << endl;
                }
            }
        }
};

int main() {
    Employee emp;
    emp.FeedInfo();
    emp.ShowInfo();
    return 0;
}