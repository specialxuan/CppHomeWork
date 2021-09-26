#include "CirList.h"

void output(CirList<int> &cl)
{
    for (int i = 0; i < cl.length(); i++)
    {
        cout << cl[i] << ",";
    }
    cout << "end\n";
}

int main ()
{
    CirList<int> cl1;
    cl1.insert(1, 0);
    cl1.insert(3, 1);
    cl1.insert(2, 1);
    cl1.insert(2, 1);
    output(cl1);
    cl1[2] = 3;
    cl1[3] = 4;
    output(cl1);
    cout << cl1[-1] << "\n";

    int rm;

    cout << "Count = " << cl1.remove(rm, 1) << "\n";
    cout << rm << "\n";
    output(cl1);

    cl1.insert(5, 3);

    cl1.append(5);
    output(cl1);

    return 0;
}
