/*
Page 252
01) Find an optimal placement for 13 programs on three tapes T0, T1, T2, where the program
are of lenths 12, 5, 8, 32, 7, 5, 18, 26, 4, 3, 11, 10, 6
*/
#include <bits/stdc++.h>
using namespace std;

// This functions outputs the required
// order and Minimum Retrieval Time
float findOrderMRT(vector<int> L, int n)
{
    // Here length of i'th program is L[i]

    // Lengths of programs sorted according to increasing
    // lengths. This is the order in which the programs
    // have to be stored on tape for minimum MRT
    cout << "Optimal order in which programs are to be"
            "stored is: ";
    for (int i = 0; i < L.size(); i++)
        cout << L[i] << " ";
    cout << endl;

    // MRT - Minimum Retrieval Time
    double MRT = 0;
    for (int i = 0; i < L.size(); i++)
    {
        int sum = 0;
        for (int j = 0; j <= i; j++)
            sum += L[j];
        MRT += sum;
    }
    MRT /= n;
    cout << "Minimum Retrieval Time of this"
            " order is "
         << MRT;
    cout << "\n";
    return MRT;
}

// Driver Code to test above function
int main()
{
    int size = 3, n;
    float sum = 0.0;
    vector<int> array = {12, 5, 8, 32, 7, 5, 18, 26, 4, 3, 11, 10, 6};
    sort(array.begin(), array.end());
    vector<int> T[3];
    n = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < ceil(float(array.size()) / float(size)); j++)
        {
            if (n < array.size())
            {
                T[i].push_back(array[n]);
                n++;
            }
        }
        sum += findOrderMRT(T[i], T[i].size());
    }
    cout << "Total  TD -> " << sum << "\n";
    // findOrderMRT(array, array.size());
    return 0;
}
/*
Optimal order in which programs are to bestored is: 3 4 5 5 6
Minimum Retrieval Time of this order is 12.4
Optimal order in which programs are to bestored is: 7 8 10 11 12
Minimum Retrieval Time of this order is 26.2
Optimal order in which programs are to bestored is: 18 26 32
Minimum Retrieval Time of this order is 46
Total  TD -> 84.6
*/