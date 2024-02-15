#include<iostream>
using namespace std;
struct Register{
    int course_id;
    string coure_name;
};
struct Student : Register{
    int std_id;
    string f_name;
    string l_name;
    long int cell_no;
    string email;
};

int main(){
    Student arr[5];

    // to initializATION
    for(int i=0;i<5;i++){
        cout<< "Enter DATA OF STUDENT" << i+1 <<endl<<endl;
        cout<< "Enter Student  First Name"<<endl;
        cin>> arr[i].f_name;
        cout<< "Enter Student Last name"<< endl;
        cin>> arr[i].l_name;
        cout<< "Enter Cell Number"<<endl;
        cin>> arr[i].cell_no;
        cout<< "Enter Student Id"<<endl;
        cin>> arr[i].std_id;
        cout<< "Enter Email"<<endl;
        cin>> arr[i].email;
        cout<< "Enter Course Id"<< endl;
        cin>> arr[i].course_id;
        cout<< "Enter Course name";
        cin>> arr[i].coure_name;

    };
    // to display
    for(int i=0;i<5;i++){
        cout<<"DATA OF STUDENT "<<i+1<<endl<<endl;
        cout<< " Student  First Name: "<<arr[i].f_name<<endl;
        cout<< " Student Last name"<< arr[i].l_name<<endl;
        cout<< " Cell Number"<< arr[i].cell_no << endl;
        cout<< "Student Id"<< arr[i].std_id<<endl;
        cout<< " Email"<<arr[i].email<<endl;
        cout<< "Course Id"<< arr[i].course_id<< endl;
        cout<< " Course name"<<arr[i].coure_name<<endl;

    };
    return 0;
}
