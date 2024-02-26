#include <iostream>
#include <vector>
using namespace std;

class Bank_Acc{
    int ac_num;
    string ac_name;
    double balance;
    public:
    Bank_Acc(){}
     Bank_Acc(int ac_num, string ac_name, double balance){
        this->ac_name = ac_name;
        this->balance = balance;
        this->ac_num = ac_num;
     }

    void deposit(double amount ){
        balance += amount;
    }
    void withdraw(double amount ){
        if(amount <= balance){
             balance -= amount;
        }
       else{
        cout<<"IN sufficient BAlance: "<<endl;
       }
    }
    void display(){
        cout<<"ACCOUNT HOLDER  NAME: "<<ac_name<<endl;
        cout<<"ACCOUNT NUMBER : "<<ac_num<<endl;
        cout<<"ACCOUNT  BALANCE : "<<balance<<endl;
    }

};
int main(){
    Bank_Acc Accounts[3];

    Accounts[0] = Bank_Acc(0062, "FAHAD", 10000);
    Accounts[1] = Bank_Acc(0023, "UMAR", 10);
    Accounts[2] = Bank_Acc(0012, "RAGHIB", 10);

    for (int  i = 0; i < 3; i++)
    {
        Accounts[i].display();
        cout<<endl<<endl;
    }
   cout<<"depositing  money "<<endl;
    Accounts[0].deposit(5000);
    cout<<endl;
    Accounts[0].display();
    cout<<endl<<"with draWing money "<<endl;
    Accounts[0].withdraw(7000);
    cout<<endl;
    Accounts[0].display();
    cout<<endl;
    
    // with drwaing large amount
    Accounts[1].withdraw(20);

    return 0;
}
  
