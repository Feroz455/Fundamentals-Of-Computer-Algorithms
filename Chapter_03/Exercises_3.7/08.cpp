/*
Page 188
08. Input are a sequence S of n distinct keys not necessarily in sorted order
and two integer m1 , m2, (1 <= m1, m2 <= n). For any x in S, we defined the rank of
x in S to be | {k E S: k <= x}. Show how to output all the keys of S whose ranks fall in
the intervel [m1, m2] in O(n);
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

// Function to find rank
void rankify(int A[], int m1, int m2, int n)
{

    // Rank Vector
    float R[n] = {0};

    // Sweep through all elements in A for each
    // element count the number of less than and
    // equal elements separately in r and s.
    for (int i = m1; i < m2; i++)
    {
        int r = 1, s = 1;

        for (int j = m1; j < m2; j++)
        {
            if (j != i && A[j] < A[i])
                r += 1;

            if (j != i && A[j] == A[i])
                s += 1;
        }

        // Use formula to obtain rank
        R[i] = r + (float)(s - 1) / (float)2;
    }

    for (int i = m1; i < m2; i++)
        cout << R[i] << ' ';
}

// Driver Code
int main()
{
    srand(time(0));
    int size = 20, key;
    int array[100];
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 10;
    }
    for (int i = 0; i < size; i++)
        cout << array[i] << ' ';
    cout << '\n';
    int m1, m2;
    cout << "Enter boundary-> ";
    cin >> m1 >> m2;
    rankify(array, m1, m2, size);

    return 0;
}
/*
4 7 9 2 8 4 7 7 7 1 3 4 4 5 7 3 8 9 9 6 
Enter boundary-> 5 15  
4 8.5 8.5 8.5 1 2 4 4 6 8.5 
*/