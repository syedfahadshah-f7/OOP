#include<iostream>
using namespace std;
class BOOK{
    string name,author;
    int isbn_num, total_pg_cnt,number_of_pages_read=0;
    public:
    BOOK(){}
    BOOK( string n, string a,int i, int t) : name(n), author(a) , isbn_num(i), total_pg_cnt(t) {}
    void pages_read(int read_pageas){
        number_of_pages_read += read_pageas;
        if(read_pageas == total_pg_cnt) {
            cout<<"FINISHED THE BOOK"<<endl;
        }else{
            cout<<"TOTAL PAGES READ:  "<<number_of_pages_read;
        }
    }
};
int main(){
    BOOK b1("HOW TO C","FAHAD",2300,200);
    b1.pages_read(50);
    return 0;
}
