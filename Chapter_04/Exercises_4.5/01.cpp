/*
page 233
01. You are given a set of n jobs. Associated with each job i is a processing
time ti and a deadline di by which it must be completed. A feasible shecdule is
a permutation of the jobs such that if the jobs are processed in the order, then
each job finishes by its deadline. Define a greedy schedule to be one in which the
jobs are process in nodecreasing order of deadlines. Show that if there exists a
fieasible schedule, then all greedy schedules are feasible.
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