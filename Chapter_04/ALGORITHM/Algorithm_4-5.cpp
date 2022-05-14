/*
page 227

Algorithm 4.5 TVS for the special case of binary tree

//Determine and output a minimum cardinality split set
//The tree is realized the sequentiial representation
//Root is at tree[1]. N is the largest number such that
//Tree[N] has a tree node
Algorithm TVS(i, del)
{
    if(tree[i] != 0) then // If the tree is not empty
    if(2i > N) then d[i] = 0; // i is a leaf
    else
    {
        TVS(2i, del);
        d[i] = max(di), d[2i]+weight[2i]);
        if(2i + 1 <= N)
        {
            TVS(2i + 1, del);
            d[i] = max(d[i], d[2i+1] + weight[2i+1]);
        }
    }
    if((tree[i] != 1) and d[i] + weight[i] > del)
    {
        write (tree[i]);
        d[i] = 0;
    }
}

*/