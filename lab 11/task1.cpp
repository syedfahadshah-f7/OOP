#include<iostream>
using namespace std;
class convert{
    protected:
    float value1,value2;
    public:
    convert(float val1,float val2): value1(val1), value2(val2){}
    virtual void compute() =0;
    void set_value2(float val){
        this->value2 = val;
    }
};
class l_to_g: public convert{
    public:
    l_to_g(float val1): convert(val1,0){}
    void compute(){
        set_value2(value1*1000);
        cout<<"The value in grams is "<<value2<<endl;
    }
};
class f_to_c: public convert{
    public:
    f_to_c(float val1): convert(val1,0){}
    void compute(){
        set_value2((value1-32)*5/9);
        cout<<"The value in celsius is "<<value2<<endl;
    }
    
};
int main(){
    convert *convert;
    l_to_g l(4);
    f_to_c f(70);
    convert = &l;
    convert->compute();
    convert = &f;
    convert->compute();
    return 0;
}
