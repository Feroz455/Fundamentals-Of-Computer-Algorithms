/*
Page 58
3. Determine the frequency counts for all statements in the following two algorithm segments

a) for i:=1 to n do
    for j:=1 to i do
        for k:=1 to j do
            x := x+1;

b) i := 1;
    while(i <= n) do
    {
        x := x + 1;
        i := i +1;
    }
*/
#include <iostream>
#include <ctime>
using namespace std;
int main()
{
    srand(time(0));
    int i, j, k, x, n;
    i = j = k = x = n = 0;
    n = rand() % 100;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
        {
            for (k = 0; k <= j; k++)
            {
                x++;
            }
        }
    }
    cout << x << "\n";
    i = 1;
    x = 0;
    while (i <= n)
    {
        x++;
        i++;
    }
    cout << x << "\n";
}
/*
output
24752
51
*/