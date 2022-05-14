/*
page 231

Algorithm 4.7
Greedy algorithm for sequencing unit time jobs with dead lines and profits

//d[i] >= 1, 1 <= n are deadlines, n>= 1. the jobs
//are ordered such that p[1] >= p[2] >= ....>= p[n]. J[i]
//is the ith job in the optimal solution , 1 <= i <= k
//Also at termination d[j[i] <= d[j[i+1]], 1 <= i < k
Algorithm JS(d, j, n)
{
    d[0] = J[0] = 0; // Initialize
    J[1] = 1; // Include job 1;

    k := 1;

    for(i = 2 to n do)
    {
        // Consider jobs in nonincreasing order of p[i]. Find
        //Position for i and check feasibility of insertion

        r = k;
        while((d[j[r]] > d[i]) && (d[j[r]] != r))
        do
        r = r - 1;
        if(d[J[r]] <= d[i]) and (d[i] > r) then
        //Insert i into j
        for q = k to (r+1) step-1 do J[q+1] = J[q];
        j[r+1] = i; k = k + 1;
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
    int Dmax, i, j, k, MaxProfit = 0, timeSlot[size], filledTimeslot = 0;
    Dmax = Max(jobs, size);
    cout << "Max " << Dmax << "\n";
    for (int i = 0; i < size; i++)
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
    int Jobs_Number = 5;
    Job temp, Jobs[Jobs_Number] = {{"Job1", 2, 60},
                                   {"Job2", 1, 100},
                                   {"Job3", 3, 20},
                                   {"Job4", 2, 40},
                                   {"Job5", 1, 20}};
    PrintJobs(Jobs, Jobs_Number);
    // Sorting the jobs profit wise in descending order
    sort(Jobs, Jobs + Jobs_Number, comparison);
    PrintJobs(Jobs, Jobs_Number);

    Job_Sequence(Jobs, Jobs_Number);
    return 0;
}
/*
    Job ID   job Deadline       Job Profit
      Job1              2             60  
      Job2              1            100  
      Job4              2             40  
      Job5              1             20  

    Job ID   job Deadline       Job Profit
      Job2              1            100  
      Job1              2             60  
      Job4              2             40  
      Job3              3             20
      Job5              1             20

Max 3
Required Jobs: Job2 -> Job1 -> Job3
MaxProfit -> 180
*/