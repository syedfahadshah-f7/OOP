#include<iostream>
using namespace std;
class smart_phone{
    string company;
    int model;
    float display,ram,rom,storage;
    public:
    void setter(string company,int model,float display, float ram, float rom, float storage){
        this->company = company;
        this->display = display;
        this->model = model;
        this->ram =ram;
        this->rom = rom;
        this->storage= storage;
    }
    void getter(){
        cout<<"Mobile company name: "<< company<<endl
        <<"Model number: "<< model<<endl
        <<"Storage: "<<storage<<endl
        <<"Display: "<<display<<endl
        <<"RAM: "<<ram<<endl
        <<"ROM: "<<rom<<endl<<endl;
    }
    void make_phone_call(){}
    void send_message(){}
    void connect_to_wifi(){}
    void browse_internet(){}
};
int main(){
    smart_phone iphone,vivo;
    iphone.setter("Apple",14,12.5,12.0,512.0,128);
    vivo.setter("VIVO",20,13.0,4.0,512.0,64);
    cout<<"DISPLAYING SPECS OF IPHONE: "<<endl;
    iphone.getter();
    cout<<"DISPLAYING SPECS OF VIVO: "<<endl;
    vivo.getter();
    return 0;
}
