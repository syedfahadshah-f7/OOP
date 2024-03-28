#include<iostream>
using namespace std;
double pi = 3.142;
class Shape{
    public:
    void area(double radius)const{
        cout<<"Area Of Circle is: "<< pi*(radius)*(radius)<<endl;
    }
    void area(int length, int width)const{
        cout<<"Area Of Rectangle is: "<< length*width<<endl;
    }
    void area(double base, double height)const{
        cout<<"Area Of Triangle is: "<< (base*height)/2<<endl;
    }
    void perimeter(double radius)const{
        cout<<"Perimeter Of Circle is: "<< 2*pi*radius<<endl;
    }
    void perimeter(int length, int width)const{
        cout<<"Perimeter Of Rectangle is: "<< 2*(length+width)<<endl;
    }
    void perimeter(double side1, double side2,double side3)const{
        cout<<"Perimeter Of Triangle is: "<< side1+side2+side3<<endl;
    }
};
 int main(){
    Shape obj;
    // calling Circle Area and Perimeter 
    obj.area(4.5);
    obj.perimeter(4.5);
    // calling Rectangle Area and Perimeter 
    obj.area(10,15);
    obj.perimeter(10,15);
    // calling Triangle Area and Perimeter 
    obj.area(5.6,7.3);
    obj.perimeter(4.0,5.0,7.0);
    return 0;
 }
