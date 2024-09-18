#include <bits/stdc++.h>
using namespace std;

class Counter {
    private:
        int count = 0;
        int incrementStep = 5;
    public:
        void setIncrementStep(int step) {
            incrementStep = step;
        }

        int getCount() {
            return count;
        }

        void increment() {
            count += incrementStep;
        }

        void resetCount() {
            count = 0;
        }
};

int main() {
    Counter counter;
    cout << "Count at the beginning: " << counter.getCount() << endl;
    counter.increment();
    counter.increment();
    cout << "Count after two increments: " << counter.getCount() << endl;
    cout << "Setting increment step to 6" << endl;
    counter.setIncrementStep(6);
    counter.increment();
    cout << "Count value after one more increment: " << counter.getCount() << endl;
    return 0;
}