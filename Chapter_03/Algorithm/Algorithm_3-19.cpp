/*
page 184
Algorithm 3.19 Selection pesdocode using the median of medians rule

//Fiind the k-th smallest in a[low:up]
Algorithm Selct2(a,k,low,up)
{
    n = up - low;
    if(n <= r)
    {
        sort a[low:up] and return the k-th elements;
        Divide a[low:up] into n/r subsets of size each;
        ignore excess elements;

        let m[i], 1 <= i <= n/r); be the set of medians of the above n/r subsets;
        v = selsect2(m,ceil(n/r)/2), 1, n/r);
        Psrtition a[low:up] using as the partition elemets;
        Assume that v is at position j;

        if(k == (j - low + 1))
        return v;
        else if(k < (j - low + 1))
        return Select2(a, k, low, j-1);
        else retrun Select2(a,k-(j-low+1), j + 1, up);

    }
}
*/
#include <iostream>
#include <ctime>
#define INF 2147483647
using namespace std;
int partition(int a[], int l, int u)
{
    int v, i, j, temp;
    v = a[l];
    i = l;
    j = u + 1;

    do
    {
        do
            i++;
        while (a[i] <= v && i <= u);

        do
            j--;
        while (v < a[j]);

        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);

    a[l] = a[j];
    a[j] = v;
    return (j);
}
void Select1(int a[], int n, int k)
{
    int low = 1, j;
    int up = n + 1;
    a[n + 1] = INF; // a[n+1] is set to infinity
    do
    {
        // Each time the loop is entered
        // 1 <= low <= k <= up <= n+1
        j = partition(a, low, up);
        // j is such that a[j] is the jth-smallest value in a[]

        if (k == j)
            return;
        else if (k < j)
            up = j; // j is the new upper limit
        else
            low = j + 1; // j+1 is the new lower limit
    } while (true);      // Until its become false
}
int Select2(int a[], int k, int low, int up)
{
    int n = up - low;
    int r = 10, j, v;
    if (n <= r)
    {
        j = partition(a, low, up);
        if (k == (j - low + 1))
            return v;
        else if (k < (j - low + 1))
            return Select2(a, k, low, j - 1);
        else
            return Select2(a, k - (j - low + 1), j + 1, up);
    }
}

void PrintArray(int array[], int low, int high)
{
    for (int i = low; i < high; i++)
    {
        cout << array[i] << " ";
    }
    cout << "\n";
}
int main()
{
    srand(time(0));
    int size = 10, key;
    int array[100];
    for (int i = 1; i < size; i++)
    {
        array[i] = rand() % 100;
    }
    PrintArray(array, 1, size);
    // Select1(array, size, 5);
    for (int i = 1; i < size; i++)
        Select2(array, i, 1, size);
    PrintArray(array, 1, size);

    return 0;
}
/*
88 73 44 66 3 12 83 33 32 
3 12 32 33 44 66 73 83 88
*/