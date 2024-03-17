#include<iostream>
using namespace std;
class Person{
    string name;
    int age;
    public:
    Person(string name, int age): name(name), age(age){}
    void display(){
        cout<<"Name: "<<name<<endl
            <<"Age "<<age<<endl;
    }
};
class Student:public Person{
    int std_id;
    float grade_level;
    public:
    Student(int std_id, float grade_level, string name, int age): std_id(std_id), grade_level(grade_level), Person(name,age){}
};
class Teacher: public Person{
    string subject;
    int Room_num;
    public:
    Teacher(string subject, int room, string name, int age ): subject(subject), Room_num(room), Person(name,age){}
}
class GraduateStudeny:public Student, public Teacher{
    public:
    GraduateStudeny(string subject, int room, int std_id, float grade_level, string name , int age): Teacher(subject,room,name,age),
    Student(std_id,grade_level, name, age){}
};
int main(){
    GraduateStudeny graduate("OOP",32,230062, 4.00,"Fahad",19);
    return 0;
}
