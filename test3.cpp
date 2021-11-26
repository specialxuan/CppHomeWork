#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int m, n[4], ascend, descend, latest, previous;
    while (true)
    {
        cout << "Input a integer between 1000 and 9999 (not all digits are the same)" << endl;
        cin >> m;
        if (m < 1000 || m > 9999)
            continue;

        n[0] = m % 10;
        n[1] = (m / 10) % 10;
        n[2] = (m / 100) % 10;
        n[3] = (m / 1000) % 10;
        if (n[0] - n[1] || n[1] - n[2] || n[2] - n[3])
            break;
    }
    while (true)
    {
        sort(n, n + 4);
        ascend = n[0] * 1000 + n[1] * 100 + n[2] * 10 + n[3];
        descend = n[0] + n[1] * 10 + n[2] * 100 + n[3] * 1000;
        latest = descend - ascend;

        if (latest == previous)
            break;

        previous = latest;
        n[0] = latest % 10;
        n[1] = (latest / 10) % 10;
        n[2] = (latest / 100) % 10;
        n[3] = (latest / 1000) % 10;
    }
    cout << "The digital black hole is " << latest << endl;
    return 0;
}