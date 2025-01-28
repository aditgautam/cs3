#ifndef ARRAY_FUNCTIONS_H
#define ARRAY_FUNCTIONS_H

using namespace std;
#include <iostream>
#include <iomanip>
#include <cassert>

const int MINIMUM_CAPACITY = 3;

template<class T>
T* allocate(int capacity= MINIMUM_CAPACITY);            //allocate 'capacity' 
                                                        //      elements. 
                                                        //  return array

template<class T>
T* reallocate(T* a, int size, int capacity);            //take array, resize it 
                                                        //  return new array. 
                                                        //  delete old array

template<class T>
void print_array(T* a, int size, 
            int capacity = 0, ostream& outs = cout);    //prints 
                                                        //  (size/capacity)
                                                        //  for debugging

template <class T>
void print(T* a, unsigned int how_many, 
                                ostream& outs = cout);  //print array

template<class T>
T* search_entry(T* a, int size, const T& find_me);      //search for 'find me'

template <class T>
int search(T* a, int size, const T& find_me);           //search for 'find_me' 

template <class T>
void shift_left(T* a, int& size, int shift_here);       //shift left @ pos:
                                                        //    erases @ pos
template <class T>
void shift_left(T* a, int& size, T* shift_here);        //shift left @ pos: 
                                                        //    erases @ pos

template <class T>
void shift_right(T *a, int &size, int shift_here);      //shift right: 
                                                        //      make a hole

template <class T>
void shift_right(T *a, int &size, T* shift_here);       //shift right: 
                                                        //   make a hole

template<class T>
void copy_array(T *dest, const T* src, 
                                int many_to_copy);      //copy from src to dest

template <class T>
T* copy_array(const T *src, int size);                  //return a 
                                                        //  copy of src

template <class T>
string array_string(const T *a, int size);              //return array 
                                                        //  as a string

template <class T>
void init_array(T* a, int size, T item);


template<class T>       //make sure to return the pointer !!!!!!!
T* allocate(int capacity)
{
    T* a = new T[capacity]; //Allocates new memory addresses with size capacity
    return a;               //Could write in one line but I am a noob and need to see it first
}           

template<class T>       //same shit as above!!!!
T* reallocate(T* a, int size, int capacity)
{
    // cout << "original array: ";
    // print_array(a, size, capacity);
    
    T* new_array = new T[capacity]; //declaring a new array with the new desired capacity
    
    // print_array(new_array, size, capacity);
    

    T* a_ptr = a;
    T* new_array_ptr = new_array;

    for( int i = 0; i < size ; i++)
    {
        *new_array_ptr= *a_ptr; //derefernece the walkers to get the values
        // cout << "original value: " << *a_ptr << " copy: " << *new_array_ptr <<endl;
        new_array_ptr++;
        a_ptr++;
    }
    // cout << "Printing reallocated array: \n";
    // print_array(new_array, size, capacity);

    delete [] a;
    // cout << "Printing reallocated array: \n";
    // print_array(new_array, size, capacity);
    

    return new_array;
}

template<class T>
void print_array(T* a, int size, int capacity, ostream& outs)
{
    T* start_ptr = a;
    T* end_ptr = start_ptr + size;

    cout << "Printing array with size " << size << " and capacity " << capacity << endl;

    for( T* w = start_ptr; w < end_ptr; w++ )
    {
        outs << setw(4) << *w;
    }
    outs << endl;
}

template <class T>
void print(T* a, unsigned int how_many, ostream& outs)
{
    T* start_ptr = a;
    T* end_ptr = start_ptr + how_many;

    for( T* w = start_ptr; w != end_ptr; w++ )
    {
        outs << setw(4) << *w;
    }
    outs << endl;
}

template<class T>
T* search_entry(T* a, int size, const T& find_me) //here we are returning a pointer to the address of where the element is
{
    T* start_ptr = a;                               // blah blah blah typical bullshit 
    T* end_ptr = start_ptr + size;

    for ( T* w = start_ptr; w!= end_ptr; w++ )      // same loop as always
    {
        if( *w == find_me )                         // check if dereferenced walker is the same element as find me
        {
            return w;                               // if it is found, return the address (NOT DEREFERENCED)
        }
    }
    return nullptr;                                 // if that shit dont exist, return a null pointer
}

template <class T>
int search(T* a, int size, const T& find_me)
{
    T* start_ptr = a;
    T* end_ptr = start_ptr + size;

    int index = 0;                                  //since we are returning an index, initialize an iterator to 0

    for ( T* w = start_ptr; w!= end_ptr; w++ )
    {
        if( *w != find_me )                         //check if our walker is the element we are searching for
        {
            index++;                                //if its not what we are looking for, increment index
        }
        else if( *w == find_me)
        {
            return index;                           //if it is what we are looking for, return the index without incrementing
        }
    }
    return -1;                                      //otherwise, the element wasnt found, return -1
}

template <class T>                                  //I am using the same array function I had in CS2
void shift_left(T* a, int& size, int shift_here)    //Using hand notes to translate the array notation to pointers, as a warm up
{
    for( T* walker = a + shift_here; walker < a + size - 1; walker++)
    {
        T* get_next_value = walker + 1;             //THIS IS A LOCAL VARIABLE. DOES NOT NEED TO INCREMENT IN THE LOOP WITH ++
        *walker = *get_next_value;
    }
    size--;
}

template <class T>
void shift_left(T* a, int& size, T* shift_here)
{
    for( T* walker = shift_here ; walker < a + size - 1; walker++) //Same function as above. Simply using shift here as the 
    {                                                               //start point rather than using arithmetic
        T* get_next_value = walker + 1;
        *walker = *get_next_value;
    }
    size--;
}

template <class T>
void shift_right(T *a, int &size, int shift_here)                   //Nearly identical function as above, just changing loop condition
{
    for( T* walker = a + size ; walker > a + shift_here; walker--)
    {
        T* get_previous_value = walker - 1;
        *walker = *get_previous_value;
    }
    size++;
}

template <class T>
void shift_right(T *a, int &size, T* shift_here)
{
    for( T* walker = a + size ; walker > shift_here ; walker--)
    {
        T* get_previous_value = walker - 1;
        *walker = *get_previous_value;
    }
    size++;
}

template<class T>
void copy_array(T *dest, const T* src, int many_to_copy)
{
    T* start_ptr = dest;                                   //Point to beginning of new array
    T* end_ptr = start_ptr + many_to_copy;                 //End pointer adds how many indeces we want to copy
    for( start_ptr ; start_ptr != end_ptr ; start_ptr++)
    {
        *start_ptr = *src;
        src++;                                             //Increment source pointer since start ptr is incrementing in for loop
    }   
}

template <class T>
T* copy_array(const T *src, int size)                       //THIS IS BASICALLY THE SAME AS REALLOCATE
{
    T* new_array = new T[size];                             //Declaring new array to copy to
    T* new_array_ptr = new_array;                               //Point to the start of our new array
    const T* end_ptr = src + size;                          //End pointer just adds to size

    while( src < end_ptr)
    {
        *new_array_ptr = *src;
        new_array_ptr++;
        src++;
    }       
    return new_array;                              //return the start of new array, was causing bug
}

template <class T>                                          //What the fuck does this even do?? Use to_string??
string array_string(const T *a, int size)
{
    return string();
}

template <class T>
void init_array(T* a, int size, T item)
{
    for(T* walker = a; walker < a + size; walker++)
    {
        *walker = item;
    }
}


#endif