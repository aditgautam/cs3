#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
#include "../../includes/linked_list_functions/linked_list_functions.h"
using namespace std;

node<int>* initialize_test_list(int size)
{
  node<int>* head = nullptr;
  for(int i = size; i >= 1; i--)
  {
    _insert_head(head, i);
  }
  return head;
}

bool test_stub(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  return true;
}

bool test_node_default(bool debug = false)
{
  node<int> n;

  if( n._item != 0)
  {
    cout << "Expected to find 0 in default node, but instead found " << n << endl;
    return false;
  }
  if( n._next != nullptr)
  {
    cout << "Expected default node to not point to anything, but it was" << endl;
    return false;
  }
  return true;
}

bool test_node(bool debug = false)
{
  node<int>* n1 = new node<int>(1, nullptr);
  node<int>* n2 = new node<int>(2, n1);

  if(n1 -> _item != 1)
  {
    cout << "Expected to find 1, but instead found " << n1 << endl;
    return false;
  }

  if(n1 -> _next != nullptr)
  {
    cout << "Expected n1 not to point to anything, but it was " << endl;
    return false;
  }

  if(n2 -> _item != 2)
  {
    cout << "Expected to find 2, but instead found " << n2 << endl;
    return false;
  }

  if(n2 -> _next != n1)
  {
    cout << "Expected n2 to point to n1, but it was not " << endl;
    return false;
  }
  delete n1;
  delete n2;

  return true;
}

bool test_insert_head(bool debug = false)
{
  cout << "initializing linked list with size 10: \n";
  node<int>* head = initialize_test_list(10);
  _print_list(head);

  _insert_head(head, 0);
  cout << "inserting 0 at the head: \n";
  _print_list(head);
  if(head -> _item != 0)
  {
    cout << "Expected to find 0 at the head but instead found " << head << endl;
    return false;
  }
  _clear_list(head);
  return true;
}

bool test_insert_after(bool debug = false)
{
  cout << "initializing linked list with size 10: \n";
  node<int>* head = initialize_test_list(10);
  _print_list(head);

  node<int>* node_to_insert = head -> _next;
  _insert_after(head, node_to_insert, 727);
  cout << "Inserting 727 at position 2 : \n";
  _print_list(head);

  if(node_to_insert -> _next -> _item != 727)
  {
    cout << "Expected to find 727 at this position but found" << node_to_insert << endl;
    return false;
  }

  if(node_to_insert -> _next -> _next ->  _item != 3)
  {
    cout << "Expected to find 2 in the next node, but found some other shit idk" << endl;
    return false;
  }

  node<int>* last_node_ptr = head;
  while(last_node_ptr -> _next != nullptr)
  {
    last_node_ptr = last_node_ptr -> _next;
  }

  cout << "inserting some 420 at the last position" << endl;
  _insert_after(head, last_node_ptr, 420);
  _print_list(head);

  _clear_list(head);
  return true;
}

bool test_insert_before(bool debug = false)
{
  cout << "initializing linked list with size 10: \n";
  node<int>* head = initialize_test_list(10);
  _print_list(head);

  node<int>* node_to_insert = head -> _next;
  cout << "Inserting 727 at position 1" << endl;
  _insert_before(head, node_to_insert, 420);
  _print_list(head);

  if(head -> _next -> _item != 420)
  {
    cout << "expected 420 found some bullshit" << endl;
    return false;
  }

  node<int>* last_node_ptr = head;
  while(last_node_ptr -> _next != nullptr)
  {
    last_node_ptr = last_node_ptr -> _next;
  }
  cout << "inserting before the last position: " << endl;
  _insert_before(head, last_node_ptr, 727);
  _print_list(head);
  if(_previous_node(head, last_node_ptr) -> _item != 727)
  {
    cout << "yikes" << endl;
    return false;
  }

  cout << "inserting before head " << endl;
  _insert_before(head, head , 200);
  _print_list(head);

  if(head -> _item != 200)
  {
    cout << "you dun fucked up buddy " << endl;
    return false;
  }

  _clear_list(head);
  return true;
}

bool test_previous_node(bool debug = false) 
{
  cout << "initializing linked list with size 10: \n";
  node<int>* head = initialize_test_list(10);
  _print_list(head);
  node<int>* node_to_find = head->_next->_next->_next->_next; 
  node<int>* prev_to_five = _previous_node(head, node_to_find);
  if (prev_to_five == nullptr || prev_to_five->_item != 4) 
  {
    cout << "Expected previous node to 5 to be 4, but found something else" << endl;
    return false;
  }
  node<int>* prev_to_head = _previous_node(head, head);
  if (prev_to_head != nullptr) 
  {
    cout << "Expected previous node of head to be nullptr, but it wasn't" << endl;
    return false;
  }

  node<int>* last_node = head;
  while (last_node->_next != nullptr) 
  {
    last_node = last_node->_next;
  }

  node<int>* prev_to_last = _previous_node(head, last_node);
  if (prev_to_last == nullptr || prev_to_last->_item != 9) 
  {
    cout << "Expected previous node to 10 to be 9, but found something else" << endl;
    return false;
  }

  _clear_list(head);
  return true;
}


bool test_remove(bool debug = false)
{
  return true;
}

bool test_search(bool debug = false)
{
  return true;
}

bool test_at(bool debug = false)
{
  return true;
}

bool test_copy(bool debug = false)
{
  return true;
}

bool test_copy_pop_back(bool debug = false)
{
  return true;
}

TEST(TEST_STUB, TestStub) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stub(false));
}

TEST(TEST_NODE, test_node_default)
{
  EXPECT_EQ(1, test_node_default(false));
}

TEST(TEST_NODE, test_node_print)
{
  EXPECT_EQ(1, test_node(false));
}

TEST(TEST_INSERT, test_insert_head)
{
  EXPECT_EQ(1, test_insert_head(false));
}

TEST(TEST_INSERT, test_insert_after)
{
  EXPECT_EQ(1, test_insert_after(false));
}

TEST(TEST_INSERT, test_insert_before)
{
  EXPECT_EQ(1, test_insert_before(false));
}

TEST(TEST_REMOVE, test_previous_node)
{
  EXPECT_EQ(1, test_previous_node(false));
}

TEST(TEST_REMOVE, test_remove)
{
  EXPECT_EQ(1, test_remove(false));
}

TEST(TEST_SEARCH_AT, test_search)
{
  EXPECT_EQ(1, test_search(false));
}

TEST(TEST_SEARCH_AT, test_at)
{
  EXPECT_EQ(1, test_at(false));
}

TEST(TEST_COPY, test_copy)
{
  EXPECT_EQ(1, test_copy(false));
}

TEST(TEST_COPY, test_copy_pop_back)
{
  EXPECT_EQ(1, test_copy_pop_back(false));
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

