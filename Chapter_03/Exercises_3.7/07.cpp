/*
page 188
07.
Let S be a (not necessarily sorted) sequence of n keys
A key k in S is said to be an approximate median of S if | {k' belongs to S: k' < k}| >= n/4
and | {k' belongs to S: k' > k}| >= n/4.
Devise an O(n) time algorithm to find all the approximate median of S
*/

#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <chrono>
using namespace std::chrono;
using namespace std;

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
    Select1(array, size, size / 2);
    cout << "Midian -> " << array[size / 2] << "\n";

    return 0;
}
/*
57 83 24 47 20 1 28 85 17
28
*/