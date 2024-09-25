#include <bits/stdc++.h>
using namespace std;

double PI;

class Calculator {
    private:
        float angle;
    public:
        Calculator(float angle) {
            this->angle = angle;
        }

        Calculator() {
            Calculator(0.0);
        }

        float getCurrent() {
            return angle;
        }

        void setCurrent(float angle) {
            this->angle = angle;
        }

        float calculateSine() {
            return sin(angle / (180/PI));
        }

        float calculateCosine() {
            return cos(angle / (180/PI));
        }

        float calculateTangent() {
            if(this->angle == 90 || this->angle == 270) {
                cout << "Invalid operation: undefined result." << endl;
                return -1;
            }
            return tan(this->angle / (180/PI));
        }

        float calculateArcSine() {
            cout << "Radian equivalent: " << this->angle / (180/PI) << endl;
            return asin(this->angle  / (180/PI));
        }

        float calculateArcCosine() {
            cout << "Radian equivalent: " << this->angle / (180/PI) << endl;
            return acos(this->angle  / (180/PI));
        }

        float calculateArcTangent() {
            cout << "Radian equivalent: " << this->angle / (180/PI) << endl;
            return asin(this->angle  / (180/PI));
        }

        void calculateForAngle(float paramAngle) {
            Calculator t(paramAngle);
            cout << "Sine: " << t.calculateSine() << endl
                << "Cosine: " << t.calculateCosine() << endl
                << "Tangent: " << t.calculateTangent() << endl;
        }

        void clear() {
            this->angle = 0;
        }

        void display() {
            cout << "Calculator display: " << this->angle << endl;
        }

        ~Calculator() {
            cout << "Destructor of the Calculator object is called." << endl;
        }
};

int main() {
    PI = 4*atan(1);

    cout << fixed << setprecision(3);

    Calculator t(90);
    cout << "Sine: " << t.calculateSine() << endl;
    cout << "Cosine: " << t.calculateCosine() << endl;
    cout << "Tangent: " << t.calculateTangent() << endl;
    cout << t.calculateArcSine() << endl;
    cout << t.calculateArcCosine() << endl;
    cout << t.calculateArcTangent() << endl;

    t.setCurrent(45);
    cout << "Sine: " << t.calculateSine() << endl;
    cout << "Cosine: " << t.calculateCosine() << endl;
    cout << "Tangent: " << t.calculateTangent() << endl;
    cout << t.calculateArcSine() << endl;
    cout << t.calculateArcCosine() << endl;
    cout << t.calculateArcTangent() << endl;

    t.calculateForAngle(180);

    return 0;
}