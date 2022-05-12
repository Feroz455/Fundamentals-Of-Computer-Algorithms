/*
page 218
a) Extend the greedy algorihtm of exercises 4 to the case when m persons are
available to do the taks

b) Does your algorithm gurantee optimul solution. Prove your alswer

c) What is the time complexity  of your algorithm
*/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct job
{
    int id;
    int time;
};
int arr[] = {4, 2, 8, 1};
int n = sizeof(arr) / sizeof(int);
struct compare
{
    bool operator()(job const &a, job const &b) const
    {

        return a.time > b.time;
    }
};

float ATC(priority_queue<job, vector<job>, compare> task)
{
    float average = 0.0, x[n];
    job JOB;
    JOB = task.top();
    task.pop();
    int i = 1;
    x[0] = JOB.time;
    while (!task.empty())
    {
        JOB = task.top();
        x[i] = JOB.time + x[i - 1];
        i = i + 1;
        task.pop();
    }

    for (auto i : x)
    {
        average += i;
    }
    return average;
}

int main()
{
    float average = 0.0;
    int check = 1;
    priority_queue<job, vector<job>, compare> task;

    job JOB;
    for (int i = 0; i < n; i++)
    {
        JOB.id = i;
        JOB.time = arr[i];
        task.push(JOB);
    }
    cout << "Enter number of Person\n";
    int person;
    cin >> person;
    priority_queue<job, vector<job>, compare> PRSN[person];
    int i = n;
    while (check)
    {
        for (int k = 0; k < person; k++)
        {
            JOB = task.top();
            PRSN[k].push(JOB);
            task.pop();
            i = i - 1;
            if (i == 0)
            {
                check = 0;
                break;
            }
        }
    }
    for (int k = 0; k < person; k++)
    {
        average += ATC(PRSN[k]);
    }
    cout << "ATC -> " << average / n << "\n";

    return 0;
}
/*
Enter number of Person
2
ATC -> 4.5


complexity will be O(n log n*m)
*/