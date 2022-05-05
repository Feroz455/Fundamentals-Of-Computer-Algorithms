/*
Page 153
Devise a ternary search algorithm that first test the element at position
n/3 for equality with some value x, and then checks the element at 2n/3 and either discovers x
or resuce the set size to one-third the size of the original. Compare this with binary search
*/
#include <iostream>
#include <ctime>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;
#define INF 2147483647
// Function to perform Ternary Search
int ternarySearch(int l, int r, int key, int ar[])
{
    if (r >= l)
    {

        // Find the mid1 and mid2
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
        cout << "mid1 -> " << mid1 << "\n";
        cout << "mid2 -> " << mid2 << "\n";

        // Check if key is present at any mid
        if (ar[mid1] == key)
        {
            return mid1;
        }
        if (ar[mid2] == key)
        {
            return mid2;
        }

        // Since key is not present at mid,
        // check in which region it is present
        // then repeat the Search operation
        // in that region
        if (key < ar[mid1])
        {

            // The key lies in between l and mid1
            return ternarySearch(l, mid1 - 1, key, ar);
        }
        else if (key > ar[mid2])
        {

            // The key lies in between mid2 and r
            return ternarySearch(mid2 + 1, r, key, ar);
        }
        else
        {

            // The key lies in between mid1 and mid2
            return ternarySearch(mid1 + 1, mid2 - 1, key, ar);
        }
    }

    // Key not found
    return -1;
}
int main()
{
    srand(time(0));
    int size = 10;
    int arr[size], key = 0, random, succses = 0, unsuccses = 0, result;
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % size;
    }

    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    int xx = 10;
    while (xx)
    {
        key = rand() % size;
        result = ternarySearch(0, size - 1, key, arr);
        if (result != -1)
            cout << "succses -> " << key << " at " << result << "\n";
        else
            cout << "unsuccses\n";
        xx--;
    }

    return 0;
}

/*
0 1 2 3 3 5 5 6 7 8 9 10 11 12 12 16 16 18 18 18
succses -> 7 at 8
succses -> 1 at 1
unsuccses
unsuccses
succses -> 2 at 2
succses -> 8 at 9
unsuccses
succses -> 12 at 13
succses -> 5 at 6
succses -> 16 at 15
*/