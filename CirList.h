#pragma once
#include <iostream>
using namespace std;

template <class T>
struct Node
{
    T data;
    Node<T> *next;

    Node(const T &item, Node<T> *pnext = NULL) : data(item), next(pnext) {}
};

template <class T>
class CirList
{
protected:
    Node<T> *Head, *Tail, *Cur;
    T zero;
    int Count;

public:
    CirList() : Head(NULL), Tail(NULL), Cur(NULL), zero(0), Count(0) {}
    ~CirList() { Clear(); }
    int insert(const T &it, int pos = 0);
    int append(const T &it) { return insert(it, Count); }
    int remove(T &it, int pos = 0);
    T &operator[](int pos);
    const T &operator[](int pos) const;
    bool isEmpty() { return Count == 0; }
    void Clear();
    int length() const { return Count; }
};

template <class T>
int CirList<T>::insert(const T &it, int pos)
{
    if (pos < -1 || pos > Count)
        return -1;

    Count++;
    if (pos == 0)
    { // 数据插入到头部
        Cur = new Node<T>(it, Head);
        Head = Cur;
        if (Count == 1)
            Tail = Head; //只有一个节点
        Tail->next = Head;
    }
    else if (pos == Count - 1)
    { // 数据插入到尾部
        Tail->next = new Node<T>(it, Head);
        Tail = Tail->next;
        Cur = Tail;
    }
    else if (pos == -1)
    {
        // 数据插入到上次访问位置后面
        Cur->next = new Node<T>(it, Cur->next);
        if (Tail == Cur)
            Tail = Cur->next;
        Cur = Cur->next;
    }
    else
    { // 数据插入到其它位置
        Node<T> *p = Head;
        for (int i = 1; i < pos; pos++)
            p = p->next;
        Cur = new Node<T>(it, p->next);
        p->next = Cur;
    }

    return Count;
}

template <class T>
int CirList<T>::remove(T &it, int pos)
{
    if (Count == 0 || pos >= Count || pos < 0)
        return -1;

    Node<T> *p = Head;
    Cur = Head;
    if (pos == 0)
    { //移除第一个节点
        it = p->data;
        Head = p->next;
        Tail->next = Head;
        Cur = Tail;
    }
    else
    { //移除其它节点
        for (int i = 1; i < pos; i++)
            Cur = Cur->next;
        p = Cur->next;
        Cur->next = p->next;
        it = p->data;
        if (p == Tail)
            Tail = Cur;
    }
    delete p;
    Count--;
    if (Count == 0) //表空
        Tail = Head = Cur = 0;

    return Count;
}

template <class T>
T &CirList<T>::operator[](int pos)
{
    if (Count == 0 || pos < -1 || pos >= Count)
        return zero;

    if (pos > -1)
    {
        Cur = Head;
        for (int i = 0; i < pos; i++)
            Cur = Cur->next;
    }

    return Cur->data;
}

template <class T>
const T &CirList<T>::operator[](int pos) const
{
    if (Count == 0 || pos < -1 || pos >= Count)
        return zero;

    Node<T> *p = Cur;

    if (pos > -1)
    {
        p = Head;
        for (int i = 0; i < pos; i++)
            p = p->next;
    }

    return p->data;
}

template <class T>
void CirList<T>::Clear()
{
    while (Count--)
    {
        Cur = Head;
        Head = Head->next;
        delete Cur;
    }
    Cur = Head = Tail = NULL;
    Count = 0;
}