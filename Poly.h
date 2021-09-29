#include "CirList.h"
#include <math.h>
using namespace std;

struct Mono
{
    int exp;
    double coe;
    Mono(int ex = 0, double co = 0) : exp(ex), coe(co) {}
    Mono(const Mono &mn) : exp(mn.exp), coe(mn.coe) {}
    bool sameOrder(const Mono &mn) { return exp == mn.exp; }
    double value(double x) { return pow(x, exp) * coe; }
    Mono &operator=(const Mono &mn)
    {
        exp = mn.exp;
        coe = mn.coe;
        return *this;
    }
    Mono operator+(const Mono &mn) const
    {
        Mono sum = *this;
        if (sum.sameOrder(mn))
            sum.coe += mn.coe;
        return sum;
    }
    Mono &operator+=(const Mono &mn)
    {
        if (this->sameOrder(mn))
            coe += mn.coe;
        return *this;
    }
    Mono operator-(const Mono &mn) const
    {
        Mono sum = *this;
        if (sum.sameOrder(mn))
            sum.coe -= mn.coe;
        return sum;
    }
    Mono &operator-=(const Mono &mn)
    {
        if (this->sameOrder(mn))
            coe -= mn.coe;
        return *this;
    }
    bool operator==(const Mono &mn) { return (exp == mn.exp && coe == mn.coe); }
    bool operator!=(const Mono &mn) { return (exp != mn.exp || coe != mn.coe); }
    friend ostream &operator<<(ostream &out, Mono mn)
    {
        out << " " << mn.coe << "x^" << mn.exp << " ";
        return out;
    }
};

class Poly
{
private:
    CirList<Mono> Polynomial;

public:
    Poly() : Polynomial() {}
    Poly(const Poly &pn)
    {
        Polynomial.Clear();
        for (int i = 0; i < pn.Polynomial.length(); i++)
            Polynomial.append(pn.Polynomial[i]);
    }
    Poly &operator=(const Mono &pn);
    Poly &operator=(const Poly &mn);
    Poly operator+(const Mono mn) const;
    Poly &operator+=(const Mono mn);
    Poly operator+(const Poly &pn) const;
    Poly &operator+=(const Poly &pn);
    Poly operator-(const Mono mn) const;
    Poly &operator-=(const Mono mn);
    Poly operator-(const Poly &pn) const;
    Poly &operator-=(const Poly &pn);
    Poly operator*(Mono mn);
    Poly operator*(const Poly &pn);
    bool operator==(const Poly &pn);
    double value(double x);
    friend ostream &operator<<(ostream &out, Poly &pn);
    Mono &operator[](int pos) { return Polynomial[pos]; }
    const Mono &operator[](int pos) const { return Polynomial[pos]; }
};

Poly &Poly::operator=(const Mono &mn)
{
    Polynomial.Clear();
    Polynomial.append(mn);

    return *this;
}

Poly &Poly::operator=(const Poly &pn)
{
    Polynomial.Clear();
    for (int i = 0; i < pn.Polynomial.length(); i++)
        Polynomial.append(pn[i]);

    return *this;
}

Poly Poly::operator+(const Mono mn) const
{
    Poly sum = *this;
    for (int i = 0; i < sum.Polynomial.length(); ++i)
    {
        Mono &t = sum[i];
        if (t.sameOrder(mn))
        { //合并同类项
            t += mn;
            return sum;
        }
        else if (t.exp > mn.exp)
        { //插入新项
            sum.Polynomial.insert(mn, i);
            return sum;
        }
    }
    sum.Polynomial.append(mn);
    return sum; //追加新项
}

Poly &Poly::operator+=(const Mono mn)
{
    for (int i = 0; i < Polynomial.length(); ++i)
    {
        Mono &t = Polynomial[i];
        if (t.sameOrder(mn))
        { //合并同类项
            t += mn;
            return *this;
        }
        else if (t.exp > mn.exp)
        { //插入新项
            Polynomial.insert(mn, i);
            return *this;
        }
    }
    Polynomial.append(mn);
    return *this; //追加新项
}

Poly Poly::operator+(const Poly &pn) const
{
    Poly sum = *this;
    for (int i = 0; i < pn.Polynomial.length(); i++)
        sum += pn[i];
    return sum;
}

Poly &Poly::operator+=(const Poly &pn)
{
    for (int i = 0; i < pn.Polynomial.length(); i++)
        *this += pn[i];
    return *this;
}

Poly Poly::operator-(const Mono mn) const
{
    Poly sum = *this;
    const Mono zero(mn.exp, 0);
    for (int i = 0; i < sum.Polynomial.length(); ++i)
    {
        Mono &t = sum[i];
        if (t.sameOrder(mn))
        { //合并同类项
            t -= mn;
            if(t.coe == 0)
                sum.Polynomial.remove(t, i);
            return sum;
        }
        else if (t.exp > mn.exp)
        { //插入新项
            sum.Polynomial.insert(zero - mn, i);
            return sum;
        }
    }
    sum.Polynomial.append(zero - mn);
    return sum; //追加新项
}

Poly &Poly::operator-=(const Mono mn)
{
    const Mono zero(mn.exp, 0);
    for (int i = 0; i < Polynomial.length(); ++i)
    {
        Mono &t = Polynomial[i];
        if (t.sameOrder(mn))
        { //合并同类项
            t -= mn;
            if (t.coe == 0)
                Polynomial.remove(t, i);
            return *this;
        }
        else if (t.exp > mn.exp)
        { //插入新项
            Polynomial.insert(zero - mn, i);
            return *this;
        }
    }
    Polynomial.append(zero - mn);
    return *this; //追加新项
}

Poly Poly::operator-(const Poly &pn) const
{
    Poly sum = *this;
    for (int i = 0; i < pn.Polynomial.length(); i++)
        sum -= pn[i];
    return sum;
}

Poly &Poly::operator-=(const Poly &pn)
{
    for (int i = 0; i < pn.Polynomial.length(); i++)
        *this -= pn[i];
    return *this;
}

ostream &operator<<(ostream &out, Poly &pn)
{
    for (int i = 0; i < pn.Polynomial.length(); i++)
        out << pn[i] << "+";
    out << " 0 ";

    return out;
}
