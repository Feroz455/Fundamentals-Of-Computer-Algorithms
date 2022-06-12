/*
Page 438
1) Devise an algorithm that accepts a number in decimal and produce the
equivalent number in binary.
*/
#include <iostream>
#include<stack>
using namespace std;
int main()
{
    int value = 0, r = 0;
    stack<int> bin;
    cout << "Enter decimal number\n";
    cin >> value;
    while (value)
    {
        r = value % 2;
        bin.push(r);
        value = value / 2;
    }
    while(!bin.empty())
    {
        cout << bin.top() << " ";
        bin.pop();
    }
    return 0;
}
/*
Enter decimal number
554
1 0 0 0 1 0 1 0 1 0 
*/