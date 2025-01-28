#ifndef LIST_SORTED_H
#define LIST_SORTED_H


#include "../linked_list_functions/linked_list_functions.h"

using namespace std;

template <class T>
class List
{
public:
    class Iterator{
    public:
        friend class List;                          //give access to list to
                                                    //          access _ptr
        Iterator(){_ptr = NULL;}                    //default ctor
        Iterator(node<T>* p) {_ptr = p;}
                                                    //Point Iterator to where p
                                                    //  is pointing to
        T &operator*(){return _ptr -> _item;}                             //dereference operator

        T *operator->(){return _ptr;}                            //member access operator
        bool is_null()
        {
            return _ptr == nullptr;
        }                             //true if _ptr is NULL
        friend bool operator!=(const Iterator &left,
                               const Iterator &right){
                                return left._ptr != right._ptr;
                               } //true if left != right

        friend bool operator==(const Iterator &left,
                               const Iterator &right){
                                return left._ptr == right._ptr;
                               } //true if left == right

        Iterator &operator++()
        {
            _ptr = _ptr -> _next;
            return *this;
        }                         //member operator:
                                                        //  ++it; or
                                                        //  ++it = new_value

        friend Iterator operator++(Iterator &it,
                                   int unused)
                                   {
                                        Iterator xd = it;
                                        ++it;
                                        return xd;
                                   }          //friend operator: it++

    private:
        node<T>* _ptr;                          //pointer being encapsulated
    };

    List(bool order=true, bool unique=false);           //CTOR: default args
                                                        //BIG 3:
    ~List();
    List(const List<T> &copyThis);
    List& operator =(const List& RHS);

    Iterator insert(const T& i);                        //Insert i
    Iterator insert_and_add(const T& i);                //Insert i

    T Delete(List<T>::Iterator iMarker);                //delete node at marker
    void Print() const;
    Iterator search(const T &key) const;                //return Iterator to
                                                        //          node [key]
    Iterator prev(Iterator iMarker);                    //previous node: marker

    const T& operator[](int index) const;               //const version of the
                                                        //       operator [ ]
    T& operator[](int index);                           //return item at index
    Iterator begin() const;                             //Iterator to head node
    Iterator end() const;                               //Iterator to NULL
    Iterator last_node() const;                          //Iterator to last node
    bool empty() const { return _head_ptr == nullptr; }
    template <class U>                                  //Note template arg U
    friend ostream& operator <<(ostream& outs, const List<U>& l);
    int size() const { return _size; }

private:
    node<T>* _head_ptr;
    bool _order;
    bool _unique;
    int _size;
};

template <class T>
List<T>::List(bool order, bool unique)
{
    _order = order;
    _unique = unique;
    _head_ptr = NULL;
    _size = 0;
}

template <class T>
List<T>::~List()
{
    _clear_list(_head_ptr);
    _size = 0;
}

template <class T>
List<T>::List(const List<T> &copyThis)
{
    _size = copyThis._size;
    _order = copyThis._order;
    _unique = copyThis._unique;
    _head_ptr = _copy_list(copyThis._head_ptr);
}

template <class T>
List<T>& List<T>:: operator =(const List<T>& RHS)
{
    if( &RHS == this)
    {
        return *this;
    }
    _clear_list(_head_ptr);
    _size = RHS._size;
    _order = RHS._order;
    _unique = RHS._unique;
    _head_ptr = _copy_list(RHS._head_ptr);
    return *this;
}

template <class T>
typename List<T>::Iterator List<T>::insert(const T& i)
{
    node<T>* inserted = _insert_sorted(_head_ptr, i, _order);
    _size++;
    return Iterator(inserted);
}

template <class T>
typename List<T>::Iterator List<T>::insert_and_add(const T& i)
{
    node<T>* inserted = _insert_sorted_and_add(_head_ptr, i, _order);
    _size++;
    return Iterator(inserted);
}

template <class T>
T List<T>::Delete(List<T>::Iterator iMarker)
{
    T popped = _delete_node(_head_ptr, iMarker._ptr);
    _size--;
    return popped;
}

template <class T>
void List<T>::Print() const
{
    _print_list(_head_ptr);
}

template <class T>
typename List<T>::Iterator List<T>::search(const T& key) const 
{
    node<T>* index = _search_list(_head_ptr, key);
    return Iterator(index);
}

template <class T>
typename List<T>::Iterator List<T>::prev(List<T>::Iterator iMarker)
{
    node<T>* prev = _previous_node(_head_ptr, iMarker._ptr);
    return Iterator(prev);
}

template <class T>
const T& List<T>::operator [](int index) const
{
    return _at(_head_ptr, index);
}

template <class T>
T& List<T>::operator [](int index)
{
    return _at(_head_ptr, index);
}

template <class T>
typename List<T>::Iterator List<T>::begin() const
{
    return Iterator(_head_ptr);
}

template <class T>
typename List<T>::Iterator List<T>::end() const
{
    return nullptr;
}

template <class T>
typename List<T>::Iterator List<T>::last_node() const
{
    return Iterator(_last_node(_head_ptr));
}

template <class U>
ostream& operator <<(ostream& outs, const List<U>& l)
{
    node<U>* walker = l._head_ptr;
    while(walker != nullptr)
    {
        outs << setw(4) << walker -> _item;
        walker = walker -> _next;
    }
    return outs;
}
#endif