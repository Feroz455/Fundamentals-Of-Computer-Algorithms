/*
Page 76
The problem considered here is that of searching for an element x in an array a[i:n]. Algoriithm 1.17
gives a deterministic @(n) time alorithm for this problem. Show that any deeterministic algorithm will
have to take Omega(n) time in the worse case for this problem. IN contrast a randomized las Vegas Algorithm
that searched for x is given in Algorithm 1.32. This algortihm assumes that x is in a[]. What is the
~Big-oh(n) run time of this algorithm.


Algorithm 1.32 Randomzed search

Alorithm RSearch(a,x,n)
//Search for x in a[1:n]. Assume that x is in a[].
{
    while(true)
    {
        i:=Random() mode n+1;
        //i is random in the range [1,n];
        if(a[i] == x) then return i;
    }
}
*/
#include <iostream>
#include <ctime>
using namespace std;
int RSearch(int a[], int x, int n)
{
    srand(time(0));
    int i;
    while (true)
    {
        i = rand() % (n + 1);
        if (a[i] == x)
            return i;
    }
}
int main()
{
    srand(time(0));
    int n = rand() % 100;
    int a[n];
    for (int i = 1; i <= n; i++)
    {
        a[i] = rand() % 20;
        cout << a[i] << " ";
    }
    int temp = rand() % 20;
    cout << "\n"
         << temp << "\n";
    cout << "Found at -> " << RSearch(a, temp, n);
    return 0;
}
/*
2 18 16 13 17 12 11 10 3 12 8 2 14 16 0 8 3 10 9 1 16 10 10 0 15 14 4 11 13 11 4 2 18 18 19 8 0 7 6 0 1 16 12 6 19 17 16 19 14 19 15 11 13 19 5 8 13 4 3 9 8 7 9 13 11 6 13 10 9 6 0 5 11 6 7 10 8 1 17 19 15 15 11 14 8 19 12 0 0 3 1 12 9 13 16 0 
9
Found at -> 63
*/