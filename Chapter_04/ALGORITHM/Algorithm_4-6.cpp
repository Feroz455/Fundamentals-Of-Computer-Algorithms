/*
page 230 
Algorithm 4.6 High-level desription of job sequencing algorithm 

//J is a set of jobs that can be comleted by their deadlines
Algorithm GreedyJob(d, j, n)
{
    j = {1};
    for(i = 2 to n do)
    {
        if(all jobs in J U(i) can be completed by their deadlines) then j = J U {i}
    }

}
*/