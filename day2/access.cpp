#include <iostream>
using namespace std;
class BankAccount {
  private:
    double balance;
    string accountNumber;
protected:
     string accountHolderName;
 public:
     BankAccount(string name,string accNo){
         accountHolderName = name;
         accountNumber = accNo;
         balance = 0.0;
     }
     void deposit(double amount){
         if(amount > 0){
             balance += amount;
             cout<<"Deposit $"<< amount<< endl;
             
         }
     }
     void showBalance(){
         cout<<"Balance: $"<<balance<<endl;
         
     }
};
class SavingAccount : public BankAccount{
    public:
    SavingAccount(string name,string aacNo)
    : BankAccount(name,aacNo){}
    
    void showHolder(){
        cout<<"Account holder:"<<accountHolderName<<endl;
        
    }
};

int main(){
    BankAccount acc("Arjun", "A1001");
    acc.deposit(1000);
    acc.showBalance();
    
    SavingAccount sav("Priya","S2001");
    sav.showHolder();
    return 0;
}