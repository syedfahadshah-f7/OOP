#include<iostream>
using namespace std;
class Employee{
    protected:
    int emp_id;
    string emp_name;
    public:
    Employee(int id, string name): emp_id(id),emp_name(name){}
    virtual double calculate_pay()const{
        return 0;
    }
    virtual void display_details()const{
        cout<<"Id: "<<emp_id<<endl<<"Name: "<<emp_name<<endl;
    }
};
class Fulltime_Employee: public Employee{
    double month_salary;
    public:
    Fulltime_Employee(int id, string name, double salary): Employee(id,name), month_salary(salary){ }
    double calculate_pay()const{
        return month_salary;
    }
    void display_details()const{
        Employee :: display_details();
        cout<<"Salary"<<month_salary<<endl;
    }
};
class Parttime_Employee: public Employee{
    int no_hours_work;
    double hourly_wage;
    public:
    Parttime_Employee(int id, string name, double h_wage, int hour): Employee(id,name), hourly_wage(h_wage), no_hours_work(hour){ }
    double calculate_pay()const{
        return no_hours_work*hourly_wage;
    }
     void display_details()const{
        Employee :: display_details();
        cout<<"Salary"<<calculate_pay()<<endl;
    }
};
int main(){
    Fulltime_Employee FE(62,"Fahad",150000);
    Parttime_Employee PE(62,"Syed",150.45,90);
    FE.display_details();
    PE.display_details();
    Employee *emp;
    emp =&FE;
    cout<<"Displaying Pay of FullTime Employee: "<< emp->calculate_pay()<<endl;
    emp =&PE;
    cout<<"Displaying Pay of PartTime Employee: "<< emp->calculate_pay()<<endl;
    return 0;
}
