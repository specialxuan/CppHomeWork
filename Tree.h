#include <iostream>

template <class T>
class BinTreeNode
{
protected:
    BinTreeNode<T> *Left;
    BinTreeNode<T> *Right;
    T Data;

public:
    BinTreeNode() : Left(NULL), Right(NULL) {}
    BinTreeNode(const T &item,
                BinTreeNode<T> *l = NULL,
                BinTreeNode<T> *r = NULL)
        : Data(item), Left(l), Right(r) {}
    ~BinTreeNode();
};

template <class T>
BinTreeNode<T>::~BinTreeNode()
{
}

template <class T>
class BinaryTree
{
private:
    BinTreeNode<T> *Root;
    void createBinTree(ifstream &in, BinTreeNode<T> *&t);
    BinTreeNode<T> *Parent(
        BinTreeNode<T> *Tree,
        BinTreeNode<T> *t);
    int insert(BinTreeNode<T> *&Tree, const T &item);
    void tranerse(BinTreeNode<T> *tree);//TODO:
    void destroy(BinTreeNode<T> *tree);

public:
    BinaryTree(/* args */);
    virtual BinaryTree() : Root(NULL);
    virtual ~BinaryTree(){destroy(Root)};
    virtual bool isEmpty(){return} //TODO:
    virtual BinTreeNode<T> *find(const T &item) const;
    BinTreeNode<T> *root() const {return Root};
    friend istream &operator>>(istream &in, BInarytree<T> &t);
    friend istream &operator<<(istream &out, BInarytree<T> &t);
    
};

template <class T>
void BinaryTree<T>::destroy(BinTreeNode<T> *t)
{
    if (T)
    {
        destroy(t->Left);
        destroy(t->Right);
        //TODO:
    }
}
