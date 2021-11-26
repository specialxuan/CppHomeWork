#include <iostream>
using namespace std;

struct femNode
{
    double x, y;
    double m, v;

    femNode(double ix = 0, double iy = 0, double im = 0, double iv = 0) : x(ix), y(iy), m(im), v(iv) {}
};

class femNodeMat
{
private:
    int m, n;
    femNode **p;

public:
    femNodeMat(int im = 0, int in = 0) : m(im), n(in)
    {
        if (m && n)
        {
            p = new femNode *[m]();
            for (int i = 0; i < m; i++)
                p[i] = new femNode[n]();
        }
    }
    ~femNodeMat()
    {
        for (int i = 0; i < m; i++)
            delete[] p[i];
        delete[] p;
        m = n = 0;
    }
    femNode *operator[](int pos)
    {
        if (pos >= m)
            return p[0];
        else
            return p[pos];
    }
    const femNode *operator[](int pos) const
    {
        if (pos >= m)
            return p[0];
        else
            return p[pos];
    }
};

int main()
{
    int m, n;
    cin >> m >> n;
    femNodeMat Matrix(m, n);
    cout << Matrix[2][3].x << endl;
    return 0;
}