/*
Page 69
Algorithm 1.27 Identifying the repeated array number

RepeatedElement(a,n)
//Finds the repeated element from a[1:n]
{
    while(true) do
    {
        i = Random() mod n+1;
        j := Random() mod n+1;
        // i and j are random numbers in the range [1,n];
        if((i != j) and (a[i] = a[j])) then return i;
    }
}
*/
#include <iostream>
#include <ctime>
using namespace std;
int RepeatedElement(int a[], int n)
{
    srand(time(0));
    int i, j;
    while (true)
    {
        i = rand() % n + 1;
        j = rand() % n + 1;
        if ((i != j) && (a[i] == a[j]))
        {
            cout << "index  " << j << " & " ;
            return i;
        }
    }
}
int main()
{
    srand(time(0));
    int n = 10, a[n];
    for (int i = 1; i <= n; i++)
    {
        a[i] = rand() % 5;
        cout << a[i] << " ";
    }
    cout << "\nRepeated Element -> " << RepeatedElement(a, n) << "\n";
    return 0;
}
/*
4 3 3 0 1 0 0 1 1 2 
Repeated Element -> index  9 & 5
*/