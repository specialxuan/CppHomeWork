#include "Set.h"

void output(Set<int> &set)
{
    int output = 0;
    for (int i = 0; i < set.length(); i++)
    {
        set.getData(output, i);
        cout << output << ",";
    }
    cout << "\n";
}

int main(int argc, char *argv[])
{
    int input = 0;
    char ope;
    Set<int> set1, set2, set3;

    cout << "Input elements of set 1, end with -1\n";
    cin >> input;
    while (input != -1)
    {
        set1.append(input);
        cin >> input;
    }
    cout << "Input elements of set 2, end with -1\n";
    cin >> input;
    while (input != -1)
    {
        set2.append(input);
        cin >> input;
    }
    cout << "Input operator in \'+\' \'-\' \'^\' \n";
    cin >> ope;

    if (ope == '+')
        set3 = set1 + set2;
    else if (ope == '-')
        set3 = set1 - set2;
    else if (ope == '^')
        set3 = set1 ^ set2;

    output(set1);
    output(set2);
    output(set3);

    return 0;
}
