/*
Page 581
Algorithm 12.2 Approximation algorithm to store programs

Algorithm PStore(l, n, L)
{
    //Assume that l[i] <= l[i+1], 1 <= i < n

    i = 1;
    for j = 1 to 2 do
    {
        sum = 0; // Ammount of dist j already assigned
        while((sum + l[i]) <= L)
        {
            cout << "Store program " << i  << " on dist " << j;
            sum = sum = l[i];
            i = i + 1;
            if(i > n)
            return;
        }
    }
}
*/
#include <iostream>
using namespace std;

void PStore(int l[], int n, int L)
{
    // Assume that l[i] <= l[i+1], 1 <= i < n

    int i = 1;
    for (int j = 1; j <= 2; j++)
    {
        int sum = 0; // Ammount of dist j already assigned
        while ((sum + l[i]) <= L)
        {
            cout << "Store program " << i << " on dist " << j << "\n";
            sum = sum + l[i];
            i = i + 1;
            if (i > n)
                return;
        }
    }
}
int main()
{
    int L = 10, n = 4, l[n + 1] = {0, 2, 4, 5, 6};
    PStore(l, n, L);
    return 0;
}
/*
Store program 1 on dist 1
Store program 2 on dist 1
Store program 3 on dist 2
*/