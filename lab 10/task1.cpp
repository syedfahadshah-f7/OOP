/*
Name: Raghib Rizwan Rabani
NU ID: 23K-0012
*/
#include<iostream>
using namespace std;

class Logo{
    friend class Platform;
    string log;
public:
    Logo(string log):log(log){}
};
class Platform{
public:
    void display(Logo &obj){
        cout<<obj.log<<endl;
    }
    void modifier(Logo &obj){
        obj.log = "doge coin";
    }

};
class Server{
    
};

int main(int argc, char const *argv[])
{
    Logo logo("Blue Bird");
    Platform plat;
    cout<<"Original: ";
    plat.display(logo);
    cout<<"After Modefied: ";
    plat.modifier(logo);
    plat.display(logo);
    return 0;
}
