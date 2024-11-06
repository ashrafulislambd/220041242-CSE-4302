#include <bits/stdc++.h>
using namespace std;

class Account {
    private:
        string accountNo, accountName;
        float balance;
    protected:
        string accountPrefix;
        static int nextAccount;
        int nextAccountNo() {
            return Account::nextAccount++;
        }
    public:
        Account() {
            accountNo = accountPrefix + " - " + to_string(nextAccountNo());
        }

        string getAccountNo() {
            return accountNo;
        }

        string getAccountName() {
            return accountName;
        }

        void setAccountName(string accountName) {
            this->accountName = accountName;
        }

        float getBalance() {
            return balance;
        }

        void setBalance(float balance) {
            if(balance < 0) {
                cout << "Balance cannot be negative" << endl;
                return;
            }
            this->balance = balance;
        }

        void description() {
            cout << "Simple Bank Account" << endl;
        }
};

int Account::nextAccount = 0;

class CurrentAccount : public Account {
    private:
        const static float serviceChage;
    public:
        CurrentAccount() : Account() {
            accountPrefix = "100";
        }

        void description() {
            cout << "Current Account" << endl;
        }
};

class InterestAccount : public Account {
    private:
        float interestRate;
        float monthlyDepositAmount;
    public:
        InterestAccount() : Account() {}
        float getInterestRate() {
            return interestRate;
        }

        void setInterestRate(float interestRate) {
            if(interestRate < 0) {
                cout << "Cannot be negative" << endl;
                return;
            }
            this->interestRate = interestRate;
        }

        float getMonthlyDepositAmount() {
            return monthlyDepositAmount;
        }

        void setMonthlyDepositAmount(float monthlyDepositAmount) {
            if(monthlyDepositAmount < 0) {
                cout << "Cannot be negative" << endl;
                return;
            }
            this->monthlyDepositAmount = monthlyDepositAmount;
        }

        void description() {
            cout << "Interest Base Bank Account" << endl;
        }
};

class SavingsAccount : public InterestAccount {
    public:
        SavingsAccount() : InterestAccount() {
            accountPrefix = "200";
        }

        void description() {
            cout << "Savings Account" << endl;
        }
};

class MonthlyDepositeScheme : public InterestAccount {
    private:
        float maximumInterest;
    public:
        MonthlyDepositeScheme() : InterestAccount() {
            accountPrefix = "300";
        }
        
        float getMaximumInterest() {
            return maximumInterest;
        }

        void setMaximumInterest(float maximumInterest) {
            if(maximumInterest < 0) {
                cout << "Cannot be negative" << endl;
                return;
            }
            this->maximumInterest = maximumInterest;
        }

        void description() {
            cout << "Monthly Deposit Scheme Account" << endl;
        }
};

class LoanAccount : public InterestAccount {
    public:
        LoanAccount() : InterestAccount() {
            accountPrefix = "900";
        }

        void description() {
            cout << "Loan Account" << endl;
        }
};

class TwoYearMDS : public MonthlyDepositeScheme {
public:
    void description() {
        cout << "Two year deposit scheme account" << endl;
    }
};

class FiveYearMDS : public MonthlyDepositeScheme {
public:
    void description() {
        cout << "Five year deposit scheme account" << endl;
    }
};

class InitialDepositMDS : public MonthlyDepositeScheme {
    private:
        float initialDepositAmount;
    public:
        float getInitialDepositAmount() {
            return initialDepositAmount;
        }

        void setInitialDepositAmount(float initialDepositAmount) {
            if(initialDepositAmount < 0) {
                cout << "Cannot be negative" << endl;
                return;
            }
            this->initialDepositAmount = initialDepositAmount;
        }

        void description() {
            cout << "Initial Monthly Deposit Scheme Account" << endl;
        }
};

int main() {
    Account account;
    account.setBalance(100);
    account.setAccountName("Mr. X");
    account.description();

    CurrentAccount currentAccount;
    currentAccount.setBalance(100);
    currentAccount.description();

    SavingsAccount savingsAccount;
    savingsAccount.setBalance(100);
    savingsAccount.setMonthlyDepositAmount(30);
    savingsAccount.setInterestRate(10);
    savingsAccount.description();

    MonthlyDepositeScheme mds;
    mds.setBalance(100);
    mds.setMonthlyDepositAmount(30);
    mds.setInterestRate(10);
    mds.description();

    LoanAccount la;
    la.setBalance(100);
    la.setMonthlyDepositAmount(30);
    la.setInterestRate(10);
    la.description();

    TwoYearMDS ty;
    ty.setMaximumInterest(100);
    ty.setBalance(100);
    ty.setMonthlyDepositAmount(30);
    ty.setInterestRate(10);
    ty.description();

    FiveYearMDS fy;
    fy.setMaximumInterest(100);
    fy.setBalance(100);
    fy.setMonthlyDepositAmount(30);
    fy.setInterestRate(10);
    fy.description();

    return 0;
}