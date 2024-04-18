#include<iostream>
using namespace std;
class printclass;
 class perimeter{
    int length,breadth;
    public:
    perimeter(int l, int b): length(l), breadth(b){}
    friend class printclass;
    inline int find_perimeter()const{
        return 2*(length*breadth);
    }
 };
 class printclass{
    public:
     void display(perimeter &p){
        cout<<"Perimeter: "<<p.find_perimeter();
     }
};
int main(){
    perimeter p(8,9);
    printclass pr;
    pr.display(p);
}
