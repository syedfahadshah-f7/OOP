#include<iostream>
#include<string>
using namespace std;
class calender{
    string months[12][30];
    string months_name[12]={"january","feburuary","march","april","may","june","july","august","september","october","november","december"};

    public:

    void addition_of_task(int date, string month){
        string task;
        cout<<"Enter Task"<<endl;
        std :: getline(cin,task);
        int month_number;
        for(int i=0;i<12;i++){
            if(months_name[i]== month){
                month_number = i;
            }
        }       
            months[month_number][date-1] = task;
    }
      void removal_of_task(int date, string month){
        
        int month_number;
        for(int i=0;i<12;i++){
            if(months_name[i]== month){
                month_number = i;
                break;
            }
        }
            months[month_number][date-1] = " ";
    }
    void display(){
        for(int i=0;i<12;i++){
            for(int j=0;j<30;j++){
                cout<<"Task on "<<i+1 <<"/"<<j+1<<"/2024 "<< months[i][j]<<endl;
            }
        }
    }
};
int main(){
calender obj;
obj.addition_of_task(14,"may");
obj.removal_of_task(14,"may");
obj.display();
}
