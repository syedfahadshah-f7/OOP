/*programmer:Syed Fahad Faheem Shah
roll num: (23k-0062)
  date:2/26/2024
 */
#include<iostream>
using namespace std;

int LCM (int a,int b){
    static int maxi=max(a,b), mini=min(a,b), res=maxi;
    if (res % mini == 0) return res;
    res += maxi;
    return LCM(mini,maxi);
}
int GCD(int a, int b){
    static int mini = min(a,b), maxi=max(a,b);
    if(maxi % mini == 0) return mini;
    return GCD(mini,maxi);
}
int main (){
    cout<<"Enter Two Numbers "<<endl;
    int a,b;
    cin>>a>>b;
    cout<<"LCM :"<<LCM(a,b)<<endl;
    cout<<"GCD :"<<GCD(a,b)<<endl;
}
