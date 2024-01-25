#include<iostream>
using namespace std;
int main(){
    int num_std;
    cout<<"Enter Number of student";
    cin>>num_std;
    int arr[num_std][3];
    for(int i=0;i<num_std;i++){
        cout<<"Enter Student"<<i+1<<"course"<<endl;
        for(int j=0;j<3;j++){
            cout<<"Enter Course"<<j+1<<endl;
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<num_std;i++){
        for(int j=0;j<3;j++){
            cout<<"Enter Course"<<j+1<<endl;
            cin>>arr[i][j];
        }
    }
    return 0;
}
