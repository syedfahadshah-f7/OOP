/*programmer:Syed Fahad Faheem Shah
roll num: (23k-0062)
  date:2/26/2024
 */
#include<iostream>
using namespace std;

bool hasSubsetSum(int arr[], int size, int targetSum){
    static int i=0;
    if(i == size) return false;
    int sum =arr[i];
    for(int j=i+1;sum <= targetSum;j++){
        sum += arr[j];
        if(sum == targetSum) return true;
    }
    i++;
    return hasSubsetSum(arr,size,targetSum);
}
int main(){
    int size, target_sum;
    cout<<"Enter Size Of Array"<<endl;
    cin>>size;
    int arr[5]={6,9,2,5,7};
    cout<<"Enter Target Sum"<<endl;
    cin>>target_sum;

    if(hasSubsetSum(arr,size,target_sum) == 1){
        cout<<"Subset is present ";
        return 0;
    }else{
        cout<<"Subset is not present ";
        return 0;
    }
}
