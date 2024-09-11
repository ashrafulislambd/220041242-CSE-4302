// Enumeration: chapter 4 excercise 6

#include <iostream>
using namespace std;

enum etype { laborer, secretary, manager, accountant, executive, researcher };

etype employee_type;

int main() {
    char first_letter;

    cout << "Enter employee type (first letter only)" << endl
        << "laborer, secretary, manager," << endl
        << "accountant, executive, researcher): ";
    cin >> first_letter;

    switch(first_letter) {
        case 'l':
            employee_type = laborer;
            break;
        case 's':
            employee_type = secretary;
            break;
        case 'm':
            employee_type = manager;
            break;
        case 'a':
            employee_type = accountant;
            break;
        case 'e':
            employee_type = executive;
            break;
        case 'r':
            employee_type = researcher;
            break;
        default:
            cout << "Invalid first letter. Exitting..." << endl;
            return 0;
    }
    
    string etype_text;

    switch(employee_type) {
        case laborer:
            etype_text = "laborer";
            break;
        case secretary:
            etype_text = "secretary";
            break;
        case manager:
            etype_text = "manager";
            break;
        case accountant:
            etype_text = "accountant";
            break;
        case executive:
            etype_text = "executive";
            break;
        case researcher:
            etype_text = "researcher";
            break;
    }

    cout << "Employee type is " << etype_text << endl;

    return 0;
}