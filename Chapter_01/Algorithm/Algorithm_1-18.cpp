/*
Page 52
Algorithm 1.18 Algorithm to time Algorithm 1.17
Algorithm TimeSearch()
{
    for j := 1 to 1000 do a[j] = j;
    for j := 1 to 10 do
    {
        n[j] := 10 * (j - 1);
        n[j+10] := 100 * j;
    }
    for j := 1 to 20 do
    {
        h = GetTime();
        k = SeqSearch(a,0,n[j]);
        h1 = GetTIme();
        t = h1 - h;
        write (n[j],t);
    }
}
*/
#include <bits/stdc++.h>
using namespace std;
int SeqSearch(int A[], int x, int n)
{
    int i = n;
    A[0] = x;
    while (A[i] != x)
    {
        i--;
    }
    return i;
}
int main()
{
    clock_t start, end;
    long double time_taken;
    int i, j, A[1000], n[1000];
    for (int i = 1; i <= 1000; i++)
    {
        A[i] = i;
    }
    for (int i = 1; i <= 10; i++)
    {
        n[i] = 10 * (i - 1);
        n[i + 10] = 100 * j;
    }
    for (int j = 1; j <= 10; j++)
    {
        start = clock();
        SeqSearch(A, 0, n[j]);
        end = clock();
        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << n[j] << " " << fixed << time_taken << setprecision(20) << " sec \n";
    }
}
/*
0 0.000000 sec 
10 0.00000 sec 
20 0.00000 sec 
30 0.00000 sec 
40 0.00000 sec 
50 0.00000 sec 
60 0.00000 sec 
70 0.00000 sec 
80 0.00000 sec 
90 0.00000 sec 
*/