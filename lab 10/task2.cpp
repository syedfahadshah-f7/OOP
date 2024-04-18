#include<iostream>
using namespace std;
class Base{
    int a;
    public:
    Base(){}
    Base(int x): a(x){}
    Base operator--(){
        a = a*4;
        return a;
    }
    Base operator--(int ){
        return this->a /= 4;
    }
    void display(){
        cout<<"Value "<<a<< endl;
    }
};
int main(){
    Base obj1(9),res;
    res = --obj1;
    res.display();
    res = obj1--;
    res.display();
    return 0;
}
