/*
Page 146

//Given an array a[i:l] of elements in nondecreasing
//order a <= i <= l, determine whether x is present , and
//if so, return j such that x = a[j]; else return 0

Algorithm BinSech(a, i, l, x)
{
    if(l == i) then //If small(P)
    {
        if(x = a[j]) then return i;
        else
        return 0;
    }
    else
    {
        //Reduce P into a smaller subproblem
        mid = floor((i+l)/2);
        if(x = a[mid])
        then return mid;
        else
        if(x < a[mid])
        then
        return BinSrch(a, i, mid-1, x);
        else
        return BinSrch(a,mid+1, l, x);
    }
}
*/
#include <iostream>
#include <ctime>
#include <algorithm>
#include <math.h>
using namespace std;
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
            //cout << "From 5 -> " << mid << "\n";
            return BinSrch(a, mid + 1, l, x);
        }
    }
}

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }

    // We reach here when element is not
    // present in array
    return 0;
}
int main()
{
    srand(time(0));
    int size = 20;
    int arr[size], key = 0;
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 1000;
    }
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\nEnter your Key to Search\n";
    cin >> key;
    int result = BinSrch(arr, 0, size, key);
    if (result != -1)
        cout << "item fount at -> " << result + 1 << "\n";
    else
        cout << "NOT FOUND!!!\n";
    return 0;
}
/*
0 39 99 138 155 164 175 181 221 325 330 513 649 734 774 792 812 831 973 976
Enter your Key to Search
976
item fount at -> 20

108 116 133 242 333 358 374 394 429 495 608 613 659 704 723 743 773 890 926 933 
Enter your Key to Search
608
item fount at -> 11
*/