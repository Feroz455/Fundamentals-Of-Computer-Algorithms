/*
Page 208

04
Consider the poblem of sorting a sequence X of n keys where each
key is either zero or one (i.e each key is a bit). One way of sorting
X is to start with two empty lists L0, L1 X = k1, k2, ...kn
For each 1 < i < n do. If ki = 0, then append ki to L0. If ki = 1, then
append ki to L1. After processing all the keys of X in this manner output
the list L0 followed by the list L1;

The above idea of sorting can be extendent to the case in wich each keh
is of lenght more then one bit. In practicular, if the keys are intergers
int the range (0,m-1) then we start wit m empty list. L0, L1, ....Lm-1
one list or bucket for each possible valu that a key can take. Then the key
are processed in a similar fashion. In particular if a key has a value L
then it will be appended to the Lth list

Write an algorithm that emplouys this idea to sort n keys assuming that each
key is in the range [0,m-1]. This algorithm known as the bucket sort.
*/

// C++ program to sort an
// array using bucket sort
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Function to sort arr[] of
// size n using bucket sort
void bucketSort(float arr[], int n)
{

    // 1) Create n empty buckets
    vector<float> b[n];

    // 2) Put array elements
    // in different buckets
    for (int i = 0; i < n; i++)
    {
        int bi = n * arr[i]; // Index in bucket
        b[bi].push_back(arr[i]);
    }

    // 3) Sort individual buckets
    for (int i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end());

    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];
}

/* Driver program to test above function */
int main()
{
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);

    cout << "Sorted array is \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
/*
Sorted array is 
0.1234 0.3434 0.565 0.656 0.665 0.897 
*/