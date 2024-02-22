#include <iostream>
#include <vector>
using namespace std;


    class Solution {
public:
    bool areNumbersAscending(string str) {
    int arr[10], cnt = 0;
    for (int i = 0; i < str.size(); i++)
    {

        if (str[i] >= 48 && str[i] <= 57)
        {
            arr[cnt] = str[i] - 48;
            while (str[i + 1] >= 48 && str[i + 1] <= 57)
            {
                arr[cnt] = (arr[cnt] * 10) + (str[i + 1] - 48);
                i++;
            }
            cnt++;
        }
    }
    for (int i = 1; i < cnt; i++)
    {
        cout<<arr[i]<<endl;
        if(arr[i] < arr[i-1]) return false;
    }
    return true;
    

}
};
int main()
{
    Solution obj;
    cout << obj.areNumbersAscending("1 box has 3 blue 4 red 6 green and 12 yellow marbles") << "!!!";
    return 0;
}
