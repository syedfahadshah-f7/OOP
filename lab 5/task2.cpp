#include<iostream>
using namespace std;
class Loan_helper{
    float amount,amnt_of_month;
    int months;
    public:
    static const float interest_rate;
    Loan_helper(){}
    
    Loan_helper(float amount,int months){
        this->amount = amount;
        this->months = months;
    }
    void calculate(){
        amnt_of_month=(amount/months)+(amount/100*interest_rate);
        cout<<"YOU NEED TO PAY "<< amnt_of_month<<" EVERY MONTH "<<endl;
    }
};
const float Loan_helper :: interest_rate = 0.5;
int main(){
    Loan_helper obj1;
    obj1 = Loan_helper(100000,12);
    obj1.calculate();
    return 0;
}
