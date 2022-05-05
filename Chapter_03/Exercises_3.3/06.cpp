/*
page 153
6.
a) Prove that BinSearch1 works correctly
b) Verify that the following algorithm segment function correctly
according to the specification of binary search. Discuss its computing time
*/
#include <iostream>
#include <ctime>
#include <algorithm>
#include <math.h>
using namespace std;
int BinSearch1(int a[], int n, int x)
{
    int low = 0;
    int high = n, mid;
    do
    {
        mid = floor((low + high) / 2);
        cout << mid << "\n";
        cout << low << "\n";
        cout << high << "\n";
        if (x >= a[mid])
        {
            if (x == a[mid])
            {
                cout << "Found!!\n";
                return mid;
            }
            low = mid;
        }
        else
            high = mid;
    } while ((low + 1) == high);
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
        result = BinSearch1(arr, size-1, key);
        if (result != -1)
            cout << "succses -> " << key << " at " << result << "\n";
        else
            cout << "unsuccses -> " << key << "\n";
        xx--;
    }

    return 0;
}
/*

This dosent work correctly
1 1 1 2 3 4 4 5 7 8 
4
0
9
unsuccses -> 0      
4
0
9
unsuccses -> 7      
4
0
9
Found!!
succses -> 3 at 4   
4
0
9
unsuccses -> 7      
4
0
9
unsuccses -> 2
4
0
9
unsuccses -> 4
4
0
9
unsuccses -> 6
4
0
9
unsuccses -> 7
4
0
9
unsuccses -> 1
4
0
9
unsuccses -> 2
*/