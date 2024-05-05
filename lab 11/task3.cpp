#include<iostream>
using namespace std;
class Vehicle{
    protected:
    string make;
    string model;
    int speed;
    public:
    Vehicle(string make, string model,int speed):make(make), model(model), speed(speed){}

    virtual void accelerate() =0;
    virtual void brake() =0;
    virtual void calculateFuelEfficiency()=0;
    inline string getmake()const{return make;}
    inline string getmodel()const{return model;}

    inline int getspeed()const{return speed;}
};
class Car:public Vehicle{
    private:
    double fuelCapacity;
    public:
    Car(string make, string model, int speed,double fuel): fuelCapacity(fuel),Vehicle(make, model, speed){}

   void accelerate(){
        cout << "Car is accelerating" << endl;
    }
    void brake(){
        cout << "Brake has been applied for car" << endl;
    }
    void calculateFuelEfficiency(){
        cout << "Calculating fuel efficiency for car" << endl;
    }
};
class Truck : public Vehicle{
protected:
    double cargoCapacity;
public:
    Truck(string make, string model, int speed, double cargoCapacity) : Vehicle(make, model, speed), cargoCapacity(cargoCapacity) {}

    void accelerate(){
        cout << "Truck is accelerating" << endl;
    }
    void brake(){
        cout << "Brake has been applied for truck" << endl;
    }
    void calculateFuelEfficiency(){
        cout << "Calculating fuel efficiency for truck" << endl;
    }
};
int main(){
    Vehicle *v;
    Car c("Tesla","Y",300,33.5);
    v = &c;
    v->accelerate();
    v->brake();
    v->calculateFuelEfficiency();
    cout<<"Make: "<<v->getmake()<<endl;
    cout<<"Model: "<<v->getmodel()<<endl;
    cout<<"Speed: "<<v->getspeed()<<endl;
    cout<<"------------------Now calling functions for Truck-------------------"<<endl;
    Truck t("CyberTruck","Z100",200,6);
    v = &t;
    v->accelerate();
    v->brake();
    v->calculateFuelEfficiency();
    cout<<"Make: "<<v->getmake()<<endl;
    cout<<"Model: "<<v->getmodel()<<endl;
    cout<<"Speed: "<<v->getspeed()<<endl;
    return 0;
}
