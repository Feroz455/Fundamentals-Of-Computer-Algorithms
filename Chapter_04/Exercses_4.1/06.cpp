/*
Page 214
Suppose that some country has coins in the denominations 14, 12, 5, and 1 cent.
Will the greedy method of example 4.1 always generate change with the fewest
number of coins, Prove your ans.
*/
#include <bits/stdc++.h>
using namespace std;

// All denominations of Bangladeshi Currency
int deno[] = {1, 5, 12, 14};
int penney, nickels, dimes, quaters;

int n = sizeof(deno) / sizeof(deno[0]);

int findMin(int V)
{
    sort(deno, deno + n);

    // Initialize result
    vector<int> ans;

    // Traverse through all denomination
    for (int i = n - 1; i >= 0; i--)
    {

        // Find denominations
        while (V >= deno[i])
        {
            V -= deno[i];
            ans.push_back(deno[i]);
        }
    }

    // Print result
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return (ans.size());
}

// Driver program
int main()
{

    int n;
    cout << "Enter you taka to chage into coin  -> ";
    cin >> n;
    cout << "Following is minimal"
         << " number of change for " << n << ": ";
    int result = findMin(n);
    cout << "\nNnumber of coint need -> " << result << "\n";
    return 0;
}
/*
Enter you taka to chage into coin  -> 67
Following is minimal number of change for 67: 14 14 14 14 5 5 1
Nnumber of coint need -> 7


Enter you taka to chage into coin  -> 96
Following is minimal number of change for 96: 14 14 14 14 14 14 12
Nnumber of coint need -> 7
*/