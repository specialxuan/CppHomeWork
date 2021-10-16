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
class LinkList
{
protected:
    Node<T> *Head, *Tail;
    T zero;
    int Count;

public:
    LinkList() : Head(NULL), Tail(NULL), Count(0) {}
    ~LinkList() { clear(); }
    int insert(const T &it, int pos = 0);
    int append(const T &it) { return insert(it, Count); }
    int remove(T &it, int pos = 0);
    bool getData(T &it, int pos = 0);
    bool setData(const T &it, int pos = 0);
    bool isEmpty() { return Count == 0; }
    T &operator[](int pos);
    const T &operator[](int pos) const;

    void clear();
    int length() { return Count; }
};

template <class T>
int LinkList<T>::insert(const T &it, int pos)
{
    if (pos < 0 || pos > Count)
        return -1;

    Node<T> *pn, *p;
    if (pos == 0)
    {
        pn = new Node<T>(it, Head);
        Head = pn;
        Count++;
        if (Count == 1)
            Tail = Head;
    }
    else if (pos == Count)
    {
        Tail->next = new Node<T>(it);
        Count++;
        Tail = Tail->next;
    }
    else
    {
        p = Head;
        for (int i = 1; i < pos; i++)
            p = p->next;
        p->next = new Node<T>(it, p->next);
        Count++;
    }
    return Count;
}

template <class T>
int LinkList<T>::remove(T &it, int pos)
{
    if (Count == 0 || pos >= Count || pos < 0)
        return -1;

    Node<T> *p = Head, *pt = Head;
    if (pos == 0)
    {
        it = pt->data;
        Head = pt->next;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
            p = p->next;
        pt = p->next;
        p->next = pt->next;
        it = pt->data;
        if (pt == Tail)
            Tail = p;
    }
    delete pt;
    Count--;
    if (Count == 0)
        Tail = 0;
    return Count;
}

template <class T>
bool LinkList<T>::getData(T &it, int pos)
{
    if (pos < 0 || pos >= Count)
        return false;
    
    Node<T> *p = Head;
    for (int i = 0; i < pos; i++)
        p = p->next;
    it = p->data;
    return true;
}
template <class T>
T &LinkList<T>::operator[](int pos) 
{
    if (pos < 0 || pos >= Count)
        return zero;

    Node<T> *p = Head;
    for (int i = 0; i < pos; i++)
        p = p->next;
    return p->data;
}

template <class T>
const T &LinkList<T>::operator[](int pos) const
{
    if (pos < 0 || pos >= Count)
        return zero;

    Node<T> *p = Head;
    for (int i = 0; i < pos; i++)
        p = p->next;
    return p->data;
}

template <class T>
bool LinkList<T>::setData(const T &it, int pos)
{
    if (pos < 0 || pos >= Count)
        return false;
    
    Node<T> *p = Head;
    for (int i = 0; i < pos; i++)
        p = p->next;
    p->data = it;
    return true;
}

template <class T>
void LinkList<T>::clear()
{
    Node<T> *p = Head;
    while (p)
    {
        Head = Head->next;
        delete p;
        p = Head;
    }
    Count = 0;
    Tail = 0;
}
