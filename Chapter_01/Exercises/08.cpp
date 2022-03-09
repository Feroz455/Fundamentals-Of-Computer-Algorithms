/*
Ackermann's function A(m,n) is defined as follows
            n+1             if m = 0
A(m,n)  = { A(m-1, 1)       if n = 0}
            A(m-1, A(m,n-1)) otherwise

*/
#include <iostream>
using namespace std;
int A(int m, int n)
{
    if (m == 0)
    {
        return n + 1;
    }
    else if (n == 0)
    {
        A(m - 1, 1);
    }
    else
        A(m - 1, A(m, n - 1));
}
int main()
{
    int x, y;
    cin >> x >> y;
    cout << A(x, y);
    return 0;
}
/*
out
 2 1 
 5
*/