#include <iostream>
using namespace std;
int recursive_swap(int *num1, int *num2, int cnt = 3)
{
    if (cnt == 0)
    {
        return 0;
    }
    if (cnt == 2)
    {
        *num2 = *num1 ^ *num2;
        cnt--;
    }
    *num1 = *num1 ^ *num2;
    recursive_swap(num1, num2, cnt - 1);
}

int main()
{
    int num1, num2;
    cout << "Enter Number 1 and Number 2" << endl;
    cin >> num1 >> num2;

    cout << "Before swap number 1 = " << num1 << "and number 2 = " << num2 << endl;
    recursive_swap(&num1, &num2);
    cout << "After swap number 1 = " << num1 << "and number 2 = " << num2 << endl;
}
