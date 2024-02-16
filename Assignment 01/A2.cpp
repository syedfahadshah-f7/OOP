#include <iostream>
using namespace std;

class Table {
    int totalSeats, occupiedSeats, freeSeats;
    bool clean;
    friend void occupy_table(Table tables[], int totalFriends);

    public : 
        Table() {
            totalSeats = 4, clean = true, occupiedSeats = 0, freeSeats = 4;
        }

        Table(int cap) {
            if(cap != 4 && cap != 8) {
                if(abs(cap-4) > abs(cap-8)) {
                    totalSeats = 8;
                } else {
                    totalSeats = 4;
                }
            }
            clean = true, occupiedSeats = 0;
        }

        void using_the_table(int totalFriends) {

            
            if(clean) {
                cout<<"TABLE IS USING   "<<endl;
                if(totalFriends <= 4) {
                    freeSeats = 4-totalFriends;
                    occupiedSeats = totalFriends;
                } else {
                    freeSeats = 8-totalFriends;
                    occupiedSeats = totalFriends;
                }
            } else {
                cout << "Table is not clean" << endl;
            }
        }

        void have_lunch() {
            cout<<"HAVING LUNCH  "<<endl;
            clean=false;
        }
        void leave_table(){
            cout<<"LEAVING THE TABLE   "<<endl;
            occupiedSeats = 0, freeSeats = totalSeats;
        }
        void clean_table() {
            if(!clean && !occupiedSeats) {
                cout << "TABLE CLEANED   " << endl;
                clean = true ;

            }
        }
};

void occupy_table(Table tables[], int totalFriends) {
    for(int i = 0; i < 5; i++) {
        if(tables[i].totalSeats >= totalFriends){
            
            cout << "Assigned table : " << i+1 << endl;
            tables[i].using_the_table(totalFriends);
        }
    }
}

void emptyTable(Table tables[], int tableNo) {
     tables[tableNo].clean_table();
     tables[tableNo].leave_table();
}

int main(){

    Table tables[5];
    tables[0] = tables[2] = tables[3] = Table(4);
    tables[1] = tables[4] = Table(8);
    cout<<"OCCUPY TABLE FUNCTION CALLED!!!! "<<endl;

    occupy_table(tables,4);
    occupy_table(tables, 6);

   
    tables[0].using_the_table(4);
    tables[0].have_lunch();
    tables[0].leave_table();
    tables[0].clean_table();

    cout<<"EMPTY TABLE CALLED !!!!"<<endl;
    emptyTable(tables, 1);

    return 0;
}
