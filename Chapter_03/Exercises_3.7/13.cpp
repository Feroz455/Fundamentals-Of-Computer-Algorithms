/*
Page 189

Present an O(1) times Monte Carlo algorithm to find the median of
array of n numbers. The answer output should be correct with probability >= 1/n
*/
/* C++ program to find Approximate Median using
   1/2 Approximate Algorithm */
#include <bits/stdc++.h>
using namespace std;

// This function returns the Approximate Median
int randApproxMedian(int arr[], int n)
{
    // Declaration for the random number generator
    random_device rand_dev;
    mt19937 generator(rand_dev());

    // Random number generated will be in the range [0,n-1]
    uniform_int_distribution<int> distribution(0, n - 1);

    if (n == 0)
        return 0;

    int k = 10 * log2(n); // Taking c as 10

    // A set stores unique elements in sorted order
    set<int> s;
    for (int i = 0; i < k; i++)
    {
        // Generating a random index
        int index = distribution(generator);

        // Inserting into the set
        s.insert(arr[index]);
    }

    set<int>::iterator itr = s.begin();

    // Report the median of the set at k/2 position
    // Move the itr to k/2th position
    advance(itr, (s.size() / 2) - 1);

    // Return the median
    return *itr;
}

// Driver method to test above method
int main()
{
    srand(time(0));
    int arr[] = {1, 3, 2, 4, 5, 6, 8, 7}, temp;
    int n = sizeof(arr) / sizeof(int);
    int midian = randApproxMedian(arr, n);
    cout << "Approximate Median is " << midian << " \n";
    for (int i = 0; i < log2(n); i++)
    {
        temp = ceil(rand() % n);
        if (arr[temp] > midian)
            cout << arr[temp] << " is greater then " << midian << " \n";
    }
    return 0;
}
/*
Approximate Median is 4
5 is greater then 4
5 is greater then 4
6 is greater then 4
*/