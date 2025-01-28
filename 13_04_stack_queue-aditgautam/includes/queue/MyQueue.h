#ifndef MY_QUEUE_H
#define MY_QUEUE_H
#include "../linked_list_functions/linked_list_functions.h"
#include "../list_iterated/list_iterated.h"

using namespace std;

template <typename T>
class Queue
{
public:
    using Iterator = typename List<T>::Iterator;
    Queue();

    Queue(const Queue<T>& copyMe);
    ~Queue();
    Queue& operator=(const Queue<T>& RHS);

    bool empty();
    T front();
    T back();

    void push(T item);
    T pop();

    Iterator begin() const;            //Iterator to the head node
    Iterator end() const;              //Iterator to NULL
    void print_pointers();
    int size() const { return _list.size(); }
    template<typename TT>
    friend ostream& operator << (ostream& outs, const Queue<TT>& printMe);
private:
    List<T> _list;
    Iterator _rear;
};

template <typename T>
Queue<T>::Queue()
{
    _rear = Iterator();
}

template <typename T>
Queue<T>::Queue(const Queue<T>& copyMe)
{
    if(copyMe._front == nullptr)
    {
        _rear = nullptr;
    }
    _rear = _last_node(_list);
}

template <typename T>
Queue<T>::~Queue()
{
    _rear = nullptr;
}

template <typename T>
Queue<T>& Queue<T>::operator =(const Queue<T>& RHS)
{
    if(this == &RHS)
    {
        return *this;
    }
    _rear = _last_node(_list);
    return *this;
}

template <typename T>
bool Queue<T>::empty()
{
    return _list.empty();
}

template <typename T>
T Queue<T>::front()
{
    return *(_list.begin());
}

template <typename T>
T Queue<T>::back()
{
    return *_rear;
}

template<typename T>
void Queue<T>::push(T item)
{
    if(_list.empty())
    {
        _rear = _list.insert_head(item);
    }
    else
    {
        _rear = _list.insert_after(item, _rear);
    }
}

template <typename T>
T Queue<T>::pop()
{
    assert(!_list.empty() && "Cannot pop from an empty queue");
    
    return _list.Delete(_list.begin());
}

template <typename T>
typename Queue<T>::Iterator Queue<T>::begin() const
{
    return _list.begin();
}

template <typename T>
typename Queue<T>::Iterator Queue<T>::end() const
{
    return _list.end();
}

template <typename T>
void Queue<T>::print_pointers()
{

}

template <typename TT>
ostream& operator <<(ostream& outs, const Queue<TT>& printMe)
{
    outs << printMe._list;
    return outs;
}

#endif