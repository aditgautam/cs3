#ifndef GAUTAM__FUN_H__
#define GAUTAM__FUN_H__

#include <iostream>
#include <iomanip>
using namespace std;


template <typename T>
void init_array(T a[], int size);

template <typename T>
void append_array(T a[], int &size, T item);

template <typename T>
void print_array(T a[], int size);

template <typename T>
int* find(T a[], int size, T key);

template <typename T>
T whats_here(T* arr, int size, T* here);





template <typename T>
void init_array(T a[], int size){
  
}
template <typename T>
void append_array(T a[], int &size, T item){
  cout << "appending into array: [" << size << "], item: " << item << endl;

  T *ptr;
  ptr = a;
  ptr = ptr + size; // move ptr to the end
  *ptr = item;      //write item to the end
  size++;
}

template <typename T>
void print_array(T a[], int size){
  cout << "printing array: [" << size << "]" << endl;
  T *start_ptr = &a[0];
  T *end_ptr = start_ptr + size;

  for (T *w = start_ptr;
                       w != end_ptr;
                       w++){
    cout << setw(4) << *w;
  }
  cout << endl;
}

template <typename T>
int* find(T a[], int size, T key){
  T *start_ptr = &a[0];
  T* w = start_ptr;
  T *end_ptr = start_ptr + size -1;


  while(w!=end_ptr){
    if (*w == key){
      // return w - start_ptr;  //if you want to return an index.
      return w;
    }
    w++;
  }
  return nullptr;  //has a value of zero. Do NOT use zero.
  
}


template <typename T>
T whats_here(T*arr , int size, T* here){
  T zero = *arr;
  T one = arr[1];
  T two = *(arr + 2);  //NEVER use this!
  T* two_ptr = arr + 2;
  two = *two_ptr;
  if (here < arr)
  {
    return -1;  //be offended!
  }
  if (here >arr +size){
    return -1;  //be triggered.
  }
  return *here;
}



#endif // GAUTAM__FUN_H__


