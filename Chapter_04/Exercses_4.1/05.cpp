/*
page 214
05) Write a program implementing the change-making solution of Example 4.1.
Asume that the cashier has bills in the denominations 100, 50, 20, 10, 5, 1
in adition to coins. Your program should include a method to input the purchase
amount and the amount given by the coutomer as well as method to output
the amount od change and beakdown by denomination.
*/
#include <bits/stdc++.h>
using namespace std;

// All takaminations of Bangladeshi Currency
int taka[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
int poisa[] = {1, 5, 10, 25};
int TakaN = sizeof(taka) / sizeof(taka[0]);
int PoisaN = sizeof(poisa) / sizeof(poisa[0]);

int findMin(int TAKA, int POISA)
{
    sort(taka, taka + TakaN);
    sort(poisa, poisa + PoisaN);

    // Initialize result
    vector<int> TAns, PAns;

    // Traverse through all takamination
    for (int i = TakaN - 1; i >= 0; i--)
    {

        // Find takaminations
        while (TAKA >= taka[i])
        {
            TAKA -= taka[i];
            TAns.push_back(taka[i]);
        }
    }

    // Traverse through all takamination
    for (int i = PoisaN - 1; i >= 0; i--)
    {

        // Find takaminations
        while (POISA >= poisa[i])
        {
            POISA -= poisa[i];
            PAns.push_back(poisa[i]);
        }
    }
    // Print result
    cout << "TAKA ->\t";
    for (int i = 0; i < TAns.size(); i++)
    {
        cout << TAns[i] << " ";
    }
    cout << "\nPOISA->\t";
    for (int i = 0; i < PAns.size(); i++)
    {
        cout << PAns[i] << " ";
    }
    cout << "\n";

    return (TAns.size() + PAns.size());
}

// Driver program
int main()
{

    int TAKA, POISA;

    cout << "Pay your bill\n";
    cout << "Enter Taka \t->\t";
    cin >> TAKA;
    cout << "Enter Poisa \t->\t";
    cin >> POISA;

    if (POISA >= 100)
    {
        TAKA = TAKA + (POISA / 100);
        POISA = POISA % 100;
    }

    cout << "Following is minimal"
         << " number of change for " << TAKA << "\ttaka\t" << POISA << "\tpoisa\n";

    int result = findMin(TAKA, POISA);
    cout << "\nNnumber of coint need -> " << result << "\n";
    return 0;
}
/*
Pay your bill
Enter Taka      ->      285
Enter Poisa     ->      135
Following is minimal number of change for 286   taka    35      poisa
TAKA -> 200 50 20 10 5 1
POISA-> 25 10

Nnumber of coint need -> 8
*/