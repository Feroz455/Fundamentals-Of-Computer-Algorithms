/*
Page 252
03)
Let P1, P2,......Pn be a set of n program that are to be stored on a tape
of lenght L, Program Pi requires ai amount of tape. If SUM(ai <= L), then clearly all the
Program can be stor in the tape . So assume SUM(ai > l). The problem is to select a maximum
subset Q of the programs for storage on the tap. (A maximum subset is one with the maximum number)
of program in it). A greedy algorithm for this problem would build the subset Q by including
programs in nondecreasing order of ai


a) Assume the Pi are orderd such that a1 <= a2 ..... <= an.
Write a function for the above strategy. You function should output an array
s[1:n] such that s[i] = 1 if Pi is in Q and s[i] = 0
other wise

b) Show that this strategy always finds a maximum subset Q such that SUM(pi bilongs to Q Ai <= l)

c) Let Q be the subset obtained using the above greedy strategy How small can the tape utilization ratio
get
*/
#include <bits/stdc++.h>
using namespace std;

void Func(priority_queue<int, vector<int>, greater<int>> PRO, vector<int> s, int lenght, int program)
{
    vector<int> arr;
    float sum = 0.0;
    for (int i = 0; i < program; i++)
    {
        int n = PRO.top();
        if (lenght > n)
        {
            arr.push_back(n);
            s.push_back(1);
        }
        else
            s.push_back(0);
        PRO.pop();
        lenght -= n;
    }
    for (int i = 0; i < s.size(); i++)
    {
        cout << setw(3) << s[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << setw(3) << arr[i] << " ";
        sum += float(arr[i]);
    }
    cout << "\nRatio = " << sum / float(arr.size());
}
// Main start here
int main()
{
    int size = 20;
    int tape, program;
    // Creates a min heap
    cout << "Enter the length of tape and Program \n";
    cin >> tape >> program;
    vector<int> s;
    priority_queue<int, vector<int>, greater<int>> PRO;
    cout << "Enter program size\n";
    for (int i = 0; i < program; i++)
    {
        int n;
        cin >> n;
        PRO.push(n);
    }
    Func(PRO, s, tape, program);
    return 0;
}
/*
Enter the length of tape and Program
100 13
Enter program size
5
8
32
7
5
18
26
4
3
11
10
6
16
  1   1   1   1   1   1   1   1   1   1   1   0   0
  3   4   5   5   6   7   8  10  11  16  18
  Ratio = 8.45455
*/