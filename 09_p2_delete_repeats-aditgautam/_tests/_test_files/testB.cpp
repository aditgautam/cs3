#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
#include "../../includes/delete_repeats/delete_repeats.h"
#include "../../includes/array_functions/array_functions.h"
using namespace std;

bool test_stub(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  return true;
}

bool test_char_array(bool debug = false)
{
  char array[20] = {'a', 'f', 'b', 'c', 'b', 'c', 'd', 'd', 'e', 'f', 'e', 'f', 'a', 'e'};
  int size = 13;
  delete_repeats(array, size);
  
  print_array(array, size, 20);

  return true;
}

TEST(TEST_STUB, TestStub) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stub(false));
}

TEST(TEST_CHAR, TestChar)
{
  EXPECT_EQ(1, test_char_array(false));
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

