#include <iostream>
using namespace std;

template <class T>
struct AVLNode
{
    T data;
    int height;
    AVLNode<T> *left, *right;
    AVLNode() : height(0), left(NULL), right(NULL) {}
    AVLNode(T d, AVLNode<T> *l = 0, AVLNode<T> *r = 0) : data(d), height(0), left(l), right(r) {}
    friend ostream &operator<<(ostream &out, const AVLNode<T> &pn)
    {
        out << pn.data;
        if (pn.left == NULL && pn.right == NULL)
            return out;
        else
        {
            out << "{";
            if (pn.left)
                out << *pn.left;
            out << ",";
            if (pn.right)
                out << *pn.right;
            out << "}";
        }
        return out;
    }
};

template <class T>
class AVLTree
{
protected:
    AVLNode<T> *root;
    int count;
    int updateHeight(AVLNode<T> *&tree);
    int balance(AVLNode<T> *&tree);
    void rotateLeft(AVLNode<T> *&tree);
    void rotateRight(AVLNode<T> *&tree);
    bool insertNode(const T &x, AVLNode<T> *&tree);
    bool removeNode(const T &x, AVLNode<T> *&tree);
    void itInOrder(T *array, AVLNode<T> *tree, int &i) const;
    AVLNode<T> *searchNode(const T &key, AVLNode<T> *tree) const;
    void clear(AVLNode<T> *&tree);

public:
    AVLTree() : root(NULL), count(0) {}
    ~AVLTree() { clear(root); }
    bool insert(const T &x) { return insertNode(x, root); }
    bool remove(const T &x) { return removeNode(x, root); }
    AVLNode<T> *search(const T &key) const { return searchNode(key, root); }
    int length() const { return count; }
    T *inOrder() const
    {
        T *array = new T[count]();
        int i = 0;
        itInOrder(array, root, i);
        return array;
    }
    friend ostream &operator<<(ostream &out, const AVLTree<T> &pn)
    {
        if (pn.root)
            out << *pn.root;
        return out;
    }
};

template <class T>
int AVLTree<T>::updateHeight(AVLNode<T> *&tree)
{
    int h1 = tree->left ? tree->left->height : -1;
    int h2 = tree->right ? tree->right->height : -1;
    tree->height = h1 > h2 ? h1 + 1 : h2 + 1;
    return tree->height;
}

template <class T>
int AVLTree<T>::balance(AVLNode<T> *&tree)
{
    int h1 = tree->left ? tree->left->height : -1;
    int h2 = tree->right ? tree->right->height : -1;
    return h2 - h1;
}

template <class T>
void AVLTree<T>::rotateLeft(AVLNode<T> *&tree)
{
    if (!tree || !tree->right)
        return;

    AVLNode<T> *t = tree->right;
    tree->right = t->left;
    t->left = tree;
    tree = t;
    updateHeight(tree->left);
    updateHeight(tree);
}

template <class T>
void AVLTree<T>::rotateRight(AVLNode<T> *&tree)
{
    if (!tree || !tree->left)
        return;

    AVLNode<T> *t = tree->left;
    tree->left = t->right;
    t->right = tree;
    tree = t;
    updateHeight(tree->right);
    updateHeight(tree);
}

template <class T>
bool AVLTree<T>::insertNode(const T &x, AVLNode<T> *&tree)
{
    if (!tree)
    {
        tree = new AVLNode<T>(x);
        if (tree)
        {
            count++;
            return true;
        }
        return false;
    }

    if (x < tree->data)
    {
        if (insertNode(x, tree->left))
        {
            if (balance(tree) >= -1)
                updateHeight(tree);
            else
            {
                if (balance(tree->left) > 0)
                    rotateLeft(tree->left);
                rotateRight(tree);
            }
            return true;
        }
    }
    else if (x > tree->data)
    {
        if (insertNode(x, tree->right))
        {
            if (balance(tree) <= 1)
                updateHeight(tree);
            else
            {
                if (balance(tree->right) < 0)
                    rotateRight(tree->right);
                rotateLeft(tree);
            }
            return true;
        }
    }
    return false;
}

template <class T>
bool AVLTree<T>::removeNode(const T &x, AVLNode<T> *&tree)
{
    if (!tree)
        return false;

    if (x < tree->data)
    {
        if (removeNode(x, tree->left))
        {
            if (balance(tree) <= 1)
                updateHeight(tree);
            else
            {
                if (balance(tree->right) < 0)
                    rotateRight(tree->right);
                rotateLeft(tree);
            }
            return true;
        }
    }
    else if (x > tree->data)
    {
        if (removeNode(x, tree->right))
        {
            if (balance(tree) >= -1)
                updateHeight(tree);
            else
            {
                if (balance(tree->left) > 0)
                    rotateLeft(tree->left);
                rotateRight(tree);
            }
            return true;
        }
    }
    else if (x == tree->data)
    {
        if (!tree->left && !tree->right)
        {
            delete tree;
            tree = NULL;
            count--;
            return true;
        }
        else if (tree->left && !tree->right)
        {
            tree->data = tree->left->data;
            removeNode(tree->data, tree->left);
            updateHeight(tree);
            return true;
        }
        else if (!tree->left && tree->right)
        {
            tree->data = tree->right->data;
            removeNode(tree->data, tree->right);
            updateHeight(tree);
            return true;
        }
        else if (tree->left && tree->right)
        {
            AVLNode<T> *p = tree;
            p = p->left;
            while (p->right)
                p = p->right;
            tree->data = p->data;
            removeNode(tree->data, tree->left);
            updateHeight(tree);
            return true;
        }
    }
    return false;
}

template <class T>
void AVLTree<T>::itInOrder(T *array, AVLNode<T> *tree, int &i) const
{
    if (!tree)
        return;
    itInOrder(array, tree->left, i);
    array[i++] = tree->data;
    itInOrder(array, tree->right, i);
    return;
}

template <class T>
AVLNode<T> *AVLTree<T>::searchNode(const T &key, AVLNode<T> *tree) const
{
    if (!tree)
        return NULL;
    else if (key == tree->data)
        return tree;
    else if (key < tree->data)
        return searchNode(key, tree->left);
    else if (key > tree->data)
        return searchNode(key, tree->right);
    return NULL;
}

template <class T>
void AVLTree<T>::clear(AVLNode<T> *&tree)
{
    if (!tree)
        return;
    clear(tree->left);
    clear(tree->right);
    delete tree;
    tree = NULL;
    count--;
    return;
}