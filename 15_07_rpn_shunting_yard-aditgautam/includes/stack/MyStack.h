#ifndef MY_STACK_H
#define MY_STACK_H
#include "../linked_list_functions/linked_list_functions.h"
#include "../list_iterated/list_iterated.h"

using namespace std;

template <typename T>
class Stack{
public:
    using Iterator = typename List<T>::Iterator;
    // Stack();
    // Stack(const Stack<T>& copyMe);
    // ~Stack();
    Stack<T>& operator=(const Stack<T>& RHS);
    T top();
    bool empty();
    void push(T item);
    T pop();
    template<typename TT>
    friend ostream& operator<<(ostream& outs, 
                                        const Stack<TT>& printMe);

    Iterator begin() const;              //Iterator to the head node
    Iterator end() const;                //Iterator to NULL
    int size() const { return _list.size(); }

private:
    List<T> _list;
};

// template <typename T>
// Stack<T>::Stack(const Stack<T>& copyMe)
// {
    
// }

// template <typename T>
// Stack<T>& Stack<T>::operator=(const Stack<T>& RHS)
// {
   
// }

template <typename T>
T Stack<T>::top()
{
    return *(_list.begin());
}

template <typename T>
bool Stack<T>::empty()
{
    return _list.empty();
}

template <typename T>
void Stack<T>::push(T item)
{
    _list.insert_head(item);
}

template <typename T>
T Stack<T>::pop()
{
    return _list.Delete(_list.begin());
}

template <typename TT>
ostream& operator <<(ostream& outs, const Stack<TT>& printMe)
{
    outs << printMe._list;
    return outs;
}

template <typename T>
typename Stack<T>::Iterator Stack<T>::begin() const
{
    return _list.begin();
}

template <typename T>
typename Stack<T>::Iterator Stack<T>::end() const
{
    return _list.end();
}




#endif