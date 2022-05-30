
#include <iostream>
#include <stdio.h>
#define SIZE 15
#define MAXSIZE 100
using namespace std;

struct PW
{
	float p;
	float w;
};
void DKnap(float p[], float w[], int x[], int n, float m);
int Largest(struct PW pair[], float w[], int t, int h, int i, float m);
void TraceBack(float p[], float w[], struct PW pair[], int b[], int x[], float m, int n);
int binarySearchTuple(struct PW pair[], struct PW tuple, int from, int to);

int main()
{
	float p[] = {0, 1, 2, 5};
	float w[] = {0, 2, 3, 4};
	int x[] = {0, 0, 0, 0};
	float n = 3, m = 6;
	DKnap(p, w, x, n, m);
	// print final solution
	for (int i = 1; i <= n; i++)
	{
		printf("x[%d]: %d\n", i, x[i]);
	}
	return 0;
}

void DKnap(float p[], float w[], int x[], int n, float m)
{
	struct PW pair[SIZE];
	int b[MAXSIZE], next;

	b[0] = 1;
	pair[1].p = pair[1].w = 0.0; // S0
	int t = 1, h = 1;			 // Start and end of S(0)
	b[1] = next = 2;			 // Next free spot in pair[]

	for (int i = 1; i <= n; i++)
	{
		// Generate S(i)
		int k = t;
		int u = Largest(pair, w, t, h, i, m);
		for (int j = t; j <= u; j++)
		{
			// Generate S1(i-1) and merge.
			// (pp, ww) is the next element in S1(i-1)
			float pp = pair[j].p + p[i];
			float ww = pair[j].w + w[i];
			while ((k <= h) && (pair[k].w <= ww))
			{
				pair[next].p = pair[k].p;
				pair[next].w = pair[k].w;
				next++;
				k++;
			}
			if ((k <= h) && (pair[k].w == ww))
			{
				if (pp < pair[k].p)
					pp = pair[k].p;
				k++;
			}
			if (pp > pair[next - 1].p)
			{
				pair[next].p = pp;
				pair[next].w = ww;
				next++;
			}
			while ((k <= h) && (pair[k].p <= pair[next - 1].p))
			{
				k++;
			}
		}
		// Merge in remaining terms from S(i-1)
		while (k <= h)
		{
			pair[next].p = pair[k].p;
			pair[next].w = pair[k].w;
			next++;
			k++;
		}
		// Initialize for S(i+1)
		t = h + 1;
		h = next - 1;
		b[i + 1] = next;
	}
	TraceBack(p, w, pair, b, x, m, n);
}

int Largest(struct PW pair[], float w[], int t, int h, int i, float m)
{
	int q = (t + h) / 2, k = 0;
	while (q != k)
	{
		if (pair[q].w + w[i] > m)
		{
			h = q;
			k = (t + q) / 2 + 1;
		}
		else
		{ // <= m
			t = q;
			k = (q + h) / 2 + 1;
		}
		if (k > h)
			break;
		q = k;
	}
	return q;
}

void TraceBack(float p[], float w[], struct PW pair[], int b[], int x[], float m, int n)
{
	int opt; // optimal tuple index (6, 6)
	for (int i = b[n]; i <= b[n + 1]; i++)
	{ // Takes O(|Sn|) time
		if (pair[i].w > m)
		{
			opt = i - 1;
			break;
		}
	}
	struct PW tuple = pair[opt];
	for (int i = n; i >= 1; i--)
	{ // Takes O(n|Si|) time
		// binary search opt tuple in S(i-1)
		int found = binarySearchTuple(pair, tuple, b[i - 1], b[i]);
		if (found > 0)
		{ // found
			opt = found;
			x[i] = 0;
		}
		else
		{
			x[i] = 1;
			tuple.p = tuple.p - p[i];
			tuple.w = tuple.w - w[i];
		}
	}
}

/**
 * Takes O(log|Si|) time - binary search
 */
int binarySearchTuple(struct PW pair[], struct PW tuple, int from, int to)
{
	int m = (from + to) / 2, k = 0;
	while (m != k)
	{
		if (tuple.p == pair[m].p && tuple.w == pair[m].w)
		{
			return m; // found
		}
		if (pair[m].p < tuple.p)
		{
			to = m;
			k = (m + from) / 2 + 1;
		}
		else
		{ // <= m
			from = m;
			k = (m + to) / 2 + 1;
		}
		m = k;
	}
	return -1; // not found
}