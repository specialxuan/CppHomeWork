#include <algorithm>
#include <iostream>
#include "LinkList.h"
using namespace std;

int greedy(int total, int thisKinds, int totalKinds, int *each, int *num, LinkList<int *> &solutions)
{
    if (total <= 0 || thisKinds <= 0 || each == NULL || num == NULL)
        return 0;

    int count = 0, n = total / each[thisKinds - 1];

    if (total % each[thisKinds - 1] == 0)
    {
        num[thisKinds - 1] = n;
        int *newnum = new int(totalKinds);
        memcpy(newnum, num, totalKinds * sizeof(int));

        solutions.append(newnum);
        count++;
    }
    for (; n >= 0; n--)
    {
        num[thisKinds - 1] = n;
        count += greedy(total - each[thisKinds - 1] * n, thisKinds - 1, totalKinds, each, num, solutions);
    }
    
    return count;
}

int main()
{
    int total, kinds, *each, *num;
    LinkList<int *> solutions;

    cout << "total, kinds, each\n";
    cin >> total >> kinds;
    each = new int[kinds]();
    num = new int[kinds]();
    for (int i = 0; i < kinds; i++)
        cin >> each[i];
    sort(each, each + kinds);

    greedy(total, kinds, kinds, each, num, solutions);

    cout << solutions.length() << "\n";
    for (int i = 0; i < solutions.length(); i++)
    {
        for (int j = 0; j < kinds; j++)
            cout << solutions[i][j] << ",";
        cout << "\n";
    }

    return 0;
}