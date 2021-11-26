#include <iostream>
using namespace std;

class Pool
{
private:
    double Length, Width, H;

public:
    Pool(double l = 0, double w = 0, double h = 0) : Length(l), Width(w), H(h) {}
    ~Pool() {}
    double pathArea() { return (2 * (Length + Width) * H + 4 * H * H); }
    double pathCircumference() { return 2 * (Length + 2 * H + Width + 2 * H); }
    double pathCost() { return pathArea() * 40; }
    double fenceCost() { return pathCircumference() * 20; }
};

int main()
{
    double length, width, h;
    cin >> length >> width >> h;
    Pool p(length, width, h);
    cout << "Path cost " << p.pathCost() << " yuan" << endl;
    cout << "Fence cost " << p.fenceCost() << " yuan" << endl;
    return 0;
}