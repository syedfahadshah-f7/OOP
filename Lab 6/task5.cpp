#include<iostream>
#include<vector>

using namespace std;
class Course{ 
    string course_code,course_name;
    int credit_hours;
    friend class Student;
};
class Student{ 
    string st_id,st_name;
    vector<Course> course;
    public:
    Student(string id,string name): st_id(id),st_name(name){}
    void enroll(Course& obj){
        course.push_back(obj);
    }
    void drop(Course& obj){
        for(int i=0;i< course.size(); i++){
            if(course[i].course_name == obj.course_name){
                course.erase(course.begin()+i);
            }
        }
    }
    int getTotalCreditHours(){
        int sum=0;
        for(int i=0;i< course.size(); i++){
                sum += course[i].credit_hours;
        }
        return sum;
    }
    void printEnrolledCourses(){
        for(int i=0;i< course.size(); i++){
                cout<<"Course Name: "<< course[i].course_name<<endl
                <<"Course Code: "<< course[i].course_code<<endl
                <<"Corse Credit Hours: "<< course[i].credit_hours<<endl<<endl;
        }
    }
};

int main(){
    return 0;
}
