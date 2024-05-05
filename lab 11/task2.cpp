#include<iostream>
using  namespace std;
class Account{
    protected:
    int acc_no;
    double balance;
    public:
    Account(int ac, double bal): acc_no(ac), balance(bal){}
    virtual void deposit(double amount) =0;
    virtual void withdraw(double amount) =0;

    virtual void calculateInterest() =0;
    int get_ac_num(){
        return acc_no;
    }
    double get_balance(){
        return balance;
    }
};
class SavingAccounts: public Account{
    private:
    double interestRate;
    public:
    SavingAccounts(int ac, double bal, double rate): Account(ac, bal), interestRate(rate){}
    void deposit(double amount){
        balance += amount;
    }
    void withdraw(double amount){
       if(amount < balance){
            balance -= amount;
        }
        else{
            cout<<"Sorry Insufficient Balance!"<<endl;
        }
    }
    void calculateInterest(){
        balance += balance*interestRate;
    }
};
class CurrentAccounts: public Account{
    private:
    double overDraftLimit;
    public:
    CurrentAccounts(int ac, double bal, double rate): Account(ac, bal), overDraftLimit(rate){}
    void deposit(double amount){
        balance += amount;
    }
    void withdraw(double amount){
        if (balance - amount >= overDraftLimit) {
            balance -= amount;
            
        } else {
            cout << "Withdrawal amount exceeds overdraft limit!" << endl;
            
        }
    }
    void calculateInterest(){    
    }
};
int main(){
    Account *account;
    SavingAccounts savingAccount(100, 3000, 0.09);
    account = &savingAccount;
    account->deposit(1000);
    account->withdraw(500);
    account->calculateInterest();
    cout<<"Acoount No: "<<account->get_ac_num()<<endl;
    cout<<"Balance: "<<account->get_balance()<<endl;
    CurrentAccounts currentAccount(101, 4000, 1000);
    account = &currentAccount;
    account->deposit(1000);
    account->withdraw(500);
    cout<<"Acoount No: "<<account->get_ac_num()<<endl;
    cout<<"Balance: "<<account->get_balance()<<endl;
    return 0;
}
