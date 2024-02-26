/*programmer:Syed Fahad Faheem Shah
roll num: (23k-0062)
  date:2/26/2024
 */
#include<iostream>
using namespace std;
int main(){
    int num;
    if(num<0){
        cout<<"enter correct value";
    }
    cout<<"Enter Value to check prime";
    cin>> num;

   for(int i=2;i<num/2;i++){
        if(num%i == 0){
            cout<<"Is prime";
            return 0;
        }
   }
   cout<<"not prime";
}
