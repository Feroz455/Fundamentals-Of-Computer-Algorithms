/*
Page 594

Obtained an O(n log n) Algorithm that implements the LPT scheduling rule
*/

#include <bits/stdc++.h>

using namespace std;

// creating a structure of a process
struct process
{
    int processno;
    int AT;
    int BT;

    // for backup purpose to print in last
    int BTbackup;
    int WT;
    int TAT;
    int CT;
};

// creating a structure of 4 processes
struct process p[4];

// variable to find the total time
int totaltime = 0;
int prefinaltotal = 0;

// comparator function for sort()
bool compare(process p1, process p2)
{
    // compare the Arrival time of two processes
    return p1.AT < p2.AT;
}

// finding the largest Arrival Time among all the available
// process at that time
int findlargest(int at)
{
    int max = 0, i;
    for (i = 0; i < 4; i++)
    {
        if (p[i].AT <= at)
        {
            if (p[i].BT > p[max].BT)
                max = i;
        }
    }

    // returning the index of the process having the largest BT
    return max;
}

// function to find the completion time of each process
int findCT()
{

    int index;
    int flag = 0;
    int i = p[0].AT;
    while (1)
    {
        if (i <= 4)
        {
            index = findlargest(i);
        }

        else
            index = findlargest(4);
        cout << "Process executing at time " << totaltime
             << " is: P" << index + 1 << "\t";

        p[index].BT -= 1;
        totaltime += 1;
        i++;

        if (p[index].BT == 0)
        {
            p[index].CT = totaltime;
            cout << " Process P" << p[index].processno
                 << " is completed at " << totaltime;
        }
        cout << endl;

        // loop termination condition
        if (totaltime == prefinaltotal)
            break;
    }
}

int main()
{

    int i;

    // initializing the process number
    for (i = 0; i < 4; i++)
    {
        p[i].processno = i + 1;
    }

    // cout<<"arrival time of 4 processes : ";
    for (i = 0; i < 4; i++) // taking AT
    {
        p[i].AT = i + 1;
    }

    // cout<<" Burst time of 4 processes : ";
    for (i = 0; i < 4; i++)
    {

        // assigning {2, 4, 6, 8} as Burst Time to the processes
        // backup for displaying the output in last
        // calculating total required time for terminating
        // the function().
        p[i].BT = 2 * (i + 1);
        p[i].BTbackup = p[i].BT;
        prefinaltotal += p[i].BT;
    }

    // displaying the process before executing
    cout << "PNo\tAT\tBT\n";

    for (i = 0; i < 4; i++)
    {
        cout << p[i].processno << "\t";
        cout << p[i].AT << "\t";
        cout << p[i].BT << "\t";
        cout << endl;
    }
    cout << endl;

    // sorting process according to Arrival Time
    sort(p, p + 4, compare);

    // calculating initial time when execution starts
    totaltime += p[0].AT;

    // calculating to terminate loop
    prefinaltotal += p[0].AT;
    findCT();
    int totalWT = 0;
    int totalTAT = 0;
    for (i = 0; i < 4; i++)
    {
        // since, TAT = CT - AT
        p[i].TAT = p[i].CT - p[i].AT;
        p[i].WT = p[i].TAT - p[i].BTbackup;

        // finding total waiting time
        totalWT += p[i].WT;

        // finding total turn around time
        totalTAT += p[i].TAT;
    }

    cout << "After execution of all processes ... \n";

    // after all process executes
    cout << "PNo\tAT\tBT\tCT\tTAT\tWT\n";

    for (i = 0; i < 4; i++)
    {
        cout << p[i].processno << "\t";
        cout << p[i].AT << "\t";
        cout << p[i].BTbackup << "\t";
        cout << p[i].CT << "\t";
        cout << p[i].TAT << "\t";
        cout << p[i].WT << "\t";
        cout << endl;
    }

    cout << endl;
    cout << "Total TAT = " << totalTAT << endl;
    cout << "Average TAT = " << totalTAT / 4.0 << endl;
    cout << "Total WT = " << totalWT << endl;
    cout << "Average WT = " << totalWT / 4.0 << endl;
    return 0;
}
/*
PNo     AT      BT
1       1       2 
2       2       4 
3       3       6 
4       4       8 

Process executing at time 1 is: P1
Process executing at time 2 is: P2
Process executing at time 3 is: P3
Process executing at time 4 is: P4
Process executing at time 5 is: P4
Process executing at time 6 is: P4
Process executing at time 7 is: P3
Process executing at time 8 is: P4
Process executing at time 9 is: P3
Process executing at time 10 is: P4
Process executing at time 11 is: P2
Process executing at time 12 is: P3
Process executing at time 13 is: P4
Process executing at time 14 is: P2
Process executing at time 15 is: P3
Process executing at time 16 is: P4
Process executing at time 17 is: P1      Process P1 is completed at 18
Process executing at time 18 is: P2      Process P2 is completed at 19
Process executing at time 19 is: P3      Process P3 is completed at 20
Process executing at time 20 is: P4      Process P4 is completed at 21
After execution of all processes ...
PNo     AT      BT      CT      TAT     WT
1       1       2       18      17      15
2       2       4       19      17      13
3       3       6       20      17      11
4       4       8       21      17      9

Total TAT = 68
Average TAT = 17
Total WT = 48
Average WT = 12
*/