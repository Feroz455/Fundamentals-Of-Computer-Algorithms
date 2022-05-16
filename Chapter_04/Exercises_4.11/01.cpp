/*
minimum number of coin Problems
*/
#include <bits/stdc++.h>
using namespace std;

// All denominations of Bangladeshi Currency
int deno[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
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
output
Enter you taka to chage into coin  -> 658
Following is minimal number of change for 658: 500 100 50 5 2 1 
Nnumber of coint need -> 6
*/