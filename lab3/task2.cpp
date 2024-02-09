#include <iostream>
using namespace std;
class water_bottle{
    string company, colour;
    float water_capacity;
    public:
    void setter(string comp, string col, float cap){
        company = comp;
        colour = col;
        water_capacity = cap;
    }
    void getter(){
        cout<<"Water bottle company name:  "<< company<<endl<< "Colour "<< colour <<endl<<"Capacity"<< water_capacity<<endl;
    }
    void update(float update){
        water_capacity += update/1000;
    }
};
int main(){
    water_bottle obj;
    obj.setter("nestle","red",5.5);
    obj.getter();
    cout<<"-----After amount of water consumed ---- "<<endl;
    obj.update(2000.0);
    obj.getter();
    return 0;
}
