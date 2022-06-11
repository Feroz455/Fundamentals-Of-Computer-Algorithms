/*
Page 412
03)
Give an algorithm schema LcBB for LC branch and bound search for least cost answer node
Page 407
Algorithm 8.1 LC-search

listnode = record
{
    listnode *next, *parent;
    float cost;
}

Algorithm LCSearch(listnode *t)
//Search t for an answer node
{
    if *t is an answer node then output *t and retrun;
    E = t; // E-node
    //Inititalize the list of live nodes to be empty
    do
    {
        for each child of E do
        {
            if x is an answer node then output the path from x to t and return
            Add(x); // x is a new live node
            x->parent = E; // Pointer for path to root
        }

        if there are no more live nodes then \
        {
            write ("No answer node");
            return;
        }
        E = Least();
    }while(true);
}
*/