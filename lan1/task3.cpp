#include <iostream>
using namespace std;

int main() {
    int target =14 ;
    int arr[]={6,9,2,5,3};
    
    for(int i=0;i<5;i++){
        for(int j=i+1;arr[j]+arr[i]<=target;j++){

            if(arr[i]+arr[j] == target){
                cout<<"("<<i<<","<<j<<")"<<endl;
                return 0;
            }
        }
    }
    cout<<"No pair found";
}
