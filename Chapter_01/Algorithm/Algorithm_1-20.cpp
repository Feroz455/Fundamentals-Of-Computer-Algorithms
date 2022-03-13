/*
page 54
Algorithm 1.20 Improper timing construct



to := 0;
for i := 1 to r[j] do
{
    h:=GetTime();
    k = SeqSearch9a,0,n[j]);
    h1 := GetTime();
    t := t + h1 - h;
}
t := t / r[j];
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
        t = 0;

        for (int i = 1; i <= r[j]; i++)
        {
            h = clock();
            k = SeqSearch(a, 0, n[j]);
            h1 = clock();
            t = t + h1 - h;
        }
        t = t / r[j];
        cout << n[j] << " " << ((double)t) / CLOCKS_PER_SEC << "sec \n ";
    }
}
int main()
{
    TimeSearch();
    return 0;
}
/*
output
 10 32.76sec  to 0sec
 20 32.76sec  to 0sec
 30 32.76sec  to 0sec
 40 32.76sec  to 0sec
 50 32.76sec  to 0sec
 60 32.76sec  to 0sec
 70 32.76sec  to 0sec
 80 32.76sec  to 0sec
 90 32.76sec  to 0sec
 100 32.76sec  to 0sec
 200 32.76sec  to 0sec
 300 32.76sec  to 0sec
 400 32.76sec  to 0sec
 500 32.76sec  to 0sec
 600 32.76sec  to 0sec
 700 32.76sec  to 0sec
 800 32.76sec  to 0sec
 900 32.76sec  to -2.14748e+06sec
 1000 32.76sec  to -2.14748e+06sec



 0 0sec   
 10 0sec 
 20 0sec 
 30 0sec 
 40 0sec 
 50 0sec 
 60 0sec 
 70 0sec 
 80 0sec 
 90 0sec 
 100 0sec 
 200 0sec 
 300 0sec 
 400 0sec 
 500 0sec 
 600 0sec 
 700 0sec 
 800 0sec 
 900 -2.14748e+06sec
 1000 -2.14748e+06sec
*/