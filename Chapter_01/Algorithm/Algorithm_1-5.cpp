/*
Page 15
Algorithm abc(a, b, c)
{
    return(a + b + c * c + (a + b - c) / (a + b) + 4.0);
}
*/
#include <iostream>
using namespace std;
int abc(int a, int b, int c)
{
    return (a + b + c * c + (a + b - c) / (a + b) + 4.0);
}
int main()                  
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << abc << "\n";
    return 0;
}
/*
output

12 1 54
1
*/