#include <iostream>

template <class T>
class BiTreeNode
{
protected:
    BiTreeNode<T> *Left;
    BiTreeNode<T> *Right;
    T Data;

public:
    BiTreeNode() : Left(NULL), Right(NULL) {}
    BiTreeNode(const T &item,
               BiTreeNode<T> *l = NULL,
               BiTreeNode<T> *r = NULL)
        : Left(l), Right(r), Data(item) {}
    ~BiTreeNode();
};

template <class T>
BiTreeNode<T>::~BiTreeNode()
{
}

template <class T>
class BinaryTree
{
private:
    BiTreeNode<T> *Root;

    void createBinTree(ifstream &in, BiTreeNode<T> *&t);
    BiTreeNode<T> *Parent(BiTreeNode<T> *Tree, BiTreeNode<T> *t);
    int insert(BiTreeNode<T> *&Tree, const T &item);
    void tranerse(BiTreeNode<T> *tree); //TODO:
    void destroy(BiTreeNode<T> *tree);

public:
    BinaryTree(/* args */);
    virtual BinaryTree() : Root(NULL);
    virtual ~BinaryTree(){destroy(Root)};
    virtual bool isEmpty() { return } //TODO:
    virtual BiTreeNode<T> *find(const T &item) const;
    BiTreeNode<T> *root() const {return Root};
    friend istream &operator>>(istream &in, BInarytree<T> &t);
    friend istream &operator<<(istream &out, BInarytree<T> &t);
};

template <class T>
void BinaryTree<T>::destroy(BiTreeNode<T> *t)
{
    if (T)
    {
        destroy(t->Left);
        destroy(t->Right);
        //TODO:
    }
}
