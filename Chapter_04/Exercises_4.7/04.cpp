/*
Page 253
04) Assume n program of lengths l1, l2, ......, ln are to be stored in a tap
Program i si to be retrived with frequency fi. If the program are stored in the
order i1, i2 .... in the expected retrival time ERT
*/
#include <bits/stdc++.h>
using namespace std;
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
    }
    cout << "\n";
    findOrderMRT(arr, arr.size());
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
Optimal order in which programs are to bestored is: 3 4 5 5 6 7 8 10 11 16 18
Minimum Retrieval Time of this order is 36.8182
*/