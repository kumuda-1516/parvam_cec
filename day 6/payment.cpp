#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Abstract base class
class Payment {
protected:
    double amount;
    string transactionId;

public:
    Payment(double amt, string id)
        : amount(amt), transactionId(id) {}

    virtual void process() = 0;          
    virtual string getType() const = 0;  

    virtual ~Payment() {}
};
class CreditCardPayment : public Payment {
private:
    string cardNumber;

public:
    CreditCardPayment(double amt, string id, string card)
        : Payment(amt, id), cardNumber(card) {}

    void process() override {
        cout << "Processing Credit Card payment of $" << amount << endl;
        cout << "Card ending in: "
             << cardNumber.substr(cardNumber.length() - 4) << endl;
        cout << "Transaction: "
             << transactionId << " - APPROVED" << endl;
    }

    string getType() const override {
        return "Credit Card";
    }
};
 class PayPalPayment : public Payment {
private: 
    string email;
public:
    PayPalPayment(double amt, string id, string e)
        : Payment(amt, id), email(e) {}

    void process() override {
        cout << "Processing PayPal payment of $" << amount << endl;
        cout << "PayPal account: " << email << endl;
        cout << "Transaction: " << transactionId << " - APPROVED" << endl;
    }

    string getType() const override {
        return "PayPal";
    }
 };
class Cryptopayment : public Payment {
private:
    string walletAddress;
public:
    Cryptopayment(double amt, string id, string wallet)
        : Payment(amt, id), walletAddress(wallet) {}

    void process() override {
        cout << "Processing Cryptocurrency payment of $" << amount << endl;
        cout << "Wallet address: " << walletAddress << endl;
        cout << "Transaction: " << transactionId << " - APPROVED" << endl;
    }

    string getType() const override {
        return "Cryptocurrency";
    }
};
int main() {
    vector<Payment*> payments;
    payments.push_back(new CreditCardPayment(100.0, "TXN12345", "1234-5678-9012-3456"));
    payments.push_back(new PayPalPayment(50.0, "TXN67890", "user@example.com"));
    payments.push_back(new Cryptopayment(25.0, "TXN11223", "1A2B3C4D5E6F7G8H9I0J"));

    for (Payment* payment : payments) {
       cout<<"\n---"<<payment->getType()<<" ---"<<endl;
        payment->process();
    }
    for (Payment* payment : payments) {
        delete payment;
    }

    return 0;
}