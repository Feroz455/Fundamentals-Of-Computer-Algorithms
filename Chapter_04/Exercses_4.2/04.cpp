/*
Page 217

4)
If two people perform the n task of exercise 3, we need an assignment
of task to each and an order in wich each person is to perform his
assigned tasks the task completion times and ACT are defined as in
Exercises 3. A possible greedy method that aimes to minimzize the ACT
is as follow. The two worker select tasks. alternately and one at a
time. From the remaining tasks. one with least task time is selected
each person does his tasks in the order selectd, for the example of
exercises 3(a), if person 1 begins the selection process, he select
task 4, person 2 select task 2, person 1 selecets task 1, and finally person
2 select task 3

a) Write an algorithm implement this strategy, What is its time complexity

b) Does the outlined greedy strategy always minimize the ACT? Prove your answer

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
struct compare
{
    bool operator()(job const &a, job const &b) const
    {

        return a.time > b.time;
    }
};

int arr[] = {4, 2, 8, 1};
int n = sizeof(arr) / sizeof(int);

void ATC(priority_queue<job, vector<job>, compare> task)
{
    float average1 = 0.0, average2 = 0.0, person1[n] = {0.0}, person2[n] = {0.0};
    job JOB;

    int i = 1;
    JOB = task.top();
    average1 = person1[0] = JOB.time;
    task.pop();
    JOB = task.top();
    average2 = person2[0] = JOB.time;
    task.pop();
    while (!task.empty())
    {
        JOB = task.top();
        person1[i] = JOB.time + person1[i - 1];
        average1 += person1[i];
        task.pop();
        if (task.empty())
            break;
        JOB = task.top();
        person2[i] = JOB.time + person2[i - 1];
        average2 += person2[i];
        task.pop();
        i = i + 1;
    }

    cout << "ATC -> " << (average1 + average2) / n << "\n";
}

int main()
{
    priority_queue<job, vector<job>, compare> task;

    job JOB;
    for (int i = 0; i < n; i++)
    {
        JOB.id = i;
        JOB.time = arr[i];
        task.push(JOB);
    }
    ATC(task);
    return 0;
}
/*
ATC -> 4.5
*/