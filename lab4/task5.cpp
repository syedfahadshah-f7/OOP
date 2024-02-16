#include <iostream>
using namespace std;

class Office {
    string location;
    int seating_capacity;
    string* furniture;

public:

    Office(string loc = " ", int seats = 0, int size)
        : location(loc), seating_capacity(seats) {
            furniture = new string[size];
        }

    ~Office(){
        delete(furniture);
    }

};

int main() {
    Office *obj; 
   obj = new Office;
   
   Office("Fast", 1500,15);
   delete(obj);
  
    return 0;
}
