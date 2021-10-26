#include "AVLTree.h"
#include <time.h>

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

class SpaceRange : protected AVLTree<cmpNode>
{
protected:
    SpaceNode *nodes;

    bool rangeNodeX(const cmpNode &n1, const cmpNode &n2, const AVLNode<cmpNode> *tree, AVLTree<cmpNode> &y) const;
    bool rangeNodeY(const cmpNode &n1, const cmpNode &n2, const AVLNode<cmpNode> *tree, AVLTree<cmpNode> &z) const;
    bool rangeNodeZ(const cmpNode &n1, const cmpNode &n2, const AVLNode<cmpNode> *tree, AVLTree<int> &id) const;

public:
    SpaceRange() {}
    SpaceRange(int n, double *x, double *y, double *z)
    {
        nodes = new SpaceNode[n]();
        cmpNode t;
        for (int i = 0; i < n; i++)
        {
            nodes[i].x = x[i];
            nodes[i].y = y[i];
            nodes[i].z = z[i];
            t.cmp = x[i];
            t.index = i;
            this->insert(t);
        }
    }
    ~SpaceRange() {}
    int range(double x1, double x2, double y1, double y2, double z1, double z2, int *&out)
    {
        if (x1 > x2 || y1 > y2 || z1 > z2)
            return 0;

        AVLTree<cmpNode> y, z;
        AVLTree<int> id;
        rangeNodeX(x1, x2, root, y);
        rangeNodeY(y1, y2, y.pRoot(), z);
        rangeNodeZ(z1, z2, z.pRoot(), id);

        out = id.inOrder();
        return id.length();
    }

    friend ostream &operator<<(ostream &out, const SpaceRange &pn)
    {
        if (pn.root)
            out << *pn.root;
        return out;
    }
};

bool SpaceRange::rangeNodeX(const cmpNode &n1, const cmpNode &n2, const AVLNode<cmpNode> *tree, AVLTree<cmpNode> &y) const
{
    if (!tree)
    {
        return true;
    }
    else if (tree->data < n1)
    {
        rangeNodeX(n1, n2, tree->right, y);
        return true;
    }
    else if (tree->data >= n1 && tree->data <= n2)
    {
        cmpNode t(nodes[tree->data.index].y, tree->data.index);
        y.insert(t);
        rangeNodeX(n1, n2, tree->left, y);
        rangeNodeX(n1, n2, tree->right, y);
        return true;
    }
    else if (tree->data > n2)
    {
        rangeNodeX(n1, n2, tree->left, y);
        return true;
    }

    return false;
}

bool SpaceRange::rangeNodeY(const cmpNode &n1, const cmpNode &n2, const AVLNode<cmpNode> *tree, AVLTree<cmpNode> &z) const
{
    if (!tree)
    {
        return true;
    }
    else if (tree->data < n1)
    {
        rangeNodeY(n1, n2, tree->right, z);
        return true;
    }
    else if (tree->data >= n1 && tree->data <= n2)
    {
        cmpNode t(nodes[tree->data.index].z, tree->data.index);
        z.insert(t);
        rangeNodeY(n1, n2, tree->left, z);
        rangeNodeY(n1, n2, tree->right, z);
        return true;
    }
    else if (tree->data > n2)
    {
        rangeNodeY(n1, n2, tree->left, z);
        return true;
    }

    return false;
}

bool SpaceRange::rangeNodeZ(const cmpNode &n1, const cmpNode &n2, const AVLNode<cmpNode> *tree, AVLTree<int> &id) const
{
    if (!tree)
    {
        return true;
    }
    else if (tree->data < n1)
    {
        rangeNodeZ(n1, n2, tree->right, id);
        return true;
    }
    else if (tree->data >= n1 && tree->data <= n2)
    {
        id.insert(tree->data.index);
        rangeNodeZ(n1, n2, tree->left, id);
        rangeNodeZ(n1, n2, tree->right, id);
        return true;
    }
    else if (tree->data > n2)
    {
        rangeNodeZ(n1, n2, tree->left, id);
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
        x[i] = (int)rand();
        y[i] = (int)rand();
        z[i] = (int)rand();
    }

    double x1, x2, y1, y2, z1, z2;
    cin >> x1 >> x2 >> y1 >> y2 >> z1 >> z2;

    clock_t start = 0, end = 0;
    start = clock();
    SpaceRange sr(n, x, y, z);

    int *out = NULL, cnt = 0;
    cnt = sr.range(x1, x2, y1, y2, z1, z2, out);

    end = clock();
    cout << "TIME:\n"
         << (double)(end - start) / CLOCKS_PER_SEC << endl;

    // for (int i = 0; i < cnt; i++)
    // {
    //     cout << "(" << x10[out[i]] << "," << y[out[i]] << "," << z[out[i]] << ")"  << endl;
    // }

    return 0;
}

