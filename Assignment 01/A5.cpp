#include <iostream>
using namespace std;

class User;
class BOGOCoupon;

class Restaurant {
    string name, location, menuList[3];
    float priceList[3];
    int validCouponCodesList[15];
    static int couponsRedeemedCount;
    
    public : 
    
        Restaurant(string rname, string loc) : name(rname), location(loc) {}
        
        static const int totalMenu=3;
        
        void setMenuAndPriceList(string m1, string m2, string m3, float p1, float p2, float p3) {
           menuList[0] =m1,menuList[1] =m2,menuList[2] =m3;
           priceList[0]=p1,priceList[1]=p2,priceList[2]=p3;
        }
        
        void displayMenu() {

            
            for(int i = 0; i < totalMenu; i++) {

                cout << "Menu " << i+1 << " : " << menuList[i] << endl;
            }
        }
        
        float generateBill() {
            return 1;
        }
        
        float applyDiscount() {
            return 1;
        }
};

class BOGOCoupon {
    string couponCode,  restaurantCode;
    float validFrom, validUntil;
   
    friend class User ;

    public: 
    BOGOCoupon(){};

 BOGOCoupon(string CC, float VF, float VU, string RC) : couponCode(CC) , validFrom(VF), validUntil(VU), restaurantCode(RC){}

        bool isValid(float time) {
            if(validFrom< time && time<validUntil){
                return 1;
            }else{
                return 0;
            }
        }
};

class User {
    string name,redeem_coupon_list[15];
    BOGOCoupon  couponsList[15];
    int age, mobileNumber;
    
    
    public : 
    User(){}
    User(string n,int a,int mN): name(n), age(a), mobileNumber(mN){}
     int counter =0;
        void accumulateCoupon() {
            string coupon_code,  restaurant_code;
            float valid_from, valid_until;

            cout<<"Enter restaurent code :";
            cin>>restaurant_code;
            cout<<"Enter Coupon code :";
            cin>>coupon_code;
            cout<<"Enter valid From :";
            cin>>valid_from;
            cout<<"Enter valid Until :";
            cin>>valid_until;
            couponsList[counter].restaurantCode  = restaurant_code;
            couponsList[counter].couponCode  = coupon_code;
            couponsList[counter].validFrom  = valid_from;
            couponsList[counter].validUntil  = valid_until;
            if(hasValidCoupon(couponsList[counter], coupon_code) && redeemCoupon(coupon_code)){
                
                cout<<"COUPON IS VALID  "<<endl;
                counter++;
            }
            
        }
        
        bool hasValidCoupon(BOGOCoupon &bg, string coupan) { 
            if(coupan[0] == bg.restaurantCode[0] && coupan[1] == bg.restaurantCode[1] ){
                return 1;
            }else{
                cout<<"RESTAURENT CODE AND COUPON CODE IS DIFERENT "<<endl;
                return 0;
            }
        }
        
        bool redeemCoupon(string redeemCoupon) {
            for(int i=0;i<counter;i++){
                if(redeemCoupon == redeem_coupon_list[i]) return 0;
            }
            redeem_coupon_list[counter] = redeemCoupon ;
            return 1;
        }
};

int main() {
    
    Restaurant r1("Food Haven", "City Center"), r2("Pixel Bites", "Cyber street");
    r1.setMenuAndPriceList("Sushi","Pad Thai","Mango Tango",150.0,200.5,235.8);
    r2.setMenuAndPriceList("Binary Burger", "Quantum", "Quinoa",500.0,780.0,900.5);


    cout<<"DISPLAYING MENU OF FOOD HAVEN "<< endl;
    r1.displayMenu();
    cout<<"DISPLAYING MENU OF PIXEL BITES "<< endl;
    r2.displayMenu();
    User u1,u2;

    u1= User("FAHAD", 18, 31639);
    u2= User("HAMMAD", 19, 28802);
    u1.accumulateCoupon();
    u2.accumulateCoupon();
    return 0;
}
