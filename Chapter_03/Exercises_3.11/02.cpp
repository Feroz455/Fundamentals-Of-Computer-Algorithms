/*
Page 207

02. The set A and B have n elements each in the from of sorted array.
Present an O(n) time algorihtm to compute A(union)B and A(intersection)B
*/
#include <algorithm> //  set_union,  sort
#include <iostream>  //  cout
#include <vector>    //  vector
using namespace std;

// Driver code
int main()
{
    int first[] = {5, 10, 15, 20, 25};
    int second[] = {50, 40, 30, 20, 10};
    int n = sizeof(first) / sizeof(first[0]);

    // Print first array
    cout << "First array contains :";
    for (int i = 0; i < n; i++)
        cout << " " << first[i];
    cout << "\n";

    // Print second array
    cout << "Second array contains :";
    for (int i = 0; i < n; i++)
        cout << " " << second[i];
    cout << "\n\n";

    vector<int> v(10) ;
    vector<int>::iterator it, st;

    sort(first, first + n);
    sort(second, second + n);

    // Using default function
    it = set_union(first, first + n, second,
                   second + n, v.begin());

    cout << "The union has " << (it - v.begin())
         << " elements:\n";
    for (st = v.begin(); st != it; ++st)
        cout << ' ' << *st;
    cout << '\n';
    // Using default function
    it = set_intersection(first, first + n, second,
                          second + n, v.begin());

    cout << "The intersection has " << (it - v.begin())
         << " elements:\n";
    for (st = v.begin(); st != it; ++st)
        cout << ' ' << *st;
    cout << '\n';

    return 0;
}
/*
First array contains : 5 10 15 20 25  
Second array contains : 50 40 30 20 10

The union has 8 elements:
 5 10 15 20 25 30 40 50
The intersection has 2 elements:      
 10 20
*/