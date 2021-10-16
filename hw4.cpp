#include "AVLTree.h"

int main()
{
    AVLTree<int> tree;
    tree.insert(3);
    tree.insert(4);
    tree.insert(2);
    tree.insert(5);
    tree.insert(7);
    tree.insert(1);
    tree.insert(6);
    tree.insert(8);
    tree.insert(9);
    tree.insert(10);
    tree.insert(11);
    cout << tree << " " << tree.length() << "\n";
    int *array = tree.inOrder();
    for (int i = 0; i < tree.length(); i++)
        cout << array[i] << ",";
    cout << "\n";
    tree.remove(4);
    tree.remove(5);
    tree.remove(6);
    cout << tree << " " << tree.length() << "\n";
    AVLNode<int> *p = tree.search(2);
    cout << p->data << "\n";
    tree.~AVLTree();
    tree.insert(3);
    tree.insert(4);
    tree.insert(2);
    tree.insert(5);
    tree.insert(7);
    tree.insert(1);
    tree.insert(6);
    tree.insert(8);
    tree.insert(9);
    tree.insert(10);
    tree.insert(11);
    cout << tree << " " << tree.length() << "\n";

    return 0;
}