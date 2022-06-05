/*
Page 369

Algorithm 7.2 General iterative backtracking method

Algorithm IBracktrack(n)
//This schema describes the backtracking Process
//All solution are generated in x[1:n] and printed
//as soon as they are determined
{
    k = 1;
    while(k != 0)
    {
        if(there remains an untried x[k] (- T(x[1], x[2],....., x[k-1]) and Bk(x[1],....,x[k] is true) then))
        {
            if (x[1],.....x[k] is a path to an answer node)
            {
                write(x[1:k]);
            }
            k = k + 1; // consider the next set
        }

    }
    else k = k - 1; // Bracktrack to the previous set;

}
*/