#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Payment {
    protected:
        double amount;
        string transactionId;
    
    public:
        Payment(double amt, string id) : amount(amt), transactionId(id) {}
        
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
            cout << "Card ending in: " << cardNumber.substr(cardNumber.length() - 4) << endl;
            cout << "Transaction: " << transactionId << " — APPROVED" << endl;
        }
        
        string getType() const override {
            return "Credit Card";
        }
};