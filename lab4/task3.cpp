#include<iostream>
using namespace std;
class Week_Days{
    string days[7];
    int current_days ;
    public:
    Week_Days(){}
    Week_Days(int crr_day){
        days[0] ="Saturday";
        days[1] = "Sunday";
        days[2] = "Monday";
        days[3] = "Tuesaday";
        days[4] = "Wednesday";
        days[5] = "Thursay";
        days[6] = "Friday";
        if(crr_day >6){
            current_days = crr_day/6;
        }
        current_days = crr_day;
    }
    void get_current_day(){
        cout<<"CURRENT DAY: "<< days[current_days]<< endl;
    }
    void get_next_day(){
        cout<<"NEXT DAY: "<< days[current_days+1]<< endl;
    }
    void get_previous_day(){
        cout<<"PREVIOUS DAY: "<< days[current_days-1]<< endl;
    }
    void getn_nth_day(int nth){
        if(current_days+nth > 6 ){
            nth = (current_days+nth)/6;
        }
        cout<<"NTH DAY: "<< days[current_days + nth]<< endl;
    }
};
int main(){
    Week_Days obj;
    obj = Week_Days(3);
    obj.get_next_day();
    obj.get_current_day();
    obj.get_previous_day();
    obj.getn_nth_day(10);
    return 0;
}
