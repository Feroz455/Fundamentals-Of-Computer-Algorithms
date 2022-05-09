/*
 */

// A C++ program to find convex hull of a set of Gpoints. Refer
// https://www.geeksforgeeks.org/orientation-3-ordered-Gpoints/
// for explanation of orientation()
#include <bits/stdc++.h>
#include<algorithm>
// iPair is integer pairs
#define iPair pair<int, int>

// Stores the result (points of convex hull)
set<iPair> hull;
using namespace std;

struct Gpoint
{
    int x, y;
};

// A global Gpoint needed for  sorting Gpoints with reference
// to  the first Gpoint Used in compare function of qsort()
Gpoint p0;

// A utility function to find next to top in a stack
Gpoint nextToTop(stack<Gpoint> &S)
{
    Gpoint p = S.top();
    S.pop();
    Gpoint res = S.top();
    S.push(p);
    return res;
}

// A utility function to swap two Gpoints
void swap(Gpoint &p1, Gpoint &p2)
{
    Gpoint temp = p1;
    p1 = p2;
    p2 = temp;
}

// A utility function to return square of distance
// between p1 and p2
int distSq(Gpoint p1, Gpoint p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) +
           (p1.y - p2.y) * (p1.y - p2.y);
}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are collinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Gpoint p, Gpoint q, Gpoint r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0)
        return 0;             // collinear
    return (val > 0) ? 1 : 2; // clock or counterclock wise
}

// A function used by library function qsort() to sort an array of
// Gpoints with respect to the first Gpoint
int compare(const void *vp1, const void *vp2)
{
    Gpoint *p1 = (Gpoint *)vp1;
    Gpoint *p2 = (Gpoint *)vp2;

    // Find orientation
    int o = orientation(p0, *p1, *p2);
    if (o == 0)
        return (distSq(p0, *p2) >= distSq(p0, *p1)) ? -1 : 1;

    return (o == 2) ? -1 : 1;
}

// Prints convex hull of a set of n Gpoints.
void convexHull(Gpoint Gpoints[], int n)
{
    // Find the bottommost Gpoint
    int ymin = Gpoints[0].y, min = 0;
    for (int i = 1; i < n; i++)
    {
        int y = Gpoints[i].y;

        // Pick the bottom-most or chose the left
        // most Gpoint in case of tie
        if ((y < ymin) || (ymin == y &&
                           Gpoints[i].x < Gpoints[min].x))
            ymin = Gpoints[i].y, min = i;
    }

    // Place the bottom-most Gpoint at first position
    swap(Gpoints[0], Gpoints[min]);

    // Sort n-1 Gpoints with respect to the first Gpoint.
    // A Gpoint p1 comes before p2 in sorted output if p2
    // has larger polar angle (in counterclockwise
    // direction) than p1
    p0 = Gpoints[0];
    qsort(&Gpoints[1], n - 1, sizeof(Gpoint), compare);

    // If two or more Gpoints make same angle with p0,
    // Remove all but the one that is farthest from p0
    // Remember that, in above sorting, our criteria was
    // to keep the farthest Gpoint at the end when more than
    // one Gpoints have same angle.
    int m = 1; // Initialize size of modified array
    for (int i = 1; i < n; i++)
    {
        // Keep removing i while angle of i and i+1 is same
        // with respect to p0
        while (i < n - 1 && orientation(p0, Gpoints[i],
                                        Gpoints[i + 1]) == 0)
            i++;

        Gpoints[m] = Gpoints[i];
        m++; // Update size of modified array
    }

    // If modified array of Gpoints has less than 3 Gpoints,
    // convex hull is not possible
    if (m < 3)
        return;

    // Create an empty stack and push first three Gpoints
    // to it.
    stack<Gpoint> S;
    S.push(Gpoints[0]);
    S.push(Gpoints[1]);
    S.push(Gpoints[2]);

    // Process remaining n-3 Gpoints
    for (int i = 3; i < m; i++)
    {
        // Keep removing top while the angle formed by
        // Gpoints next-to-top, top, and Gpoints[i] makes
        // a non-left turn
        while (S.size() > 1 && orientation(nextToTop(S), S.top(), Gpoints[i]) != 2)
            S.pop();
        S.push(Gpoints[i]);
    }

    // Now stack has the output Gpoints, print contents of stack
    while (!S.empty())
    {
        Gpoint p = S.top();
        cout << "(" << p.x << ", " << p.y << ")" << endl;
        S.pop();
    }
}

