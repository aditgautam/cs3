#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>

#include "../../includes/add_entry/add_entry.h"
using namespace std;

bool test_stub(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  return true;
}

bool test_add_basic(bool debug = false)
{
  cout << "MINIMUM_CAPACITY: " << MINIMUM_CAPACITY << endl;
  int capacity = 3;
  int *arr = allocate<int>(capacity);
  int size = 0;
  for (int i = 0; i < 15; i++){
    cout << "adding [" << i << "] ";
    arr = add_entry(arr, i, size, capacity);
    print_array(arr, size, capacity);
    cout << "size: " << size << " capacity : " << capacity <<endl;
  }
  for( int i = 0; i < 12 ; i++)
  {
      arr = erase_entry(arr, i, size, capacity);
  }
  print_array(arr,size,capacity);
  if(capacity == 20)
  {
    return false;
  }
  return true;
}

bool test_increase_capacity(bool debug = false)
{
  int capacity = 1;
  int *arr = allocate<int>(capacity);
  int size = 0;
  for(int i = 0; i < 5; i++ )
  {
    arr = add_entry(arr, i, size, capacity);
    cout << "size : " << size << " capacity: " << capacity << endl;
  }
  if( capacity != 8)
  {
    return false;
  }
  return true;
}

bool test_popped(bool debug = false)
{
  cout << "MINIMUM_CAPACITY: " << MINIMUM_CAPACITY << endl;
  int capacity = 3;
  int *arr = allocate<int>(capacity);
  int size = 0;
  for (int i = 0; i < 15; i++){
    cout << "adding [" << i << "] ";
    arr = add_entry(arr, i, size, capacity);
    print_array(arr, size, capacity);
    cout << "size: " << size << " capacity : " << capacity <<endl;
  }

  int popped;

  for( int i = 0; i < 15; i++ )
  {
    arr = remove_last_entry(arr, popped, size, capacity);
    cout << popped << endl;
  }
  return true;
}

bool test_edge_case_insert(bool debug = false)
{
  int capacity = 5;
  int *arr = allocate<int>(capacity);
  int size = 5;
  for (int i = 0; i < size; i++)
  {
    arr[i] = i;
    print_array(arr, size, capacity);
    cout << "size: " << size << " capacity : " << capacity <<endl;
  }

  print_array(arr, size, capacity);

  arr = insert_entry(arr, 727, 4, size, capacity);

  print_array(arr, size, capacity);

  if(capacity != 10)
  {
    cout << "ERROR, capacity did not increase, instead capacity is " << capacity <<endl;
    return false;
  }
  if(arr[4] != 727)
  {
    cout << "ERROR, expected 727 at address 4 but instead found " << arr[4] << endl;
    return false;
  }
  return true;

}

TEST(TEST_STUB, TestStub) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stub(false));
}

TEST(TEST_ADD_BASIC, TestAddBasic)
{
  EXPECT_EQ(1, test_add_basic(false));
}

TEST(TEST_INCREASE_CAPACITY, TestIncreaseCapacity)
{
  EXPECT_EQ(1, test_increase_capacity(false));
}

TEST(TEST_POPPED, TestPopped)
{
  EXPECT_EQ(1, test_popped(false));
}

TEST(TEST_EDGE_CASE_INSERT, TestEdgeCaseInsert)
{
  EXPECT_EQ(1, test_edge_case_insert(false));
}




int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

