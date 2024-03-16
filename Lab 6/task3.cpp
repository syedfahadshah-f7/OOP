#include<iostream>
#include<string>
using namespace std;
class appointment{
    static int total_appointment,total_earning;
    int appoint_num;
    float price,time;
    string deal;
    public:
    appointment(){}
    appointment(int appoint_num,float price,string deal, float time){
        this->appoint_num = appoint_num;
        this->price = price;
        this->deal = deal;
        this->time = time;
        total_appointment++;
        total_earning += price;
    }
    static int calculate_average(){
        return total_earning/total_appointment;
    }
};
int appointment :: total_appointment =0 ;
int appointment :: total_earning =0 ;

int main(){
    appointment obj1,obj2,obj3;
    obj1 = appointment(1,1290.50,"Hair style",2.00);
    obj2 = appointment(2,1000.50,"Hair cut",4.00);
    obj3 = appointment(3,1090.50,"Facial",6.30);
    cout<<"Average cost of all the appointment made: "<< obj1.calculate_average()<<endl;
    return 0;
}
