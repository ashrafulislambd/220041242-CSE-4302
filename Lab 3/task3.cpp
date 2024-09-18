#include <bits/stdc++.h>
#include <cstring>
using namespace std;

class Medicine {
    private:
        char tradeName[30];
        char genericName[30];
        double price;
        double discountPercent;

    public:
        void assignName(char name[], char genericName[]) {
            strcpy(this->tradeName, name);
            strcpy(this->genericName, genericName);
        }

        void assignPrice(double price) {
            if(price < 0) {
                cout << "Price must be non-negative." << endl;
                return;
            }
            this->price = price;
        }

        void setDiscountPercent(double percent) {
            if(percent < 0 || percent > 30) {
                cout << "Value must be within 0-30%." << endl;
                return;
            }

            this->discountPercent = percent;
        }

        double getSellingPrice(int nos) {
            double singleProductPrice = this->price*(1 - discountPercent/100);
            return singleProductPrice * nos;
        }

        double getSellingPrice() {
            return getSellingPrice(1);
        }

        void display() {
            cout << "MRP. of " << this->tradeName << " (" << this->genericName <<
                ") is BDT " << this->price << ". Current discount " << this->discountPercent <<
                "%. Selling price BDT " << this->getSellingPrice() << "." << endl;
        }
};

int main() {
    Medicine med;
    med.assignName("Napa", "Paracetamol");
    med.assignPrice(1);
    med.setDiscountPercent(10);
    med.display();
    return 0;
}