/*
Page 214

03) Consider the change-making problem of Example 4.1.
Suppose that the cashier has only a limited number of quaters,
dimes, nickels, and pennies, Formulate a greedy solution to
the change-making problem. Does your algorithm always use the
fewest number of coins. Prove your result.

*/
#include <bits/stdc++.h>
using namespace std;

// All denominations of Bangladeshi Currency
int deno[] = {1, 5, 10, 25};
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
Following is minimal number of change for 67: 25 25 10 5 1 1
Nnumber of coint need -> 6
*/