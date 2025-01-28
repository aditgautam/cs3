#ifndef LIST_ITERATED_H
#define LIST_ITERATED_H

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

        T *operator->(){return &(_ptr->_item);}                            //member access operator
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
        node<T>* _ptr;
    };      
    List();                                                     //CTOR
                                                                //BIG 3:
    ~List();
    List(const List<T> &copyThis);
    List& operator =(const List& RHS);

    //int size();
    Iterator insert_head(T i);                           //insert at the head of list
    Iterator insert_after(T i,
                                          Iterator iMarker);    //insert after marker
    Iterator insert_before(T i,
                                           Iterator iMarker);   //insert before marker
    Iterator insert_sorted(T i);                         //insert in a sorted list

    T Delete(List<T>::Iterator iMarker);        //delete node pointed to by marker
    void Print() const;
    Iterator search(const T &key);                      //return Iterator to node [key]
    Iterator prev(Iterator iMarker);                            //previous node to marker

    T& operator[](int index);                           //return item at position index
    Iterator begin() const;                                     //Iterator to the head node
    Iterator end() const;                                       //Iterator to NULL
    Iterator last_node() const;                                  //Iterator to the last node
    bool empty()const {return _head_ptr == NULL;}
    template <class U>                                          //Note the template arg U
    friend ostream& operator <<(ostream& outs, const List<U>& l);
    int size()const { return _size; }

private:
    node<T>* _head_ptr;
    int _size;
};

template <typename T>
List<T>::List()
{
    _head_ptr = nullptr;
    _size = 0;
}

template <typename T>
List<T>::~List()
{
    _clear_list(_head_ptr);
    _head_ptr = nullptr;
    _size = 0;
}

template <typename T>
List<T>::List(const List<T> &copyThis)
{
    _head_ptr = _copy_list(copyThis._head_ptr);
    _size = copyThis._size;
}

template<typename T>
List<T>& List<T>::operator =(const List<T>& RHS)
{
    if(&RHS == this)
    {
        return *this;
    }
    _clear_list(_head_ptr);
    _head_ptr = _copy_list(RHS._head_ptr);
    _size = RHS._size;
    return *this;
}

template <typename T>
typename List<T>::Iterator List<T>::insert_head(T i)
{
    _size++;
    return Iterator(_insert_head(_head_ptr, i));
}

template <typename T>
typename List<T>::Iterator List<T>::insert_after(T i, Iterator iMarker)
{
    _size++;
    return Iterator(_insert_after(_head_ptr, iMarker._ptr, i));
    
}

template <typename T>
typename List<T>::Iterator List<T>::insert_before(T i, Iterator iMarker)
{
    _size++;
    return Iterator(_insert_before(_head_ptr, iMarker._ptr, i));
    
}

template <typename T>
typename List<T>::Iterator List<T>::insert_sorted(T i)
{
    _size++;
    return Iterator();
}

template <typename T>
T List<T>::Delete(List<T>::Iterator iMarker)
{
    _size--;
    return _delete_node(_head_ptr, iMarker._ptr);
}

template <typename T>
void List<T>::Print() const
{
    _print_list(_head_ptr);
}

template <typename T>
typename List<T>::Iterator List<T>::search(const T& key)
{
    return Iterator(_search_list(_head_ptr, key));
}

template <typename T>
typename List<T>::Iterator List<T>::prev(Iterator iMarker)
{
    return Iterator(_previous_node(_head_ptr, iMarker._ptr)); 
}

template <typename T>
T& List<T>::operator [](int index)
{
    return _at(_head_ptr, index);
}

template <typename T>
typename List<T>::Iterator List<T>::begin() const
{
    return Iterator(_head_ptr);
}

template <typename T>
typename List<T>::Iterator List<T>::end() const
{
    return nullptr;
}

template <typename T>
typename List<T>::Iterator List<T>::last_node() const
{
    return Iterator(_last_node(_head_ptr));
}

template <typename U>
ostream& operator <<(ostream& outs, const List<U> &l)
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