// Returns the side of point p with respect to line
// joining points p1 and p2.
int findSide(iPair p1, iPair p2, iPair p)
{
    int val = (p.second - p1.second) * (p2.first - p1.first) -
              (p2.second - p1.second) * (p.first - p1.first);

    if (val > 0)
        return 1;
    if (val < 0)
        return -1;
    return 0;
}

// returns a value proportional to the distance
// between the point p and the line joining the
// points p1 and p2
int lineDist(iPair p1, iPair p2, iPair p)
{
    return abs((p.second - p1.second) * (p2.first - p1.first) -
               (p2.second - p1.second) * (p.first - p1.first));
}

// End points of line L are p1 and p2.  side can have value
// 1 or -1 specifying each of the parts made by the line L
void quickHull(iPair a[], int n, iPair p1, iPair p2, int side)
{
    int ind = -1;
    int max_dist = 0;

    // finding the point with maximum distance
    // from L and also on the specified side of L.
    for (int i = 0; i < n; i++)
    {
        int temp = lineDist(p1, p2, a[i]);
        if (findSide(p1, p2, a[i]) == side && temp > max_dist)
        {
            ind = i;
            max_dist = temp;
        }
    }

    // If no point is found, add the end points
    // of L to the convex hull.
    if (ind == -1)
    {
        hull.insert(p1);
        hull.insert(p2);
        return;
    }

    // Recur for the two parts divided by a[ind]
    quickHull(a, n, a[ind], p1, -findSide(a[ind], p1, p2));
    quickHull(a, n, a[ind], p2, -findSide(a[ind], p2, p1));
}

void printHull(iPair a[], int n)
{
    // a[i].second -> y-coordinate of the ith point
    if (n < 3)
    {
        cout << "Convex hull not possible\n";
        return;
    }
    //  {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    // Finding the point with minimum and
    // maximum x-coordinate
    int min_x = 0, max_x = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i].first < a[min_x].first)
            min_x = i;
        if (a[i].first > a[max_x].first)
            max_x = i;
    }

    // Recursively find convex hull points on
    // one side of line joining a[min_x] and
    // a[max_x]
    quickHull(a, n, a[min_x], a[max_x], 1);

    // Recursively find convex hull points on
    // other side of line joining a[min_x] and
    // a[max_x]
    quickHull(a, n, a[min_x], a[max_x], -1);

    cout << "The points in Convex Hull are:\n";
    while (!hull.empty())
    {
        cout << "(" << (*hull.begin()).first << ", "
             << (*hull.begin()).second << ") ";
        hull.erase(hull.begin());
    }
}
pair<int, int> mid;

// determines the quadrant of a point
// (used in compare())
int quad(pair<int, int> p)
{
    if (p.first >= 0 && p.second >= 0)
        return 1;
    if (p.first <= 0 && p.second >= 0)
        return 2;
    if (p.first <= 0 && p.second <= 0)
        return 3;
    return 4;
}

// Checks whether the line is crossing the polygon
int orientation(pair<int, int> a, pair<int, int> b,
                pair<int, int> c)
{
    int res = (b.second - a.second) * (c.first - b.first) -
              (c.second - b.second) * (b.first - a.first);

    if (res == 0)
        return 0;
    if (res > 0)
        return 1;
    return -1;
}

// compare function for sorting
bool compare(pair<int, int> p1, pair<int, int> q1)
{
    pair<int, int> p = make_pair(p1.first - mid.first,
                                 p1.second - mid.second);
    pair<int, int> q = make_pair(q1.first - mid.first,
                                 q1.second - mid.second);

    int one = quad(p);
    int two = quad(q);

    if (one != two)
        return (one < two);
    return (p.second * q.first < q.second * p.first);
}

