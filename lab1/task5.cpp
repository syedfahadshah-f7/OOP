/*programmer:Syed Fahad Faheem Shah
roll num: (23k-0062)
  date:2/26/2024
 */
#include <iostream>
#include <string>
using namespace std;

int main() {
    int rows;
    cout<<"Enter number of events: "<<endl;
    cin>>rows;
    string **arr;
    arr = new string*[rows];
    for(int i=0;i<rows;i++){
        arr[i] = new string[4];
    }
    for(int i=0;i<rows;i++){
            cout<<"Enter Event name N0: "<<i+1<<endl;
            cin>>arr[i][0];
            cout<<"Enter Date:"<<endl;
            cin>>arr[i][1];
            cout<<"Enter Venue: "<<endl;
            cin>>arr[i][2];
            cout<<"Enter Organizer"<<endl;
            cin>>arr[i][3];
    }
    string search_date;
    cout<<"Enter Specific Date to search event: "<<endl;
    cin>> search_date;
    for(int i=0;i<rows;i++){
        if(search_date == arr[i][1]){
            cout<<"Event name: "<<arr[i][0]<<endl;
            cout<<"Date:"<<arr[i][1]<<endl;
            cout<<"Venue: "<<arr[i][2]<<endl;
            cout<<"Organizer:"<<arr[i][3]<<endl;

        }
    }
    return 0;
}
