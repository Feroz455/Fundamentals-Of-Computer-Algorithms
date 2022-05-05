/*
page 153
1.
Run the recursive and iterative version of binary search and compare the times;
for appropriate size in n, have each algorithm find every element in the set.Then try all n + 1 possible
unsuccessful searches.
*/

#include <iostream>
#include <ctime>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;
int BinarySearch(int a[], int n, int x)
// Same specifiction as BinSearch except n > 0
{
    int low = 1;
    int high = n + 1, mid;
    // high is one more than possible
    while (low < (high - 1))
    {
        mid = floor((low + high)) / 2;
        if (x < a[mid])
        {
            high = mid;
        }
        // only one comparison in the loop
        else
            low = mid; // x >= a[mid];
    }
    if (x == a[low])
    {
        return low; // x is present
    }
    else
        return -1; // x is not present
}
int BinSrch(int a[], int i, int l, int x)
{
    if (l == i)
    // If small(P)
    {
        if (x = a[i])
        {
            // cout << "From 1 -> " << i << "\n";
            return i;
        }

        else
        {
            // cout << "From 2 -> " << i << "\n";
            return -1;
        }
    }
    else
    {
        // Reduce P into a smaller subproblem
        int mid = floor((i + l) / 2);
        if (x == a[mid])
        {
            // cout << "From 3 -> " << mid << "\n";
            return mid;
        }

        else if (x < a[mid])
        {
            // cout << "From 4 -> " << mid << "\n";
            return BinSrch(a, i, mid - 1, x);
        }

        else
        {
            // cout << "From 5 -> " << mid << "\n";
            return BinSrch(a, mid + 1, l, x);
        }
    }
}

int main()
{
    srand(time(0));
    int size = 20000;
    int arr[size], key = 0, count = 500, succses = 0, unsuccses = 0, result;
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 10000;
    }
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n);

    clock_t start = clock();
    while (count)
    {
        key = rand() % 10000;
        result = BinarySearch(arr, size, key);
        if (result != -1)
            succses++;
        else
            unsuccses++;
        count--;
    }
    clock_t stop = clock();

    double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
    cout << "Time elapsed in ms: " << setprecision(5) << double(elapsed) << "\n";
    count = 500;
    start = clock();
    while (count)
    {
        key = rand() % 10000;
        result = BinSrch(arr, 0, size, key);
        if (result != -1)
            succses++;
        else
            unsuccses++;
        count--;
    }
    stop = clock();
    elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
    cout << "Time elapsed in ms: " << setprecision(5) << double(elapsed) << "\n";
    return 0;
}
/*
*/
