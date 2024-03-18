#include<iostream>
#include<vector>
using namespace std;

class menu_item{
    string food_name;
    float food_price;
    public:
    void set_food_name(string food_name){
        this->food_name = food_name;
    }
    void set_food_price(float food_price){
        this->food_price = food_price;
    }
    string get_food_name()const{
        return food_name;
    }
    float get_food_price()const{
        return food_price;
    }
};
class menu{
    public:
    vector<menu_item> items;
    void add(const menu_item& item){
        items.push_back(item);
    }
    void remove(const menu_item& item) {
        for (auto i = items.begin(); i != items.end(); i++) {
            if (i->get_food_name() == item.get_food_name() ) {
                items.erase(i);
                break; 
            }
        }
    }
    void display(){
        for(auto& item:items){
            cout<<"Name : "<<item.get_food_name();
            cout<<" Price : "<<item.get_food_price()<<endl;
        }
    }
};
class payments{
    double payment;
    public:
    void set_payment(double payment){
        this->payment = payment;
    }
    double get_payment()const{
        return payment;
    }
};
class order{
    menu* MENU;
    payments pay;
    double payment;
    public:
    void add(const menu_item& item){
        MENU->add(item);
    }
    void calculate_bill(){
        payment = 0.0;
        for(auto& item: MENU->items){
        payment += item.get_food_price();
        }
        pay.set_payment(payment);
    }

};
int main(){
    menu Menu;
    order Order;
    payments Payment
    return 0;
}
