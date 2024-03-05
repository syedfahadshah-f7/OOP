#include<iostream>
using namespace std;
class engine{
    int hp;
    public:
    engine(){}
    engine(int hp){
        this->hp = hp;
    }
    int getter(){
        return hp;
    }
};
class wheels{
    wheels(){}
    int size;
    public:
    wheels(int size){
        this->size = size;
    }
    int getter(){
        return size;
    }
};
class headlights{
    string brand;
    public:
    headlights(){}
    headlights(string brand){
        this->brand = brand;
    }
    string getter(){
        return brand;
    }
};
class steering{
    string material;
    public:
    steering(){}
    steering(string material){
        this->material= material;
    }
    string getter(){
        return material;
    }
};
class car{
    engine eg;
    wheels* w;
    headlights* h1;
    steering s;
    public:
    car(){ }
    car( wheels* w, headlights* h1){
        eg = engine(150);
        s = steering("Leather");
        this->eg = eg;
        this->h1 = h1;
        this->w = w;
        this->s = s;
    }
    void display(){
        cout<<"Engine HP: "<<eg.getter()<<endl;
        cout<<"Steering Material: "<< s.getter()<<endl;
        cout<< "Wheels Size: "<<w->getter()<<endl;
         cout<< "Headlights Brand: "<<h1->getter()<<endl;

    }
};
int main(){
   // engine e(150);
    wheels* w = new wheels(18);
    headlights* h= new headlights("ABC");
   // steering s("Leather");
    car c;
    c = car(w,h);
    c.display();
    return 0;
}
