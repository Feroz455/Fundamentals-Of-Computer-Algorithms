/*
page 153
4. Devise a 'binary' search algorthm that splits the set not into two sets of(almost)
equal sizes but into two sets, one whice is twice the size of the other. How does this 
algorithm compare with binary search?
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