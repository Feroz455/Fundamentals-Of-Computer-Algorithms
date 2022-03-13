/*
Page 54
Algorithm 1.19 Timing Algorthm

Algorithm TimeSearch()
{
    //Repetitin factors
    r[21] := {0,200000,200000,100000,100000,100000,50000,50000,
    50000,50000,50000,50000,50000,50000,50000,50000,25000,25000,25000};
    for(int j = 1; to 1000 do a[j] := j;
    for j:= 1 to 10 do
    {
        n[j] := 10 * (j - 1);
        n[j+10] := 100 * j;
    }
    for j:= 1 to  20 do
    {
        h = GetTime();
        for i:=1 to r[j] do k := SeqSearch(a,0,n[j]);
        h1 = Gettime();
        t1 = h1 - h;
        t = t1;
        t := t /r[j];
        write(n[j],t1,t);
    }
}
*/
#include <iostream>
#include <ctime>
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
void TimeSearch()
{
    clock_t h, h1, t, t1;

    int a[10000], n[10000], k;
    double r[21] = {0, 200000, 200000, 100000, 100000, 100000, 50000, 50000, 50000, 50000, 50000, 50000, 50000, 50000, 50000, 50000, 25000, 25000, 25000};
    for (int j = 1; j < 1000; j++)
    {
        a[j] = j;
    }
    for (int j = 1; j <= 10; j++)
    {
        n[j] = 10 * (j - 1);
        n[j + 10] = 100 * j;
    }
    for (int j = 1; j <= 20; j++)
    {
        h = clock();
        for (int i = 1; i <= r[j]; i++)
        {
            k = SeqSearch(a, 0, n[j]);
        }
        h1 = clock();
        t1 = h1 - h;
        t = t1;
        t = t / r[j];
        cout << n[j] << " " << ((double)t1) / CLOCKS_PER_SEC << "sec  to " << ((double)t) / CLOCKS_PER_SEC << "sec\n ";
    }
}
int main()
{
    TimeSearch();
    return 0;
}
/*
output
 0 0.001sec  to 0sec
 10 0.006sec  to 0sec
 20 0.004sec  to 0sec
 30 0.008sec  to 0sec
 40 0.015sec  to 0sec
 50 0.009sec  to 0sec
 60 0.011sec  to 0sec
 70 0.014sec  to 0sec
 80 0.015sec  to 0sec
 90 0.015sec  to 0sec
 100 0.021sec  to 0sec
 200 0.035sec  to 0sec
 300 0.048sec  to 0sec
 400 0.063sec  to 0sec
 500 0.077sec  to 0sec
 600 0.049sec  to 0sec
 700 0.052sec  to 0sec
 800 0.082sec  to 0sec
 900 0sec  to -2.14748e+06sec
 1000 0sec  to -2.14748e+06sec
*/