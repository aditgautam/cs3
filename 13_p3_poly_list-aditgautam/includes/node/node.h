#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

template <typename T>
struct node
{
public:
    node(const T& item = T(), node* next = nullptr);

    template <typename TT>
    friend std::ostream& operator <<(std::ostream& outs, const node<TT> &printMe);
    T _item;
    node* _next;
};

template <typename T>
node<T>::node(const T& item, node<T>* next)
{
    _item = item;
    _next = next;
}

template <typename TT>
std::ostream& operator <<(std::ostream& outs, const node<TT> &printMe)
{
    outs << printMe._item;
    return outs;
}

#endif