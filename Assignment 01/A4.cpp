#include<iostream>
using namespace std;
class Roller_coaster{
    string name;
    int height,length,capacity,current_riders;
    float speed;
    bool ride_in_progress;
    public:
    
    // default constructor
    Roller_coaster(){
        name = "ROLLER-COST";
        height= 15;
        length = 2000;
        capacity = 20;
        ride_in_progress = 0;

    }
    // constructor with parameteriz
    Roller_coaster(int height, int capacity,int length, string name){
        this->name = name;
        this->height=height;
        this->length= length;
        if(capacity >3){
            if(capacity%2==0 || capacity%3==0){
            this->capacity=capacity;
            }else{
                this->capacity = capacity-1;
            }
        }else{
            this->capacity = 20;
        }      
    }
    // initializing setter
    void setter(int height, int capacity,int length, float speed){
        this->height=height;
        this->length= length;
        this-> speed = speed;
        if(capacity >3){
            if(capacity%2 || capacity%3){
            this->capacity=capacity;
        }else{
            this->capacity = capacity-1;
        }
        }else{
            this->capacity = 20;
        }      
    }
// getter
    void getter(){
        cout<<"NAME OF ROLLER COASTER: "<< name <<endl
        << "LENGTH : "<<length <<endl<<
        "HEIGHT : "<< height <<endl
        <<"CAPACITY : "<<capacity<<endl
        <<"CURRENT RIDER : "<<current_riders<<endl
        <<"SPEED : "<<speed <<endl 
        <<"RIDE IN PROGRESS : ";;
        if(!ride_in_progress){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }
// function to load the riders 
    int load_the_riders(int riders){
        if(!ride_in_progress){
            if(riders <= capacity){
                current_riders = riders;
                    return 0;
            }else{
                return riders - capacity;
            }
        }else{
            cout<<"RIDE IN PROGRESS "<<endl;
        }
    }
//function to start the ride
    int start_the_ride(int riders){
        if(!ride_in_progress){
            ride_in_progress =1;
            if( riders == capacity){              
                return 0;
            }else{
                return capacity-riders;
            }
        }else{
            return -1;
        }
    }
//function to stop the ride
    void stop_the_ride(){
        if(ride_in_progress){
            ride_in_progress =0;
        }
    }
 // function unload the function
   void unload_the_rider(){
        if(!ride_in_progress){
            current_riders=0;
        }
   } 
 // function accelerate roller coaster
    void accelerate_the_ride(){
        speed *= 2;
    }
 // function deaccelerate roller coaster
    void deaccelerate_the_ride(){
        speed /= 6;
    }   
};
int main(){
    Roller_coaster obj1,obj2;
    obj1 = Roller_coaster(50, 30, 100, "ZIG_ZAG");
    obj1.setter(50,30,100,200.1);
    obj1.load_the_riders(20);
    obj1.start_the_ride(20);
    obj1.stop_the_ride();
    obj1.unload_the_rider();
    obj1.accelerate_the_ride();
    obj1.deaccelerate_the_ride();
    obj1.getter();
    return 0;
}
