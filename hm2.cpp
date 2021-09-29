#include "Poly.h"

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
    Poly pn1, pn2;
    Mono mn1(1,1), mn2(2, 2), mn3(3, 3);
    pn1 = mn1;
    pn2 = pn1;
    // cout << pn1 << "\n";
    // cout << pn2 << "\n";
    Poly pn3(pn1), pn4, pn5;
    // cout << pn3 << "\n";
    pn2 = pn1 + mn1;
    // cout << pn2 << "\n";
    pn3 = pn2 + mn3;
    // cout << pn2 << "\n";5
    // cout << pn3 << "\n";
    pn2 += mn2;
    // cout << pn2 << "\n";
    pn4 = pn2 + pn3;
    // cout << pn4 << "\n";
    pn4 += pn1;
    // cout << pn4 << "\n";
    pn2 -= pn4;
    cout << pn2 << "\n";

    return 0;
}
