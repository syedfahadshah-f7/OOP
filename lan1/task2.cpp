#include<iostream>
using namespace std;
int average(int sum){
    return sum/3;
}
char grade(int aver){
    if(aver >= 90) return 'A';
    else if(aver>=80 && aver<=89) return 'B';
    else if(aver>=70 && aver<=79) return 'C';
    else if(aver>=60 && aver<=69) return 'D';
    else return 'F';
}
int main(){
    int num_std;
    cout<<"Enter Number of student: ";
    cin>>num_std;
    int arr[num_std][3];
    for(int i=0;i<num_std;i++){
        cout<<"Enter Student "<<i+1<<" course marks: "<<endl;
        for(int j=0;j<3;j++){
            cout<<"Enter Course "<<j+1<<" marks"<<endl;
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<num_std;i++){
        int total_marks=0;
        for(int j=0;j<3;j++){
            total_marks += arr[i][j];
        }
        cout<<"Total marks of student "<<i+1<<"is "<<total_marks<<endl;
        cout<<"Average of student "<< i+1<<"is "<<average(total_marks)<<endl;
        cout<<"Grade of student "<< i+1<<"is "<<grade(average(total_marks))<<endl;
        
    }
    return 0;
}
