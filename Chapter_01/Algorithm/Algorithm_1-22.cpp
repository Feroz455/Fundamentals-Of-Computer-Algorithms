/*
page 55
Algorithm 1.22 Another improper timing cnstruct

h := GetTime();
t := 0;
while(t < DESIRED_TIME) do
{

    k := SeqSearch(a,0,n[j]);
    h1 := GetTime();
    t :=  h1 - h;
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
        t = 0;
        h = clock();
        while (t < 1500)
        {

            k = SeqSearch(a, 0, n[j]);
            h1 = clock();
            t = h1 - h;
        }
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
0 0.008sec  to 0sec
 10 0.008sec  to 0sec
 20 0.008sec  to 0sec
 30 0.008sec  to 0sec
 40 0.008sec  to 0sec
 50 0.008sec  to 0sec
 60 0.008sec  to 0sec
 70 0.008sec  to 0sec
 80 0.008sec  to 0sec
 90 0.008sec  to 0sec
 100 0.008sec  to 0sec
 200 0.008sec  to 0sec
 300 0.008sec  to 0sec
 400 0.008sec  to 0sec
 500 0.008sec  to 0sec
 600 0.008sec  to 0sec
 700 0.008sec  to 0sec
 800 0.008sec  to 0sec
 900 0.008sec  to -2.14748e+06sec
 1000 0.008sec  to -2.14748e+06sec
*/
