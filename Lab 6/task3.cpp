#include <bits/stdc++.h>
using namespace std;

class Farenheit;
class Kelvin;

class Celsius {
private:
    double temp;
public:
    Celsius() {
        temp = 0;
    }

    void assign(double temp) {
        this->temp = temp;
    }

    void display() {
        cout << "The temperature is " << temp << " Celsius." << endl;
    }

    operator Farenheit();
    operator Kelvin();
};

class Farenheit {
private:
    double temp;
public:
    Farenheit() {
        temp = 0;
    }

    void assign(double temp) {
        this->temp = temp;
    }

    void display() {
        cout << "The temperature is " << temp << " Farenheit." << endl;
    }
};

class Kelvin {
private:
    double temp;
public:
    Kelvin() {
        temp = 0;
    }

    void assign(double temp) {
        this->temp = temp;
    }

    void display() {
        cout << "The temperature is " << temp << " Kelvin." << endl;
    }
};

Celsius::operator Farenheit() {
    int ftemp = temp*9/5 + 32;
    Farenheit* fobj = new Farenheit();
    fobj->assign(ftemp);
    return *fobj;
}

Celsius::operator Kelvin() {
    int ktemp = temp + 273.15;
    Kelvin* kobj = new Kelvin();
    kobj->assign(ktemp);
    return *kobj;
}

int main() {
    Celsius temp;
    temp.assign(100);
    temp.display();
    ((Farenheit)temp).display();
    ((Kelvin)temp).display();
    return 0;
}
