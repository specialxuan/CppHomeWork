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
        nodes[i].x = (int)rand();
        nodes[i].y = (int)rand();
        nodes[i].z = (int)rand();
    }

    double x1, x2, y1, y2, z1, z2;
    cin >> x1 >> x2 >> y1 >> y2 >> z1 >> z2;
    SpaceNode n1(x1, y1, z1), n2(x2, y2, z2);

    clock_t start = 0, end = 0;
    start = clock();

    if (p2 >= p1)
    {
        sort(p1, p2, cmpX);
        // for (int i = 0; i < n; i++)
        // {
        //     cout << nodes[i];
        // }
        // cout << endl;
        p1 = lower_bound(p1, p2, n1, cmpX);
        p2 = upper_bound(p1, p2, n2, cmpX);
        // p2--;
    }

    if (p2 >= p1)
    {
        sort(p1, p2, cmpY);
        // for (int i = 0; i < n; i++)
        // {
        //     cout << nodes[i];
        // }
        // cout << endl;
        p1 = lower_bound(p1, p2, n1, cmpY);
        p2 = upper_bound(p1, p2, n2, cmpY);
        // p2--;
    }

    if (p2 >= p1)
    {
        sort(p1, p2, cmpZ);
        // for (int i = 0; i < n; i++)
        // {
        //     cout << nodes[i];
        // }
        // cout << endl;
        p1 = lower_bound(p1, p2, n1, cmpZ);
        p2 = upper_bound(p1, p2, n2, cmpZ);
        // p2--;
    }

    end = clock();
    cout << "TIME:\n"
         << (double)(end - start) / CLOCKS_PER_SEC << endl;

    // for (SpaceNode *i = p1; i < p2; i++)
    // {
    //     cout << *i << endl;
    // }

    return 0;
}
