/*
Page 119
2. Experimentally compare the performance of SimoleUnion and SimpleFind (Algorithm 2.13) with WeightedUnion
(Algorithm 2.14) and callapsingFind (Algorithm 2.15). For this genetate a random sequence of union and find 
operations  
*/


void SimpleUnion(int i,int j)
{
    Array[i] = j;
}
int SimpleFind(int i)
{
    while(Array[i] >= 0)
    {
        i = Array[i];
    }
    return i;
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