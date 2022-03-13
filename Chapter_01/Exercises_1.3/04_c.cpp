/*
Page 59
4.
a) Introduce statements to inctement count at all appropriate points in algorithm 1.23

Algorithm D(x,n)
{
    i := 1;
    repeat
    {
        x[i] := x[i] + 2;
        i := i + 2;
    }until (i > n);
    i := 1;
    while(i<= floor(n/2))do
    {
        x[i] := x[i] + x[i+1];
        i := i+1;
    }
}
*/
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
int D(int x[], int n)
{

    int count = 0, i = 1;
    do
    {
        i = i + 2;
        count = count + 3;
    } while (i >= n);
    i = 1;
    while (i <= floor(n / 2))
    {
        i++;
        count = count + 3;
    }
    return count;
}

int main()
{
    srand(time(0));
    int n = 200;
    int x[n];
    for (int i = 1; i <= n; i++)
    {
        x[i] = rand() % 100;
    }
    cout << D(x, n) << "\n";
}
/*
303
*/