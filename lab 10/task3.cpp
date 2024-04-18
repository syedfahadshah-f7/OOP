#include<iostream>
using namespace std;
class shape{
     int width, height, area;
     public:
     shape(){}
     shape(int x, int y): width(x), height(y){}
     void find_area(){
        area = height*width;
     }
     int operator+(shape &obj2){
        return this->area + obj2.area;
     }
};
int main(){
    shape s1(4,4),s2(5,5);
    s1.find_area();
    s2.find_area();
    cout<< s1+s2;
    return 0;
}
