#include<iostream>
using namespace std;
class Square{
    float side_length;
    float area;
    

    public:
    Square(){}
    static float all_areas;
    Square(float side_length){
        this->side_length = side_length;
    }
    void Calculate_Area(){
        area = (side_length*side_length);
        all_areas += area;
    }
    void getter(){
        cout<<"AREA: "<< area<<endl;
        cout<<"SIDES: "<<side_length<<endl;
         cout<<"ALL AREA: "<< all_areas<<endl;
    }
};
float Square :: all_areas = 0.0;
int main(){
Square s1,s2,s3;
s1 = Square(8.0);
s1.Calculate_Area();
s1.getter();
s2 = Square(10.5);
s2.Calculate_Area();
s2.getter();
s3 = Square(20.6);
s3.Calculate_Area();
s3.getter();
return 0;
}
