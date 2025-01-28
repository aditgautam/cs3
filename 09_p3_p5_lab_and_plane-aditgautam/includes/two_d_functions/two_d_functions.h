#ifndef TWO_D_FUNCTIONS_H
#define TWO_D_FUNCTIONS_H
#include <iostream>
#include <iomanip>
#include "../array_functions/array_functions.h"

using namespace std;


int array_size(int* sizes);
void print_array(int* a);
bool index_is_valid(int* sizes, int row, int col);
int get_num_rows(int* sizes);



//To call: int** p = allocate_twod<int>(sizes_array)  

template <class T>
T** allocate_twod(int* sizes); 

template <class T>
T** deallocate_twod(T** twod, int size);

template <class T>
T read_twod(T** twod, int row, int col);

template <class T>
void write_twod(T** twod, int row, int col, const T& item);

template <class T>
T& get_twod(T** twod, int row, int col);

template<class T>
void init_twod(T** twod, int* sizes, T init_item = T());

template<class T>
bool search_twod(T** twod, int* sizes, const T& key, int& row, int& col);

//return a pointer to the item if found, nullptr if not found: 
//                                                 (Ms. Barskhian)
template<class T> 
T* search_twod(T** twod, int* sizes, const T& key);


template <class T>
ostream& print_twod(T** twod, int* sizes, ostream& outs = cout);




template <class T>
T** allocate_twod(int* sizes)
{
    int n = get_num_rows(sizes);

    T** two_d = allocate<T*>(n + 1);    //Allocating an array of T* which store the addresses of the head of each row
                                        //n+1 because we want to terminate our array with a nullptr
    *(two_d + n) = nullptr;
    for(T** walker = two_d; walker < two_d + n; walker++)
    {
        *walker = allocate<T>(*sizes);  //Allocate each address with a T* to our row array heads
        sizes++;                        //Increment sizes each loop
    }
    return two_d;
}

template <class T>
T** deallocate_twod(T** twod, int size)
{
    for( int i = 0; i < size; i++)
    {
        T** to_delete = twod + i;
        delete [] *to_delete;
    }
    delete [] twod;
    return nullptr;
}

template <class T>
T read_twod(T** twod, int row, int col)
{
    T** row_walker = twod + row;
    T* col_walker = *row_walker + col;
    return *col_walker;
}

template <class T>
void write_twod(T** twod, int row, int col, const T& item)
{
    T** row_walker = twod + row;
    T* col_walker = *row_walker + col;
    *col_walker = item;
}

template <class T>
T& get_twod(T** twod, int row, int col)
{
    T** row_walker = twod + row;
    T* col_walker = *row_walker + col;
    return *col_walker;
}

template<class T>
void init_twod(T** twod, int* sizes, T init_item)
{
    int num_of_rows = get_num_rows(sizes);

    for(int i = 0; i < num_of_rows; i++)
    {
        init_array(*twod, *sizes, init_item);
        sizes++;
        twod++;
    }
}

template<class T>
bool search_twod(T** twod, int* sizes, const T& key, int& row, int& col)
{
    int num_of_rows = get_num_rows(sizes);

    for(int i = 0; i < num_of_rows; i++)
    {
        T* array_to_search = *(twod + i);
        T* search_result = search_entry(array_to_search, *sizes, key);

        if(search_result != nullptr)
        {
            row = i;
            col = search_result - array_to_search;
            return true;
        }
        sizes++;
    }
    return false;
}

template<class T> 
T* search_twod(T** twod, int* sizes, const T& key)
{
    for(int i = 0; i < get_num_rows(sizes); i++)
    {
        T* search_result = search_entry(*twod, *sizes, key);

        if(search_result != nullptr)
        {
            return search_result;
        }
        twod++;
        sizes++;
    }
    return nullptr;
}

template <class T>
ostream& print_twod(T** twod, int* sizes, ostream& outs)
{
    int num_of_rows = get_num_rows(sizes);

    for( int i = 0; i < num_of_rows; i++)
    {
        print(*twod, *sizes);
        twod++;
        sizes++;
        outs << endl;
    }
    return outs;

}

#endif