// Finds upper tangent of two polygons 'a' and 'b'
// represented as two vectors.
vector<pair<int, int>> merger(vector<pair<int, int>> a,
                              vector<pair<int, int>> b)
{
    // n1 -> number of points in polygon a
    // n2 -> number of points in polygon b
    int n1 = a.size(), n2 = b.size();

    int ia = 0, ib = 0;
    for (int i = 1; i < n1; i++)
        if (a[i].first > a[ia].first)
            ia = i;

    // ib -> leftmost point of b
    for (int i = 1; i < n2; i++)
        if (b[i].first < b[ib].first)
            ib = i;

    // finding the upper tangent
    int inda = ia, indb = ib;
    bool done = 0;
    while (!done)
    {
        done = 1;
        while (orientation(b[indb], a[inda], a[(inda + 1) % n1]) >= 0)
            inda = (inda + 1) % n1;

        while (orientation(a[inda], b[indb], b[(n2 + indb - 1) % n2]) <= 0)
        {
            indb = (n2 + indb - 1) % n2;
            done = 0;
        }
    }

    int uppera = inda, upperb = indb;
    inda = ia, indb = ib;
    done = 0;
    int g = 0;
    while (!done) // finding the lower tangent
    {
        done = 1;
        while (orientation(a[inda], b[indb], b[(indb + 1) % n2]) >= 0)
            indb = (indb + 1) % n2;

        while (orientation(b[indb], a[inda], a[(n1 + inda - 1) % n1]) <= 0)
        {
            inda = (n1 + inda - 1) % n1;
            done = 0;
        }
    }

    int lowera = inda, lowerb = indb;
    vector<pair<int, int>> ret;

    // ret contains the convex hull after merging the two convex hulls
    // with the points sorted in anti-clockwise order
    int ind = uppera;
    ret.push_back(a[uppera]);
    while (ind != lowera)
    {
        ind = (ind + 1) % n1;
        ret.push_back(a[ind]);
    }

    ind = lowerb;
    ret.push_back(b[lowerb]);
    while (ind != upperb)
    {
        ind = (ind + 1) % n2;
        ret.push_back(b[ind]);
    }
    return ret;
}

// Brute force algorithm to find convex hull for a set
// of less than 6 points
vector<pair<int, int>> bruteHull(vector<pair<int, int>> a)
{
    // Take any pair of points from the set and check
    // whether it is the edge of the convex hull or not.
    // if all the remaining points are on the same side
    // of the line then the line is the edge of convex
    // hull otherwise not
    set<pair<int, int>> s;

    for (int i = 0; i < a.size(); i++)
    {
        for (int j = i + 1; j < a.size(); j++)
        {
            int x1 = a[i].first, x2 = a[j].first;
            int y1 = a[i].second, y2 = a[j].second;

            int a1 = y1 - y2;
            int b1 = x2 - x1;
            int c1 = x1 * y2 - y1 * x2;
            int pos = 0, neg = 0;
            for (int k = 0; k < a.size(); k++)
            {
                if (a1 * a[k].first + b1 * a[k].second + c1 <= 0)
                    neg++;
                if (a1 * a[k].first + b1 * a[k].second + c1 >= 0)
                    pos++;
            }
            if (pos == a.size() || neg == a.size())
            {
                s.insert(a[i]);
                s.insert(a[j]);
            }
        }
    }

    vector<pair<int, int>> ret;
    for (auto e : s)
        ret.push_back(e);

    // Sorting the points in the anti-clockwise order
    mid = {0, 0};
    int n = ret.size();
    for (int i = 0; i < n; i++)
    {
        mid.first += ret[i].first;
        mid.second += ret[i].second;
        ret[i].first *= n;
        ret[i].second *= n;
    }
    sort(ret.begin(), ret.end(), compare);
    for (int i = 0; i < n; i++)
        ret[i] = make_pair(ret[i].first / n, ret[i].second / n);

    return ret;
}

// Returns the convex hull for the given set of points
vector<pair<int, int>> divide(vector<pair<int, int>> a)
{
    // If the number of points is less than 6 then the
    // function uses the brute algorithm to find the
    // convex hull
    if (a.size() <= 5)
        return bruteHull(a);

    // left contains the left half points
    // right contains the right half points
    vector<pair<int, int>> left, right;
    for (int i = 0; i < a.size() / 2; i++)
        left.push_back(a[i]);
    for (int i = a.size() / 2; i < a.size(); i++)
        right.push_back(a[i]);

    // convex hull for the left and right sets
    vector<pair<int, int>> left_hull = divide(left);
    vector<pair<int, int>> right_hull = divide(right);

    // merging the convex hulls
    return merger(left_hull, right_hull);
}
/*
 */