// Structure: chapter 4 exercise 8

#include <iostream>
using namespace std;

typedef struct {
    int numerator;
    int denominator;
} fraction;

int main() {
    fraction f1, f2;
    char dummychar;
    
    cout << "Enter first fraction: ";
    cin >> f1.numerator >> dummychar >> f1.denominator;

    cout << "Enter second fraction: ";
    cin >> f2.numerator >> dummychar >> f2.denominator;

    if(f1.denominator == 0 || f2.denominator == 0) {
        cout << "One of the fractions is invalid" << endl;
        return 0;
    }

    fraction res;
    res.numerator = f1.numerator * f2.denominator + f1.denominator * f2.numerator;
    res.denominator = f1.denominator * f2.denominator;

    cout << "Sum: " << res.numerator << "/" << res.denominator << endl;

    return 0;
}