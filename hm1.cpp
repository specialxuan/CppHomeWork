// #include "LinkList.h"
#include "Set.h"

void output(Set<int> &set)
{
    int output = 0;
    for (int i = 0; i < set.length(); i++)
    {
        set.getData(output, i);
        cout << output << ",";
    }
    cout << "**\n";
}

int main(int argc, char *argv[])
{
    // LinkList<int> list1, list2, list3;
    // list1.insert(3, 0);
    // list1.append(4);
    // list1.insert(1, 0);
    // list1.insert(2, 1);
    // // list1.insert(5, 3);
    // int output = 0;
    // for (int i = 0; i < 4; i++)
    // {
    //     list1.getData(output, i);
    //     cout << output << ",";
    // }
    // list1.remove(output, 3);
    // cout << "\n"
    //      << output << "\n";
    // for (int i = 0; i < 4; i++)
    // {
    //     list1.getData(output, i);
    //     cout << output << ",";
    // }
    // cout << "\n";
    // list1.append(5);
    // for (int i = 0; i < 4; i++)
    // {
    //     list1.getData(output, i);
    //     cout << output << ",";
    // }
    // cout << "\n";
    // list1.setData(4, 3);
    // for (int i = 0; i < 4; i++)
    // {
    //     list1.getData(output, i);
    //     cout << output << ",";
    // }
    // cout << "\n";
    // list1.remove(output, 3);
    // cout << "\n"
    //      << output << "\n";
    // for (int i = 0; i < 4; i++)
    // {
    //     list1.getData(output, i);
    //     cout << output << ",";
    // }
    // cout << "\n";
    // list2.append(5);
    // Set<int> set1, set2, set3, set4;
    // set1.append(1);
    // set1.append(2);
    // set1.append(3);
    // cout << set1.ifExist(1) << "\n";
    // cout << set1.ifExist(2) << "\n";
    // cout << set1.ifExist(3) << "\n";
    // cout << set1.ifExist(4) << "\n";
    // cout << set1.append(4) << "\n";
    // cout << set1.append(5) << "\n";
    // cout << set1.append(6) << "\n";
    // cout << set1.append(7) << "\n";
    // cout << set1.append(1) << "\n";
    // cout << set2.append(6) << "\n";
    // cout << set2.append(8) << "\n";
    // cout << set2.append(2) << "\n";
    // cout << set2.append(10) << "\n";
    // set3 = set1 + set2;
    // output(set1);
    // output(set2);
    // output(set3);
    // // set3.clear();
    // // set3.append(10);
    // set3 = set3 - set2;
    // set4 = set1 ^ set2;
    // // cout << set3.erase(4) << "\n";
    // output(set3);
    // output(set4);
    // // cout << set3.erase(10) << "\n";

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
    {
        set3 = set1 + set2;
    }
    else if (ope == '-')
    {
        set3 = set1 - set2;
    }
    else if (ope == '^')
    {
        set3 = set1 ^ set2;
    }

    output(set1);
    output(set2);
    output(set3);

    return 0;
}
