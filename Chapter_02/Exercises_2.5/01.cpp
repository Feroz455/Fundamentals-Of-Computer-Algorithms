/*
Page 119 
1. Suppose we start with n sets, each containing a distinct element.

a) Show that if u unions are performend, then no set contains more than u+1 elements.

b) Show that at most n-1 union can be parformed before the number of sets becomes 1

c) Show that if fewer than (n/2) unions can be performed, 
then at least one set with a single element in it remains.

d) Show that if u unions are performed, then at least max(n-2u, 0) singleton sets remain.

*/
#include<iostream>

using namespace std;
int Array[100];

void option() {
    int i = 1;
    cout << "\n************************************\n";
    //cout << i++ << "Enter sets value\n";
    cout << i++ << "\tUnion set\n";
    cout << i++ << "\tFind Parent\n";
    cout << i++ << "\tShow result\n";
    cout << i++ << "\tExit\n";
    cout << "\n************************************\n";
}

int CollapsingFInd(int i)
//Find the root of the tree containing elemenet i. Use the 
//Collapsing rule to collapse all nodes from i to the root
{
    int r, s;
    r = i;
    while (Array[r] > 0) {
        r = Array[r]; //Find the root
    }

    //Collapse nodes from i to root r
    while (i != r) {
        s = Array[i];
        Array[i] = r;
        i = s;
    }
    return r;
}

void WeightedUnion(int i, int j)
//Union sets with roots i and j, where i != j using the 
//Weighting rule Array[i] = -count[i] and Array[j] = - count[j];
{
    int temp = (Array[i]) + (Array[j]);
    if (Array[i] > Array[j]) {
        //I has fewer nodes
        Array[i] = j;
        Array[j] = temp;
    } else {
        //j has fewer or equal nodes
        Array[j] = i;
        Array[i] = temp;
    }
}
int SimpleFind(int i) {
    while (Array[i] >= 0) {
        i = Array[i];
    }
    return i;
}
int main() {
    int count, N, tempi, tempj, opcode;
    cout << "Number of element? --> \t";
    cin >> N;
    for (int i = 1; i <= N; i++) {
        Array[i] = -1;
    }
    while (1) {
        option();
        cin >> opcode;
        switch (opcode) {
            case 1:
                cout << "Enter 2 sets number\n";
                cin >> tempi >> tempj;
                if (tempi > N || tempj > N)
                    break;
                else
                    WeightedUnion(tempi, tempj);
                break;
            case 2:
                cout << "Enter set value\n";
                cin >> tempi;
                if (tempi >= N)
                    break;
                else
                    cout << CollapsingFInd(tempi) << "\n";
                break;
            case 3:
                for (int i = 1; i <= N; i++) {
                    cout << i << " -> " << Array[i] << "\n";
                }
                break;
            case 4:
                exit(1);
            default:
                break;
        }
    }

}