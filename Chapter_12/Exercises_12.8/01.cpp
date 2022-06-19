/*
Page  618

01) The setisfiability problems was introduced in chapter 11. 
Defined maximum satisfiability to be the problem of determining a maximum sub set
of clauses that can be satisfied simultaniously. If a formula has o clasuses, the all
p clauses can be simultaneously satisfied if and only if the formula is satisfiable, 
For function MSat (Algorithm 12.9) show that for every instance i, 
*/

/*
Page 619
Algorithm 12.9 Function for exercises 1 

Algiruthm MSat(l)
//Appromimation algorithm for maximum satisfiability 
//l is a formula Let x[1:n] be the variable in l
//and let Ci 1 <= i <= p be the clauses
{
    CL = 0;// Set of clauses simultaniously satisfiable 
    Left = {C[i] | 1 <= i <= n}; // Remaining clauses 
    Lit = {xi , X^[i]| 1 <= n} // Set of all literals 
    while(Lit contains a literal occurring in a clauses in left do)
    {
        let g be a literal in Lit that is in the most clauses of Left;
        Let  R be the subset of clauses in left that contains y;
        CL = Cl U R;
        Left = Left - R;
        Lit = Lit - {y, `y};
    }
    return CL;
}
*/