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
class Set
{
protected:
    Node<T> *Head, *Tail;
    int Count;

public:
    Set() : Head(NULL), Tail(NULL), Count(0) {}
    ~Set()
    {
        clear();
    }
    int insert(const T &it, int pos = 0);
    int append(const T &it)
    {
        return insert(it, Count);
    }
    int remove(T &it, int pos = 0);
    bool getData(T &it, int pos = 0);
    bool setData(const T &it, int pos = 0);
    bool isEmpty()
    {
        return Count == 0;
    }

    int addList(const Set<T> &list);
    Set<T> operator+(const Set<T> &list) const;

    void clear();
    int length()
    {
        return Count;
    }
};

template <class T>
int Set<T>::insert(const T &it, int pos)
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
int Set<T>::remove(T &it, int pos)
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
bool Set<T>::getData(T &it, int pos)
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
bool Set<T>::setData(const T &it, int pos)
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
int Set<T>::addList(const Set<T> &list)
{
    if (list.isEmpty())
        return Count;

    T tmp;
    for (int i = 0; i < list.length(); i++)
    {
        list.getData(tmp, i);
        this->append(tmp);
    }
    return Count;
}

template<class T>
Set<T> Set<T>::operator+(const Set<T> &list) const
{
    Set<T> newList;
    T tmp;
    if (!this->isEmpty())
        for (int i = 0; i < this->Count; i++)
        {
            this->getData(tmp, i);
            newList.append(tmp);
        }
        
    if (!list.isEmpty())
        for (int i = 0; i < list.length(); i++)
        {
            list.getData(tmp, i);
            newList.append(tmp);
        }

    return newList;
}

template <class T>
void Set<T>::clear()
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
