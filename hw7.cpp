#include <iostream>
#include <algorithm>
#include <set>
#include <time.h>
#include <vector>
using namespace std;

struct cmpNode
{
    double cmp;
    int index;
    cmpNode(double c = 0, int i = 0) : cmp(c), index(i) {}
    inline bool operator<(const cmpNode &n) const { return (cmp < n.cmp); }
    inline bool operator<=(const cmpNode &n) const { return (cmp <= n.cmp); }
    inline bool operator>(const cmpNode &n) const { return (cmp > n.cmp); }
    inline bool operator>=(const cmpNode &n) const { return (cmp >= n.cmp); }
    inline bool operator==(const cmpNode &n) const { return (cmp == n.cmp); }
    inline bool operator!=(const cmpNode &n) const { return (cmp != n.cmp); }
    friend ostream &operator<<(ostream &out, const cmpNode &pn)
    {
        out << pn.cmp;
        return out;
    }
};

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

int main()
{
    int n = 0, s = 0;
    cin >> n >> s;
    srand(s);

    cmpNode *x = new cmpNode[n](),
            *y = new cmpNode[n](),
            *z = new cmpNode[n]();

    for (int i = 0; i < n; i++)
    {
        x[i].cmp = rand();
        y[i].cmp = rand();
        z[i].cmp = rand();
        x[i].index = y[i].index = z[i].index = i;
    }
    set<cmpNode> xSet(x, x + n), ySet(y, y + n), zSet(z, z + n), id;
    set<cmpNode>::iterator px1, px2, py1, py2, pz1, pz2;

    cmpNode x1, x2, y1, y2, z1, z2;
    cin >> x1.cmp >> x2.cmp >> y1.cmp >> y2.cmp >> z1.cmp >> z2.cmp;

    clock_t start = 0, end = 0;
    start = clock();
    px1 = xSet.lower_bound(x1);
    px2 = xSet.lower_bound(x2);
    py1 = ySet.lower_bound(y1);
    py2 = ySet.lower_bound(y2);
    pz1 = zSet.lower_bound(z1);
    pz2 = zSet.lower_bound(z2);

    vector<int> out;
    set_intersection(px1, px2, py1, py2, inserter(id, id.begin()));
    set_intersection(id.begin(), id.end(), pz1, pz2, insert_iterator<vector<int>>(out, out.begin()));

    int cnt = out.size();
    // cout << cnt << endl;

    end = clock();
    cout << "TIME:\n"
         << (double)(end - start) / CLOCKS_PER_SEC << endl;

    for (int i = 0; i < cnt; i++)
    {
        cout << "(" << x[out[i]] << "," << y[out[i]] << "," << z[out[i]] << ")"  << endl;
    }

    return 0;
}
