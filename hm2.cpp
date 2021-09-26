#include "CirList.h"

int main ()
{
    CirList<int> cl1, cl2, cl3;
    cl1.insert(1, 0);
    cl1.insert(3, 1);
    cl1.insert(2, 1);
    cl1.insert(2, 1);
    cout << cl1[0] << "\n";
    cout << cl1[1] << "\n";
    cout << cl1[2] << "\n";
    cout << cl1[3] << "\n";
    cl1[2] = 3;
    cl1[3] = 4;
    cout << cl1[0] << "\n";
    cout << cl1[1] << "\n";
    cout << cl1[2] << "\n";
    cout << cl1[3] << "\n";

    return 0;
}