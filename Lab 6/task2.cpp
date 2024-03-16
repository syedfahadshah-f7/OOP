#include<iostream>
using namespace std;

class BankAccount{
    private:
    int accountld;
    double balance;
    int *transationHistory;
    int numTransations;
    public:
    BankAccount(){}
    BankAccount(int accountld, double balance, int numTransations){
            this->accountld = accountld;
            this->balance = balance;
            this->numTransations = numTransations;
            transationHistory = new int[numTransations];
            for (int i = 0; i < numTransations; i++)
            {
                cout<<"Enter Transation History num # "<<i+1<<endl;
                cin>>transationHistory[i];
            }
            
    }
    BankAccount(BankAccount& obj){
        accountld = obj.accountld;
        balance = obj.balance;
        numTransations = obj.numTransations;
        transationHistory = new int[numTransations];
        for (int  i = 0; i < numTransations; i++)
        {
            transationHistory[i] = obj.transationHistory[i];
        }
    }

    void display(){
        cout<<"Account ID: "<< accountld<<endl<<" Balance: "<<balance<<endl;
        for (int i = 0; i < numTransations; i++)
        {
           cout<<"Transation History # "<<i+1<<" : "<<transationHistory[i]<<endl;
        }
    }
    void update(int new_transation){
         delete[] transationHistory;
         transationHistory = new int[new_transation];
         cout<<"Enter Details of new transation !!!"<<endl;
          for (int i = 0; i < numTransations; i++)
            {
                cout<<"Enter Transation History num # "<<i+1<<" :"<<endl;
                cin>>transationHistory[i];
            }
    }
           ~BankAccount(){
        delete[] transationHistory;
    }
};

int main(){
    BankAccount sir_talha(6666,1200000.45,2),fahad(sir_talha);
    cout<<"DISPLAYING SIR TALHA ACCOUNT: "<<endl<<endl;
    sir_talha.display();
    cout<<"DISPLAYING FAHAD ACCOUNT: "<<endl<<endl;
    fahad.display();
    cout<<"CALLING TRANSATION HISTORY: "<<endl<<endl;
    sir_talha.update(3);
    cout<<"After updating !!!!!"<<endl<<endl;
    cout<<"DISPLAYING SIR TALHA ACCOUNT: "<<endl<<endl;
    sir_talha.display();
    cout<<"DISPLAYING FAHAD ACCOUNT: "<<endl<<endl;
    fahad.display();
    return 0;
}
