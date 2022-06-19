/*
Page 620

Algorithm 12.10 Function for exercise

Algorithm MSat2(l)
//Same function as MSat
{
    w[i] = 2^|C[i]|, 1 <= i <= p;
    //Weightting function |C[i]| = number of Literas in C[i]
    CL = 0;
    Left = {C[i]| 1 <= i <= p}
    Lit = {xi, `x[i]| 1 <= i <= n}
    while(Lit contains a literal occuring in a clause in left)
    {
        Let y belogss Lit be such that y occure in a clause in left
        let R be the subset of clauses in left contains y;
        Let s be the subset of clauses in left cintaining `y;
        if Sumof(c[i] to R)(w[i]) >= SUMof(C[i] to S)(w[i])
        {
            CL = CL U R;
            left = left - R;
            w[i] = 2 * w[i] for each C[i] belongs S;
        }
        else
        {
        CL = CL U S;
        Left = left  - S;
        w[i] - 2 * w[i] for each Ci belongs R;
        }
    Lit = Lit - {y, `y}.
    }
    return CL;

}
*/