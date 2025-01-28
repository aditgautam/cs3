#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>

#include "../../includes/array_functions/array_functions.h"
using namespace std;

bool test_stub(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  return true;
}

bool test_search_entry(bool debug = false)
{
  int a[20];
  int size = 10;
  
  for( int i = 0; i < size; i++ )
  {
    a[i] = i;
  }

  int *search_entry_result = search_entry(a, size, 5);
  if( search_entry_result != &a[5])
  {
    cout << "ERROR: expected to find 5 at this location but did not" << endl;
    return false;
  }

  search_entry_result = search_entry(a, size, 10);
  if(search_entry_result != nullptr)
  {
    cout << "ERROR: did not expect to find 10 in the array, but did" << endl;
    return false;
  }


  return true;
}

bool test_search(bool debug = false)
{
  int a[20];
  int size = 10;

  for( int i = 0; i < size; i++ )
  {
    a[i] = i;
  }

  int search_result = search(a, size, 5);
  if( search_result != 5 )
  {
    cout << "ERRORL expected to find 5 at index 5, but found " << a[5] << " instead \n";
    return false;
  }

  search_result = search(a, size, 10);
  if( search_result != -1 )
  {
    cout << "ERROR: did not expect to find 10 in the array, but did \n";
  }
  return true;
}

bool test_shift_left(bool debug = false)
{
  int a[20];
  int size = 10;

  for( int i = 0; i < size; i++ )
  {
    a[i] = i;
  }


  shift_left(a, size, 5);

  if(a[5] != 6)
  {
    cout << "ERROR, expected to find 5 at index 4, but did not \n";
    print_array(a, size, 20);
    return false;
  }

  if(size != 9)
  {
    cout << "ERROR, expected size to decrement but did not, size is: " << size << endl;
    return false;
  }

  if(a[3] != 3)
  {
    cout << "ERROR, expected to not shift past index 3, but did" << endl;
    return false;
  }
return true;
}

TEST(TEST_STUB, TestStub) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stub(false));
}

TEST(TEST_SEARCH_ENTRY, TestSearchEntry)
{
  EXPECT_EQ(1, test_search_entry(false));
}

TEST(TEST_SEARCH, TestSearch)
{
  EXPECT_EQ(1, test_search(false));
}

TEST(TEST_SHIFT_LEFT, TestShiftLeft)
{
  EXPECT_EQ(1, test_shift_left(false));
}




int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

