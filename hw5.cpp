#include "AVLTree.h"
#include <algorithm>
#include <list>
#include <set>
#include <time.h>
#include <vector>

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

class SpaceRange
{
protected:
    SpaceNode *nodes;
    AVLTree<cmpNode> x, y, z;

    bool rangeNodeX(const cmpNode &n1, const cmpNode &n2, const AVLNode<cmpNode> *tree, set<int> &id) const;
    bool rangeNodeY(const cmpNode &n1, const cmpNode &n2, const AVLNode<cmpNode> *tree, list<int> &id) const;
    bool rangeNodeZ(const cmpNode &n1, const cmpNode &n2, const AVLNode<cmpNode> *tree, set<int> &id) const;

public:
    SpaceRange() {}
    SpaceRange(int n, double *xn, double *yn, double *zn)
    {
        nodes = new SpaceNode[n]();
        cmpNode tx, ty, tz;
        for (int i = 0; i < n; i++)
        {
            tx.cmp = nodes[i].x = xn[i];
            ty.cmp = nodes[i].y = yn[i];
            tz.cmp = nodes[i].z = zn[i];
            tx.index = ty.index = tz.index = i;
            x.insert(tx);
            y.insert(ty);
            z.insert(tz);
        }
    }
    ~SpaceRange() {}
    int range(double x1, double x2, double y1, double y2, double z1, double z2, list<int> &out)
    {
        if (x1 > x2 || y1 > y2 || z1 > z2)
            return 0;

        list<int> idx, idy, idz, id;

        rangeNodeY(x1, x2, x.pRoot(), idx);
        rangeNodeY(y1, y2, y.pRoot(), idy);
        rangeNodeY(z1, z2, z.pRoot(), idz);

        // cout << idx.size() << " " << idy.size() << " " << idz.size() << endl;

        idx.sort();
        idy.sort();
        idz.sort();

        set_intersection(idx.begin(), idx.end(), idy.begin(), idy.end(), inserter(id, id.begin()));
        set_intersection(id.begin(), id.end(), idz.begin(), idz.end(), insert_iterator<list<int>>(out, out.begin()));

        return out.size();
    }
};

bool SpaceRange::rangeNodeY(const cmpNode &n1, const cmpNode &n2, const AVLNode<cmpNode> *tree, list<int> &id) const
{
    if (!tree)
    {
        return true;
    }
    else if (tree->data < n1)
    {
        rangeNodeY(n1, n2, tree->right, id);
        return true;
    }
    else if (tree->data >= n1 && tree->data <= n2)
    {
        id.push_back(tree->data.index);
        rangeNodeY(n1, n2, tree->left, id);
        rangeNodeY(n1, n2, tree->right, id);
        return true;
    }
    else if (tree->data > n2)
    {
        rangeNodeY(n1, n2, tree->left, id);
        return true;
    }

    return false;
}

int main()
{
    int n = 0, s = 0;
    cin >> n >> s;
    srand(s);
    double *x = new double[n](),
           *y = new double[n](),
           *z = new double[n]();
    for (int i = 0; i < n; i++)
    {
        x[i] = (double)(rand() * rand() % 100000000) / 100000000;
        y[i] = (double)(rand() * rand() % 100000000) / 100000000;
        z[i] = (double)(rand() * rand() % 100000000) / 100000000;
    }
    SpaceRange sr(n, x, y, z);
    cout << "over" << endl;

    double x1, x2, y1, y2, z1, z2;
    cin >> x1 >> x2 >> y1 >> y2 >> z1 >> z2;

    clock_t start = 0, end = 0;
    start = clock();

    list<int> out;
    sr.range(x1, x2, y1, y2, z1, z2, out);
    cout << out.size() << endl;

    end = clock();
    cout << "TIME:" << (double)(end - start) / CLOCKS_PER_SEC << endl;

    // for (int i = 0; i < cnt; i++)
    // {
    //     cout << "(" << x[out[i]] << "," << y[out[i]] << "," << z[out[i]] << ")"  << endl;
    // }

    return 0;
}
