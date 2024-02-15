#include<iostream>
using namespace std;
class BOOK{
    string name,author;
    int isbn_num, total_pg_cnt,number_of_pages_read;
    public:
    BOOK(){
        total_pg_cnt = 1000;
        number_of_pages_read=0;
    }
    void setter( string n, string a,int i) {
        name= n , author= a  , isbn_num = i;
        }
    void show_book_info(){
        cout<<"BOOK NAME : "<<name<<endl << "AUTHOR NAME : "<< author<< endl
        <<"TOTAL PAGES : "<<total_pg_cnt<<endl << "PAGES READ : "<< number_of_pages_read<<endl
        <<"ISBN NUMBER : "<<isbn_num<<endl;
    }
    
};
int main(){
    BOOK b1;
    b1.setter("HOW TO C","FAHAD",2300);
    b1.show_book_info();  
    return 0;
}
