#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
#include "../../includes/vector/vector_class.h"
using namespace std;

bool test_stub(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  return true;
}

bool test_pop_back(bool debug = false)
{
  int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  Vector<int> v(a, 10);
  cout << "Vector initialized with size: " << v.size() << " and capacity: " << v.capacity() << endl;
  cout << v << endl;
  for(int i = 0; i < v.capacity(); i++)
  {
    cout << v.pop_back() << endl;
    cout << v << endl;
  }
  return true;
}

bool test_set_size(bool debug = false)
{
  int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  Vector<int> v(a, 10);
  cout << "Vector initialized with size: " << v.size() << " and capacity: " << v.capacity() << endl;
  cout << v << endl;
  v.set_size(15);
  cout << v << endl;
  if(v.size() != 15)
  {
    return false;
  }
  v.set_size(4);
  cout << v << endl;
  if(v.size() != 4)
  {
    return false;
  }
  return true;
}

bool test_set_capacity(bool debug = false)
{
  int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  Vector<int> v(a, 10);
  cout << "Vector initialized with size: " << v.size() << " and capacity: " << v.capacity() << endl;
  cout << v << endl;
  v.set_capacity(20);
  cout << "Capacity changed to 20" << endl;
  if(v.capacity() != 20)
  {
    cout << "ERROR vector capacity not changed to 20" << endl;
    cout << "instead vector capacity is: " << v.capacity() << endl;
    return false;
  }
  return true;
}

bool test_at_bracket(bool debug = false)
{
  int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  Vector<int> v(a, 10);
  cout << "Vector initialized with size: " << v.size() << " and capacity: " << v.capacity() << endl;
  cout << v << endl;
  for(int i = 0; i < v.size(); i++)
  {
    if(v[i] != i)
    {
      cout << "Expected " << i << " but instead found " << v[i] << endl;
      return false;
    }
  }
  return true;
}

bool test_constructor(bool debug = false)
{
  Vector<int> v;
  cout << "Vector initialized with size " << v.size() << " and capacity " << v.capacity() << endl;
  return true;
}

bool test_constructor_int(bool debug = false)
{
  Vector<int>v(12);
  cout << "Vector initialized with size " << v.size() << " and capacity " << v.capacity() << endl;
  if(v.capacity() != 12)
  {
    cout << "ERROR, expected capacity to be 12 but instead it is " << v.capacity() << endl;
    return false;
  }
  return true;
}

bool test_front_back(bool debug = false)
{
  int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  Vector<int> v(a, 10);
  cout << "Vector initialized with size " << v.size() << " and capacity " << v.capacity() << endl;
  cout << "Inserting 727 to front: " << endl;
  v.front() = 727;
  if(v[0] != 727)
  {
    cout << "error, expected 727 at index 0 but instead found: " << v[0] << endl;
    cout << v << endl;
    return false;
  }
  cout << "Inserting 420 to the back: " << endl;
  v.back() = 420;
  if(v[9] != 420)
  {
    cout << "error, expected 420 at index 9 but instead found: " << v[9] << endl;
    cout << v << endl;
    return false;
  }
  return true;
}

bool test_empty_array(bool debug = false)
{
  int a[] = {};
  Vector<int> v(a, 0);
  cout << "Vector initialized with size " << v.size() << " and capacity " << v.capacity() << endl;
  if(!v.empty())
  {
    cout << "error, expected vector to be empty, instead has size: " << v.size() << " and capacity " << v.capacity() << endl;
    return false;
  }

  for(int i = 0; i < 10; i++)
  {
    v+=i;
    cout << v << endl;
  }
  cout << v[1000] <<endl;
  return true;
}

bool test_capacity_change(bool debug = false)
{
  int a[] = {};
  Vector<int> v(a, 0);
  for(int i = 0; i < 13; i++)
  {
    v+=i;
    cout << v << endl;
  }

  for(int i = 0; i < 13; i++)
  {
    cout << "Popping: " << v.pop_back() << endl;
    cout << v << endl;
  }
  return true;
}

bool test_insert(bool debug = false)
{
  int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  Vector<int> v(a, 10);
  cout << v << endl;
  v.insert(2, 727);
  cout << v;
  if(v[2] != 727)
  {
    cout << "ERROR, expected to find 727 at index 2 but instead found " << v[2] <<endl;
    cout << v << endl;
    return false;
  }
  return true;
}

TEST(TEST_STUB, TestStub) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stub(false));
}

TEST(TEST_POP_BACK, TestPopBack)
{
  EXPECT_EQ(1, test_pop_back(false));
}

TEST(TEST_SET_SIZE, TestSetSize)
{
  EXPECT_EQ(1, test_set_size(false));
}

TEST(TEST_SET_CAPACITY, TestSetCapacity)
{
  EXPECT_EQ(1, test_set_capacity(false));
}

TEST(TEST_AT_BRACKET, TestAtBracket)
{
  EXPECT_EQ(1, test_at_bracket(false));
}

TEST(TEST_CONSTRUCTOR, test_constructor)
{
  EXPECT_EQ(1, test_constructor(false));
}

TEST(TEST_CONSTRUCTOR_INT, test_constructor_int)
{
  EXPECT_EQ(1, test_constructor_int(false));
}

TEST(TEST_FRONT_BACK, test_front_back)
{
  EXPECT_EQ(1, test_front_back(false));
}

TEST(TEST_EMPTY_ARRAY, test_empty_array)
{
  EXPECT_EQ(1,test_empty_array(false));
}

TEST(TEST_CAPACITY_CHANGE, test_capacity_change)
{
  EXPECT_EQ(1, test_capacity_change(false));
}

TEST(TEST_INSERT, test_insert)
{
  EXPECT_EQ(1, test_insert(false));
}






int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

