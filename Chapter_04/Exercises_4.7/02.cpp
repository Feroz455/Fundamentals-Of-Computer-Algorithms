#include <bits/stdc++.h>
using namespace std;
void Store(int n, int m)
{
    int j = 0;
    for (int i = 1; i <= n; i++)
    {
        cout << "Append program " << i << " to permutaion for tape " << j << "\n";
        j = (j + 1) % m;
    }
}
int main()
{
    int n = 13, m = 3;
    Store(n, m);
    return 0;
}
/*
Append program 0 to permutaion for tape 0
Append program 1 to permutaion for tape 1
Append program 2 to permutaion for tape 2
Append program 3 to permutaion for tape 0
Append program 4 to permutaion for tape 1
Append program 5 to permutaion for tape 2
Append program 6 to permutaion for tape 0
Append program 7 to permutaion for tape 1
Append program 8 to permutaion for tape 2
Append program 9 to permutaion for tape 0
Append program 10 to permutaion for tape 1
Append program 11 to permutaion for tape 2
Append program 12 to permutaion for tape 0
*/