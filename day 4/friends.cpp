#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;
    string accountNumber;

public:
    BankAccount(string accNo, double bal)
        : accountNumber(accNo), balance(bal) {}

    // Declare an external function as a friend
    friend void displayAccountInfo(const BankAccount& acc);

    // Declare another class as friend
    friend class Auditor;
};

// Friend function
void displayAccountInfo(const BankAccount& acc) {
    cout << "Account: " << acc.accountNumber << endl;
    cout << "Balance: $" << acc.balance << endl;

    // Can access private members because it's a friend
}

class Auditor {
public:
    void audit(const BankAccount& acc) {
        cout << "AUDIT REPORT" << endl;
        cout << "Account: " << acc.accountNumber << endl;
        cout << "Verified Balance: $" << acc.balance << endl;
    }
};

int main() {
    BankAccount acc("ACC-1001", 50000);

    displayAccountInfo(acc); // Friend function

    cout << endl;

    Auditor auditor;
    auditor.audit(acc); // Friend class

    return 0;
}