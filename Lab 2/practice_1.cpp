// Basic and input and output: chapter 2 exercise 9

#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    char dummychar;
    
    cout << "Enter first fraction: ";
    cin >> a >> dummychar >> b;

    cout << "Enter second fraction: ";
    cin >> c >> dummychar >> d;

    if(b == 0 || d == 0) {
        cout << "One of the fractions is invalid" << endl;
        return 0;
    }

    cout << "Sum: " << (a*d + b*c) << "/" << b*d << endl;

    return 0;
}