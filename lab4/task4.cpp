#include <iostream>
using namespace std;

class Office {
    string location;
    int seating_capacity;
    string furniture[3];

public:

    Office(string loc = " ", int seats = 0, string f1 = " ", string f2 = " ", string f3 = " ")
        : location(loc), seating_capacity(seats), furniture{f1, f2, f3} {}

    void display(){
        cout<<"Location : "<< location<<endl<< "Total Seats : "<<seating_capacity<<endl
        <<"Furniture 1 : "<<furniture[0]<<endl<<"Furniture 2 : "<<furniture[1]<<endl
        <<"Furniture 3 : "<<furniture[2]<<endl<<endl;
    }
};

int main() {
    Office obj1; 
    Office obj2("Fast", 1500, "Desk", "sidetable", "sofa");
    Office obj3("Fast", 1500, "Desk");

    obj1.display();
    obj2.display();
    obj3.display();
    return 0;
}
