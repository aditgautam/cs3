#ifndef ADD_ENTRY_H
#define ADD_ENTRY_H


using namespace std;
#include "../array_functions/array_functions.h"
#include <iostream>
#include <iomanip>

template<class T>
T* add_entry(T* list, const T& new_entry, int& size, int& capacity);

template<class T>
T* remove_entry(T* list, const T& delete_me, int& size, int& capacity);

template <class T>
T *remove_last_entry(T *list, T &popped, int &size, int &capacity);

template <class T>
T *insert_entry(T *list, const T &insert_this, int insert_here, int &size, int &capacity);

template <class T>
T *erase_entry(T *list, int index, int &size, int &capacity);

template <class T>
T* reduce_capacity(T * list, int &size, int& capacity);         //Helper functions bc i kept reusing code

template <class T> 
T* increase_capacity( T* list, int &size, int &capacity);


template<class T>
T* add_entry(T* list, const T& new_entry, int& size, int& capacity)
{
    // T* add_here = list + size++;
    // *add_here = new_entry;
    // return increase_capacity(list, size, capacity);

    list = increase_capacity(list, size, capacity);
    T* add_here = list + size++;
    *add_here = new_entry;
    return list;
    
}

template<class T>
T* remove_entry(T* list, const T& delete_me, int& size, int& capacity)
{
    // list = reduce_capacity(list, size, capacity);
    if(search_entry(list, size, delete_me) == nullptr )
    {
        cout << "Could not find element. Returning original array." << endl;
        return list;
    }
    shift_left(list, size, search(list, size, delete_me));
    return reduce_capacity(list, size, capacity);
}

template <class T>
T *remove_last_entry(T *list, T &popped, int &size, int &capacity)
{
    // list = reduce_capacity(list, size, capacity);
    T *popper = list + size - 1;
    popped = *popper;
    size--;
    return reduce_capacity(list, size, capacity);
}

template <class T>
T *insert_entry(T *list, const T &insert_this, int insert_here, int &size, int &capacity)
{
    list = increase_capacity(list, size, capacity);
    T* position_to_insert = list + insert_here;
    shift_right(list, size, position_to_insert);
    *position_to_insert = insert_this;
    return list;
}

template <class T>
T *erase_entry(T *list, int index, int &size, int &capacity)
{
    // list = reduce_capacity(list, size, capacity);
    shift_left(list, size, list + index);
    return reduce_capacity(list, size, capacity);
}

template <class T>
T* reduce_capacity(T * list, int &size, int& capacity)
{
    if ( size == capacity / 4.0 && capacity > MINIMUM_CAPACITY)
    {
        capacity /= 2;
        return reallocate( list, size, capacity);
    }
    return list;
}

template <class T> 
T* increase_capacity( T* list, int &size, int &capacity)
{
    if( size == capacity)                               
    {
        capacity *= 2;
        return reallocate(list, size, capacity);
    }
    return list;
}

#endif