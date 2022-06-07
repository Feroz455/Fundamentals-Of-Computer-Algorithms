/*
Page 384

Algorithm 7.8  Generate a next color

Algorithm NextValue(k)
//x[1],......x[k-1] have been assined interger values in the 
//range [1,m] such that adjacent vertices have distinct 
//integers. A value for x[k] is determined in the range
//[0,m]. x[k] is assigned the next highest numbered color
//while maintaining distinctness from the adjacent vertices
//of the vertex k. If no such color exist, then x[k] = 0; 
{
    do
    {
        x[k] = (x[k]+1) mod (m+1)); //Next hightest color 
        if(x[k] == 0) 
        return; // All colors have been used
        for(j = 1; j <=n; j++)
        {
            //Check if this color is
            //distinct from adjacent colors
            if((G[k,j] != 0) && (x[k] == x[j]))
            //if (k,j) is and edge and if adj
            //vertices have same color
            break;
        } 
        if(j = n + 1) 
        return; // New color found
    }while(false); // Otherwise truy

}
*/

#include <stdio.h>
#include <iostream>
using namespace std;
// Number of vertices in the graph
#define V 4

void printSolution(int color[]);

/* A utility function to check if the current color assignment
is safe for vertex v i.e. checks whether the edge exists or not
(i.e, graph[v][i]==1). If exist then checks whether the color to
be filled in the new vertex(c is sent in the parameter) is already
used by its adjacent vertices(i-->adj vertices) or not (i.e, color[i]==c) */
bool isSafe(int v, bool graph[V][V], int color[], int c)
{
	for (int i = 0; i < V; i++)
		if (graph[v][i] && c == color[i])
			return false;
	return true;
}

/* A recursive utility function to solve m coloring problem */
bool graphColoringUtil(bool graph[V][V], int m, int color[], int v)
{
	/* base case: If all vertices are assigned a color then
	   return true */
	if (v == V)
		return true;

	/* Consider this vertex v and try different colors */
	for (int c = 1; c <= m; c++)
	{
		/* Check if assignment of color c to v is fine*/
		if (isSafe(v, graph, color, c))
		{
			color[v] = c;

			/* recur to assign colors to rest of the vertices */
			if (graphColoringUtil(graph, m, color, v + 1) == true)
				return true;

			/* If assigning color c doesn't lead to a solution
			   then remove it */
			color[v] = 0;
		}
	}

	/* If no color can be assigned to this vertex then return false */
	return false;
}

/* This function solves the m Coloring problem using Backtracking.
  It mainly uses graphColoringUtil() to solve the problem. It returns
  false if the m colors cannot be assigned, otherwise return true and
  prints assignments of colors to all vertices. Please note that there
  may be more than one solutions, this function prints one of the
  feasible solutions.*/
bool graphColoring(bool graph[V][V], int m)
{
	// Initialize all color values as 0. This initialization is needed
	// correct functioning of isSafe()
	int *color = new int[V];
	for (int i = 0; i < V; i++)
		color[i] = 0;

	// Call graphColoringUtil() for vertex 0
	if (graphColoringUtil(graph, m, color, 0) == false)
	{
		printf("Solution does not exist");
		return false;
	}

	// Print the solution
	printSolution(color);
	return true;
}

/* A utility function to print solution */
void printSolution(int color[])
{
	cout << "Solution Exists:"
		 << "\nFollowing are the assigned colors\n";
	for (int i = 0; i < V; i++)
		printf(" %d ", color[i]);
	printf(" ");
}

// driver program to test above function
int main()
{
	/* Create following graph and test whether it is 3 colorable
	  (3)---(2)
	   |   / |
	   |  /  |
	   | /   |
	  (0)---(1)
	*/
	bool graph[V][V] = {
		{0, 1, 1, 1},
		{1, 0, 1, 0},
		{1, 1, 0, 1},
		{1, 0, 1, 0},
	};
	int m = 3; // Number of colors
	graphColoring(graph, m);
	return 0;
}
/*
Solution Exists:
Following are the assigned colors
 1  2  3  2
*/