#ifndef DELETE_REPEATS_H
#define DELETE_REPEATS_H

using namespace std;
#include <iostream>
#include <iomanip>
#include <cassert>
#include "../array_functions/array_functions.h"

template<class T>
void delete_repeats(T* a, int &size); //main function that calls the check_for_duplicates helper

template <class T>
void check_for_duplicates(T*a, int& size); //helper function that runs an inner loop


template<class T>
void delete_repeats(T* a, int &size)
{
    // for( T* start_ptr = a ; start_ptr < a + size - 1; start_ptr ++) //added size - 1 idk why this works
    // {
    //     check_for_duplicates(start_ptr, size);
    // }

    T* walker = a + 1;
    T* end_ptr = a + size;

    while ( walker < end_ptr)
    {
        if( walker != search_entry(a, size, *walker))
        {
            shift_left(a, size, walker);
            end_ptr--;
        }
        else
        {
            walker++;
        }
    }


}

template <class T>
void check_for_duplicates(T*a, int& size)
{
    T* check_this_value = a;                            //Set the value to check to the start of the array
    T* start_ptr = a + 1;                               //point to the second index of the array
    T* end_ptr = a + size;

    // for( start_ptr; start_ptr != end_ptr; start_ptr++) //something isnt working here
    // {
    //     if( *check_this_value == *start_ptr)
    //     {
    //         shift_left(a, size, start_ptr);
    //         // check_this_value++;
    //     }
    // }

    while(start_ptr < end_ptr + 1)                          //change to while loop because we are going to increment
    {                                                   //start ptr and decrement end ptr
        if( *start_ptr == *check_this_value)            //dereference start ptr and check this value
        {
            shift_left(a, size, start_ptr);             //shift left if the duplicate is found
            start_ptr++;
            end_ptr--;                                  //decrement end ptr because size decrements with shift left
        }
        else
        {
            start_ptr++;                                //otherwise, check the next value
        }
    }
}




#endif