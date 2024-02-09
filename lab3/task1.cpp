#include<iostream>
using namespace std;

class boared_marker{
    string company,color;
    bool refillable,ink_status;
    public:
    void setter(string comp,string col,bool refill , bool ink){
        company = comp;
        color = col;
        refillable = refill;
        ink_status = ink;
    }
    void getter(){
        cout<<"---Boared Marker---- "<<endl<< "Color = "<< color<<endl<< "Company : "<< company<<endl<<" Refilable : "
        << refillable <<endl<<"Ink Status : "<< ink_status<<endl;
    }
    void check(){
        if( ink_status == 1){
            cout<<"You can write with boared marker"<<endl;
        }
        else{
            cout<<"You can not write with boared marker, because ink is empty"<<endl;
        }
    }
    void refilable(){
        if( refillable == 1){
            cout<<"Marker is refilable "<<endl;
        }
        else{
            cout<<"Marker is not refilable "<<endl;
        }
    }
};
int main(){
    boared_marker obj;
    obj.setter("Dollar","Black",true,false);
    obj.getter();
    obj.check();
    obj.refilable();
    return 0;
}
