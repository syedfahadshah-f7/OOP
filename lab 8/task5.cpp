#include <iostream>
using namespace std;
class Vehicle
{
    string make, model;
    int year;

public:
    Vehicle(string make, string model, int year) : make(make),
                                                   model(model), year(year) {}
    void display()
    {
        cout << "Make: " << make << endl
             << "Model: " << model << endl
             << "Year: " << year << endl;
    }
};
class Car : public Vehicle
{
    int num_doors;
    float fuel_efficiency;

public:
    Car(int num_doors, float fuel_efficiency, string make, string model, int year)
        : num_doors(num_doors), fuel_efficiency(fuel_efficiency),
          Vehicle(make, model, year) {}
    void display()
    {
        Vehicle::display();
        cout << "Number of Doors: " << num_doors << endl
             << "Fuel Efficiency: " << fuel_efficiency << endl;
    }
};
class ElectricCar : public Car
{
    float battery_life;

public:
    ElectricCar(float battery_life, int num_doors, float fuel_efficiency, string make, string model, int year)
        : Car(num_doors, fuel_efficiency, make, model, year)
    {
        this->battery_life = battery_life;
    }
    void display()
    {
        Car ::display();
        cout << "Battery life" << battery_life;
    }
};
int main()
{
    ElectricCar Tesla(55000.35, 4, 31.5, "TESLA MOTORS", "Y", 2023);
    Tesla.display();
    return 0;
}
