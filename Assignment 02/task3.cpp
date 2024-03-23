#include<iostream>
#include<string>

using namespace std;

class DarazPersonData {
    string last_name, first_name, address, city, zip, phone;
public:
    // mutators
    void set_lastname(string ln) {
        this->last_name = ln;
    }
    void set_firstname(string fn) {
        this->first_name = fn;
    }
    void set_address(string addr) {
        this->address = addr;
    }
    void set_city(string cty) {
        this->city = cty;
    }
    void set_zip(string zp) {
        this->zip = zp;
    }
    void set_phone(string phn) {
        this->phone = phn;
    }
    //accessors
    string get_lastname() const {
        return last_name;
    }
    string get_firstname() const {
        return first_name;
    }
    string get_address() const {
        return address;
    }
    string get_city() const {
        return city;
    }
    string get_zip() const {
        return zip;
    }
    string get_phone() const {
        return phone;
    }
};

class DarazCustomerData : public DarazPersonData {
    int customer_number;
    int loyality_points;
public:
    //mutators
    void set_cust_num(int num) {
        if(num>0){
            this->customer_number = num;
        }else{
            cout<<"Inappropriate Customer numner"<<endl;
        }
        
    }
    void set_loyality_points(int lp) {
        if(lp>0){
            this->loyality_points = lp;
        }else{
            cout<<"Inappropriate loyality Points"<<endl;
        }
        
    }

    //accessors
    int get_cust_num() const {
        return customer_number;
    }
    int get_loyality_points() const {
        return loyality_points;
    }

    void add_loyality_points(int points) {
        loyality_points += points;
    }
};

class DarazLoyalityProgram : public DarazCustomerData {
public:
    void add_loyality_points(int purchase) {
        if (purchase >= 1000 && purchase < 2000) {
            DarazCustomerData::add_loyality_points(30);
        }
        else if (purchase >= 2000 && purchase < 3000) {
            DarazCustomerData::add_loyality_points(60);
        }
        else if (purchase >= 3000 && purchase < 4000) {
            DarazCustomerData::add_loyality_points(90);
        }
        else if (purchase >= 4000 && purchase < 5000) {
            DarazCustomerData::add_loyality_points(120);
        }
        else if (purchase >= 5000) {
            DarazCustomerData::add_loyality_points(150);
        }
    }

    void redeeme_loyality_points(const int purchase) {
        int lp = DarazCustomerData::get_loyality_points();
        if (lp > 50 && lp < 100) {
            cout << "Total Bill: " << purchase << " After Discount: " << (purchase / 100) * 10 + purchase << endl;
        }
        else if (lp >= 100 && lp < 150) {
            cout << "Total Bill: " << purchase << " After Discount: " << (purchase / 100) * 20 + purchase << endl;
        }
        else if (lp >= 150 && lp < 200) {
            cout << "Total Bill: " << purchase << " After Discount: " << (purchase / 100) * 30 + purchase << endl;
        }
        else if (lp >= 200 && lp < 500) {
            cout << "Total Bill: " << purchase << " After Discount: " << (purchase / 100) * 40 + purchase << endl;
        }
        else if (lp >= 500) {
            cout << "Total Bill: " << purchase << " After Discount: " << (purchase / 100) * 50 + purchase << endl;
        }
    }

    void display_total_loyality_points() {
        cout << "Total loyality Point of Customer: " << DarazCustomerData::get_loyality_points() << endl;
    }
};

int main() {
    DarazLoyalityProgram Customer;
    //setting all the details of Customer
    Customer.set_firstname("Fahad");
    Customer.set_lastname("Shah");
    Customer.set_address("R-51");
    Customer.set_city("Karachi");
    Customer.set_phone("03163928802");
    Customer.set_zip("4567");
    Customer.set_cust_num(62);
    Customer.set_loyality_points(130);
    //displaying information of Customer;
    cout << "First Name: " << Customer.get_firstname() << endl;
    cout << "Last Name: " << Customer.get_lastname() << endl;
    cout << "Address: " << Customer.get_address() << endl;
    cout << "City: " << Customer.get_city() << endl;
    cout << "Phone: " << Customer.get_phone() << endl;
    cout << "ZIP Code: " << Customer.get_zip() << endl;
    cout << "Customer Number: " << Customer.get_cust_num() << endl;
    cout << "Customer Loyalty Points:" << Customer.get_loyality_points() << endl;
    //applying Function
    Customer.add_loyality_points(5500);
    Customer.redeeme_loyality_points(5500);
    Customer.display_total_loyality_points();

    return 0;
}
