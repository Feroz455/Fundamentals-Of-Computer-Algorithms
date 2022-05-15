/*
Page 251
Algorithm 4.13 Assigning program to tapes

//n is the number of program and m the number of tapes
Algorithm Store(n, m)
{
    j = 0; // Next tape to store on
    for(i = 0; i < n; i++)
    {
        write("Append Program", i, "Tp permutation for tape", j);
        j = (j + 1) % m;
    }

} 
*/
// CPP Program to find the order
// of programs for which MRT is
// minimized
#include <bits/stdc++.h>

using namespace std;

// This functions outputs the required
// order and Minimum Retrieval Time
void findOrderMRT(int L[], int n)
{
    // Here length of i'th program is L[i]
    sort(L, L + n);

    // Lengths of programs sorted according to increasing
    // lengths. This is the order in which the programs
    // have to be stored on tape for minimum MRT
    cout << "Optimal order in which programs are to be"
            "stored is: ";
    for (int i = 0; i < n; i++)
        cout << L[i] << " ";
    cout << endl;

    // MRT - Minimum Retrieval Time
    double MRT = 0;
    for (int i = 0; i < n; i++)
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
}

// Driver Code to test above function
int main()
{
    int L[] = {2, 5, 4};
    int n = sizeof(L) / sizeof(L[0]);
    findOrderMRT(L, n);
    return 0;
}
/*
Optimal order in which programs are to bestored is: 2 4 5
Minimum Retrieval Time of this order is 6.33333
*/