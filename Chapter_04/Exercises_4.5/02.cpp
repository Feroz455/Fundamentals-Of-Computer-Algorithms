/*
page 235

//FInd an optimal solution j[1:k]. It is assumed that
//p[1] >= p[2] >= .... and that b = min{n, maxi(di)}
algorithm FJS(d, n, b, j)
{
    //Inititally there are b + 1 single node trees
    for(int i = 0; i <= b; i++)
    {
        f[i] = i;
    }
    k = 0; // Initialize.

    for(int i = 1; i <= n; i++)
    {
        //Use greedy rule
        q := CollapsingFInd(min(n, d[i]));
        if(f[q] != 0)
        {
            k = k + 1;
            j[k] = i; // Select job i
            m = CollapsingFind(m,q);
            weightedUnion(m,q);
            f[q] = f[m]; // q may be new root;
        }

    }
}
*/
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <climits>
using namespace std;
struct Job
{
    string id;
    int deadline;
    int profit;
};
bool comparison(Job a, Job b)
{
    return (a.profit > b.profit);
}
void PrintJobs(Job Jobs[], int size)
{
    cout << setw(10) << "Job ID" << setw(15) << "job Deadline" << setw(15) << "\tJob Profit\n";
    for (int i = 0; i < size; i++)
    {
        cout << setw(10) << Jobs[i].id << setw(15) << Jobs[i].deadline << setw(15)
             << Jobs[i].profit << "\n";
    }
    cout << "\n";
}
int Max(Job jobs[], int size)
{
    int Dmax;
    for (int i = 0; i < size; i++)
    {
        if (jobs[i].deadline > Dmax)
        {
            Dmax = jobs[i].deadline;
        }
    }
    return Dmax;
}
int minValue(int x, int y)
{
    return ((x > y) ? x : y);
}
void Job_Sequence(Job jobs[], int size)
{
    int Dmax, i, j, MaxProfit = 0, timeSlot[size], filledTimeslot = 0;
    Dmax = Max(jobs, size);
    cout << "Max " << Dmax << "\n";
    for (i = 0; i < size; i++)
    {
        timeSlot[i] = -1;
    }
    for (i = 1; i < size; i++)
    {
        for (j = min(Dmax, jobs[i - 1].deadline); j > 0; j--)
        {
            if (timeSlot[j] == -1)
            {
                timeSlot[j] = i - 1;
                MaxProfit += jobs[i - 1].profit;
                filledTimeslot++;
                break;
            }
        }
        if (filledTimeslot == Dmax)
            break;
    }

    cout << "Required Jobs: ";
    for (i = 1; i <= Dmax; i++)
    {

        cout << jobs[timeSlot[i]].id << " ";

        if (i < Dmax)
        {
            cout << "-> ";
        }
    }
    cout << "\nMaxProfit -> " << MaxProfit << "\n";
}
int main()
{
    int Jobs_Number = 7;
    Job temp, Jobs[Jobs_Number] = {{"Job1", 1, 3},
                                   {"Job2", 3, 5},
                                   {"Job3", 4, 20},
                                   {"Job4", 3, 18},
                                   {"Job5", 2, 1},
                                   {"Job6", 1, 6},
                                   {"Job7", 2, 30}};
    PrintJobs(Jobs, Jobs_Number);
    // Sorting the jobs profit wise in descending order
    sort(Jobs, Jobs + Jobs_Number, comparison);
    PrintJobs(Jobs, Jobs_Number);

    Job_Sequence(Jobs, Jobs_Number);
    return 0;
}
/*
    Job ID   job Deadline       Job Profit
      Job1              1              3
      Job2              3              5
      Job3              4             20
      Job4              3             18
      Job5              2              1
      Job6              1              6
      Job7              2             30

    Job ID   job Deadline       Job Profit
      Job7              2             30
      Job3              4             20
      Job4              3             18
      Job6              1              6
      Job2              3              5
      Job1              1              3
      Job5              2              1

Max 4
Required Jobs: Job6 -> Job7 -> Job4 -> Job3
MaxProfit -> 74
*/