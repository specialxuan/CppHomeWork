#include <algorithm>
#include <iostream>
#include <time.h>
using namespace std;

struct SpaceNode
{
    double x, y, z;
    SpaceNode(double X = 0, double Y = 0, double Z = 0) : x(X), y(Y), z(Z) {}
    friend ostream &operator<<(ostream &out, const SpaceNode &pn)
    {
        out << "(" << pn.x << "," << pn.y << "," << pn.z << ")";
        return out;
    }
};

bool cmpX(const SpaceNode &n1, const SpaceNode &n2) { return n1.x < n2.x; }

bool cmpY(const SpaceNode &n1, const SpaceNode &n2) { return n1.y < n2.y; }

bool cmpZ(const SpaceNode &n1, const SpaceNode &n2) { return n1.z < n2.z; }

int main()
{
    int n = 0, s = 0;
    cin >> n >> s;
    srand(s);
    SpaceNode *nodes = new SpaceNode[n](), *p1 = nodes, *p2 = nodes + n;
    for (int i = 0; i < n; i++)
    {
        nodes[i].x = rand();
        nodes[i].y = rand();
        nodes[i].z = rand();
    }

    SpaceNode n1, n2;
    cin >> n1.x >> n2.x >> n1.y >> n2.y >> n1.z >> n2.z;

    clock_t start = 0, end = 0;
    start = clock();

    if (p2 >= p1)
    {
        sort(p1, p2, cmpX);
        p1 = lower_bound(p1, p2, n1, cmpX);
        p2 = upper_bound(p1, p2, n2, cmpX);
    }

    if (p2 >= p1)
    {
        sort(p1, p2, cmpY);
        p1 = lower_bound(p1, p2, n1, cmpY);
        p2 = upper_bound(p1, p2, n2, cmpY);
    }

    if (p2 >= p1)
    {
        sort(p1, p2, cmpZ);
        p1 = lower_bound(p1, p2, n1, cmpZ);
        p2 = upper_bound(p1, p2, n2, cmpZ);
    }

    end = clock();
    cout << "TIME:\n" << (double)(end - start) / CLOCKS_PER_SEC << endl;

    // for (SpaceNode *i = p1; i < p2; i++)
    // {
    //     cout << *i << endl;
    // }

    return 0;
}
