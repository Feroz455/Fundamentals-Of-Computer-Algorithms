/*
 */
#include <iostream>
#include <cmath>
#include <ctime>
#include <queue>
#include<iomanip>
#define INF 2147483647
using namespace std;
int r = 5;
void InsertionSort(int a[], int low, int high)
{
    int item = 0, i;
    for (int j = low; j < high; j++)
    {
        // a[1:j-1] is already sorted
        item = a[j];
        i = j - 1;
        while ((i >= low) && (item < a[i]))
        {
            a[i + 1] = a[i];
            i = i - 1;
        }
        a[i + 1] = item;
    }
}
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
void Select3(int a[], int n, int k)
{
    int q, min, max, temp;
    if (k <= floor(n / 2))
        for (int i = 1; i <= k; i++)
        {
            q = i;
            min = a[i];

            for (int j = i + 1; j <= n; j++)
            {
                if (a[j] < min)
                {
                    q = j;
                    min = a[j];
                }
            }
            temp = a[q];
            a[q] = a[i];
            a[i] = temp;
            // interchange(a, q, i);
        }
    else
    {
        for (int i = n; i >= k; i--)
        {
            q = i;
            max = a[i];
            for (int j = (i - 1); j >= 1; j--)
            {
                if (a[j] > max)
                {
                    q = j;
                    max = a[j];
                }
            }
            temp = a[q];
            a[q] = a[i];
            a[i] = temp;
        }
    }
}
int select2(int a[], int k, int low, int up)
{
    int n, temp, x, y, j;
    do
    {
        n = up - low + 1; // Number of elements;
        if (n <= r)
        {
            InsertionSort(a, low, up);
            return low + k - 1;
        }
        for (int i = 1; i <= (n / r); i++)
        {
            InsertionSort(a, low + (i - 1) * r, low + i * r - 1);
            // Collect medians in the front part of a[low:up];
            x = low + i - 1;
            y = low + (i - 1) * r + ceil(r / 2) - 1;
            temp = a[x];
            a[x] = a[y];
            a[y] = temp;
        }
        j = select2(a, ceil(floor(n / r) / 2), low, low + floor(n / r) - 1); // mm
        temp = a[low];
        a[low] = a[j];
        a[j] = temp;

        j = partition(a, low, up + 1);
        if (k == (j - low + 1))
            return j;
        else if (k < (j - low + 1))
            up = j - 1;
        else
        {
            k = k - (j - low + 1);
            low = j + 1;
        }
    } while (true);
}
void select4(int array[], int size)
{
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i < size; i++)
    {
        q.push(array[i]);
    }
    for (int i = 1; i < size; i++)
    {
        array[i] = q.top();
        q.pop();
    }
}
void PrintArray(int array[], int size)
{
    for (int i = 1; i < size; i++)
    {
        cout << setw(3) << array[i] << " ";
    }
    cout << "\n";
}
int main()
{
    srand(time(0));
    int size = 10;
    int array[size];
    for (int i = 1; i < size; i++)
        array[i] = rand() % 50;
    PrintArray(array, size);
    for (int i = 1; i < size; i++)
        Select3(array, size - 1, i);
    PrintArray(array, size);
}
/*
Select3 will be fastest both on the average and in the wrost case for samll
values on n. It will also be fastest for large n and very samll or very large k, 
for example k = 1, 2 ,n or n - 1

for larger values of n Select1 will have the best behavior on the average
*/