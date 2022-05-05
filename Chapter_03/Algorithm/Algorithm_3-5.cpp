/*
Page 152
Algoritm BinSearch(a, n, x)
//Same specifiction as BinSearch except n > 0
{
    low = 1;
    high = n + 1;
    //high is one more than possible
    while(low < (high -1))
    {
        mid = floor((low+high))/2;
        if(x < a[mid])
        {
            high = mid;
        }
        //only one comparison in the loop
        else
        low = mid; // x >= a[mid];
    }
    if(x = a[low])
    {
        return low; // x is present
    }
    else
    return 0; // x is not present
}
*/
#include <iostream>
#include <ctime>
#include <algorithm>
#include <math.h>
using namespace std;
int BinSearch(int a[], int n, int x)
{
    int low = 1;
    int high = n;
    while (low <= high)
    {
        int mid = floor((low + high) / 2);
        if (x < a[mid])
        {
            high = mid - 1;
        }
        else if (x > a[mid])
        {
            low = mid + 1;
        }
        else
            return mid;
    }
    return -1;
}
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

    int result = BinarySearch(arr, size, key);

    if (result != -1)
        cout << "item fount at -> " << result << "\n";
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


231 258 259 287 296 329 335 394 485 604 610 652 659 741 773 794 824 833 927 996 
Enter your Key to Search
299
NOT FOUND!!!
*/