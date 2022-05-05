/*
Page 153

3.In an infinite array, the first n cells contains integer in sorted order
and the rest of the cell are filled with infinitive. Present an algorithm that
takes x as input and finds the position of x in the array in Q(log n) times, You are not given the value of n
*/
#include <iostream>
#include <ctime>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;
#define INF 2147483647
int BinarySearch(int a[], int n, int x)
// Same specifiction as BinSearch except n > 0
{
    int low = 1;
    int high = n + 1, mid, count = 0;
    // high is one more than possible
    while (low < (high - 1))
    {
        count++;
        mid = floor((low + high)) / 2;
        if (x < a[mid])
        {
            high = mid;
        }
        // only one comparison in the loop
        else
            low = mid; // x >= a[mid];
    }
    cout << "Number of comprison\n " << count << "\n";
    if (x == a[low])
    {
        return low; // x is present
    }
    else
        return -1; // x is not present
}

int main()
{
    srand(time(0));
    int size = 2000;
    int arr[size], key = 0, random, succses = 0, unsuccses = 0, result;

    random = rand() % 2000;

    for (int i = 0; i < size; i++)
    {
        arr[i] = INF;
    }
    for (int i = 0; i < random; i++)
    {
        arr[i] = rand() % 2000;
    }

    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n);
    int xx = 10;
    while (xx)
    {
        key = rand() % 2000;
        result = BinarySearch(arr, size, key);
        if (result != -1)
            cout << "succses \n";
        else
            cout << " unsuccses\n";

        xx--;
    }

    return 0;
}
/*
Number of comprison
 11
 unsuccses
Number of comprison
 11
succses 
Number of comprison
 11
 unsuccses
Number of comprison
 11
 unsuccses
Number of comprison
 10
 unsuccses
Number of comprison
 11
 unsuccses
Number of comprison
 11
 unsuccses
Number of comprison
 11
succses
Number of comprison
 11
succses
Number of comprison
 11
succses
*/