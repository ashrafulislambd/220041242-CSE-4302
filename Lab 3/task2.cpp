#include <bits/stdc++.h>
using namespace std;

class RationalNumber {
    private:
        int numerator;
        int denominator = 1;

        bool isNegative() {
            return this->numerator * this->denominator < 0;
        }
    public:
        void assign(int numerator, int denominator) {
            if(denominator == 0) {
                cout << "You can not assign 0 as denominator" << endl;
                return;
            }

            this->numerator = numerator;
            this->denominator = denominator;
        }

        float convert() {
            return (float)numerator/denominator;
        }

        int invert() {
            if(numerator == 0) {
                cout << "You can not assign 0 as denominator." << endl
                    << "Inversion Failed." << endl;
            }
            int temp = numerator;
            numerator = denominator;
            denominator = temp;
            return 0;
        }

        void print() {
            cout << "The Rational Number is ";
            if(this->isNegative()) {
                cout << "-";
            }
            cout << abs(numerator) << "/" << abs(denominator) << endl;
        }
};

int main() {
    RationalNumber num;
    num.assign(-3, 2);
    num.print();

    num.invert();
    num.print();

    num.assign(0, 3);
    num.print();

    num.invert();

    num.assign(3, 0);
    return 0;
}