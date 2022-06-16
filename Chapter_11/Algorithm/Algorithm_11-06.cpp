/*
Algorithm 11.6 Nondeterministic satisfiability 
Algorithm Eval(E, n)
//Determine wheater the propositional formula E is 
//Satisfiable. The variable are x1, x2, .....xn
{
    for i = 1; to n do // Choose a tructh value assignment 
    xi = Choice(false, true);
    if E(x1,.....,xn) 
    Success();
    else 
    Failure();
}
*/