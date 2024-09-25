#include <bits/stdc++.h>
using namespace std;

enum AccountType {
    Current,
    Savings
};

class BankAccount {
    private:
        int accountNo;
        string holderName;
        AccountType accountType;
        float currentBalance;
        const float minimumBalance;
    public:
        static int totalCreated;
        static int objectCount;

        BankAccount(int accountNo,
                    string holderName,
                    AccountType accountType,
                    float minimumBalance) 
                    : accountNo(accountNo), 
                      holderName(holderName), 
                      accountType(accountType), 
                      currentBalance(minimumBalance), 
                      minimumBalance(minimumBalance) 
        {
            objectCount++;
            totalCreated++;
        }

        BankAccount(const BankAccount& obj) : minimumBalance(obj.minimumBalance) {
            objectCount++;
            totalCreated++;
        }

        void showInfo() {
            cout << "Account Number: " << accountNo << endl
                << "Holder Name: " << holderName << endl
                << "Account Type: " << (accountType == Current ? "Current" : "Savings") << endl
                << "Current Balance: " << currentBalance << endl
                << "Min. Balance: " << minimumBalance << endl;
        }

        void showBalance() {
            cout << "Current Balance: " << currentBalance << endl;
        }

        float getBalance() const {
            return this->currentBalance;
        }

        void deposit(float amount) {
            if(amount <= 0) {
                cout << "Please provide a valid amount" << endl;
                return;
            }
            currentBalance += amount;
        }

        void withdrawal(float amount) {
            if(amount <= 0) {
                cout << "Please provide a valid amount" << endl;
                return;
            }

            if(currentBalance - amount < minimumBalance) {
                cout << "Cannot withdraw this amount of money. Your account must maintain a minimum balance" << endl;
                return;
            }

            currentBalance -= amount;
        }

        void giveInterest() {
            currentBalance *= 1.03;
            currentBalance *= 0.9;
        }

        ~BankAccount() {
            cout << "Account of Mr. " << holderName << " with account no " << accountNo 
                << " is destroyed with a balance BDT " << currentBalance << endl;
            objectCount--;
        }
};


int BankAccount::totalCreated = 0;
int BankAccount::objectCount = 0;

void display_stat() {
    cout << "Objects created: " << BankAccount::totalCreated << endl
        << "Current object count: " << BankAccount::objectCount << endl; 
}

BankAccount Larger(const BankAccount A, const BankAccount B) {
    if(A.getBalance() > B.getBalance()) {
        return A;
    } else {
        return B;
    }
}

int main() {
    BankAccount account1(1, "Mr. X", Savings, 100);
    account1.showInfo();
    account1.showBalance();
    account1.deposit(100);
    account1.showBalance();
    account1.withdrawal(50);
    account1.showBalance();
    account1.giveInterest();
    account1.showBalance();

    BankAccount account2(1, "Mr. Y", Savings, 200);
    account2.showInfo();
    account2.showBalance();
    account2.deposit(100);
    account2.showBalance();
    account2.withdrawal(50);
    account2.showBalance();
    account2.giveInterest();
    account2.showBalance();

    BankAccount larger = Larger(account1, account2);
    larger.showBalance();

    display_stat();
    return 0;
}