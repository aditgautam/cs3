#ifndef VECTOR_CLASS_H
#define VECTOR_CLASS_H
#include <iostream>
#include <iomanip>
#include "../add_entry/add_entry.h"

using namespace std;

template <class T>
class Vector{
public:

    Vector(int capacity = 100);
    Vector(T *arr, int size);
    // big three:

    Vector(const Vector &v);
    Vector& operator =(const Vector &v);
    ~Vector();

    
    //member access functions:
    T& operator [](int index);
    const T& operator [](int index) const;

    T& at(int index);              //return reference to item at position index
    const T& at(int index) const;  //return a const item at position index

    T& front();                         //return item at position 0.
    T& back();                          //return item at the last position


    //Push and Pop functions:
    Vector& operator +=(const T& item); //push_back 
    void push_back(const T& item);      //append to the end
    T pop_back();                       //remove last item and return it


    //Insert and Erase:
    void insert(int insert_here, const T& insert_this); //insert at pos
    void erase(int erase_this_index);        //erase item at position
    int index_of(const T& item);             //search for item. retur index.

    //size and capacity:
    void set_size(int size);              //enlarge the vector to this size
    void set_capacity(int capacity);      //allocate this space
    int size() const {return _size;};  //return _size
    int capacity() const {return _capacity;} //return _capacity

    bool empty() const;                    //return true if vector is empty

    //OUTPUT:
    template <class U>
    friend ostream& operator <<(ostream& outs, const Vector<U>& _a);
private:
    int _size;
    int _capacity;
    // int _how_many;
    T* _vector;
};

template <class T>
Vector<T>::Vector(int capacity)
{
    _vector = allocate<T>(capacity);
    _capacity = capacity;
    _size = 0;
}

template <class T>
Vector<T>::Vector(T *arr, int size)
{
    _size = size;
    if(size < MINIMUM_CAPACITY)
    {
        _capacity = MINIMUM_CAPACITY;
    }
    else
    {
        _capacity = size;
    }
    _vector = copy_array(arr, size);
}

template <class T>
Vector<T>::Vector(const Vector &v)
{
    _size = v._size;
    _capacity = v._capacity;
    _vector = copy_array(v._vector, v._size);
}

template <class T>
Vector<T>& Vector<T>::operator =(const Vector &RHS)
{
    if(&RHS == this)
    {
        return *this;
    }

    delete [] _vector;
    _size = RHS._size;
    _capacity = RHS._capacity;
    _vector = copy_array(RHS._vector, RHS._size);
    return *this;
}

template <class T>
Vector<T>::~Vector()
{
    _size = 0;
    _capacity = 0;
    delete [] _vector;
}



template <class T>
T& Vector<T>::operator [](int index)
{
    return *(_vector + index);
}

template <class T>
const T& Vector<T>::operator [](int index) const
{
    return *(_vector + index);
}

template <class T> 
T& Vector<T>::at(int index)
{
    return *(_vector + index);
}

template <class T>
const T& Vector<T>::at(int index) const
{
    return *(_vector + index);
}

template <class T>
T& Vector<T>::front()
{
    return *_vector;
}

template <class T>
T& Vector<T>::back()
{
    return *(_vector + _size - 1);
}

template <class T>
Vector<T>& Vector<T>::operator +=(const T& item) //push_back
{
    _vector = add_entry(_vector, item, _size, _capacity);
    return *this;
}

template <class T> 
void Vector<T>::push_back(const T& item)
{
    _vector = add_entry(_vector, item, _size, _capacity);
}

template <class T>
T Vector<T>::pop_back()
{
    T popped;
    _vector = remove_last_entry(_vector, popped, _size, _capacity);
    return popped;
}

template <class T>
void Vector<T>::insert(int insert_here, const T& insert_this)
{
    cout << "Printing before insert " << *this << endl;
    _vector = insert_entry(_vector, insert_this, insert_here, _size, _capacity);
    cout << "printing after insert_entry " << *this << endl;
}

template <class T>
void Vector<T>::erase(int erase_this_index)
{
    _vector = erase_entry(_vector, erase_this_index, _size, _capacity);
}

template <class T>
int Vector<T>::index_of(const T& item)
{
    return search(_vector, _size, item);
}

template <class T>
void Vector<T>::set_size(int size)
{
    if(size > _capacity)
    {
        _vector = increase_capacity(_vector, _size, _capacity);
    }
    else if( size < _capacity /4.0)
    {
        _vector = reduce_capacity(_vector, _size, _capacity);
    }
    _size = size;
}             //enlarge the vector to this size

template <class T>
void Vector<T>::set_capacity(int capacity)
{
    _vector = allocate<T>(capacity);
}

template <class T>
bool Vector<T>::empty() const
{
    if(_size == 0)
    {
        return true;
    }
    return false;
}

template <class U>
ostream& operator <<(ostream& outs, const Vector<U>& _a)
{
    // cout << _a._size << " poopnem " << _a._capacity <<endl;
    print_array(_a._vector, _a._size, _a._capacity, outs);
    return outs;
}




















#endif
