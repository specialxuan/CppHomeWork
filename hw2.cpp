#include "Poly.h"

int main()
{
    Poly pn1, pn2;
    Mono mn1(1, 1), mn2(2, 2), mn3(3, 3);
    pn1 += mn1;
    pn2 = pn1;
    Poly pn3(pn1), pn4, pn5;
    pn2 = pn1 + mn1;
    pn3 = pn2 + mn3;
    pn2 += mn2;
    pn4 = pn2 + pn3;
    pn4 += pn1;
    pn2 -= pn4;
    pn4 = pn2 * pn3;
    cout << "pn1 = " << pn1 << endl;
    cout << "pn2 = " << pn2 << endl;
    cout << "pn3 = " << pn3 << endl;
    cout << "pn4 = " << pn4 << endl;
    pn2 = pn4;
    cout << (pn4 == pn2) << endl;
    cout << pn4.value(1) << endl;
    return 0;
}
