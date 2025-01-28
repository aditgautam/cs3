#ifndef LINKED_LIST_FUNCTIONS_H
#define LINKED_LIST_FUNCTIONS_H

#include <iostream>
#include <iomanip>
#include <cassert>
#include "../node/node.h"

//Linked List General Functions:
template <typename T>
void _print_list(node<T>* head);

//recursive fun! :)
template <typename T>
void _print_list_backwards(node<T> *head);

//return ptr to key or NULL
template <typename T>
node<T>* _search_list(node<T>* head, T key);


template <typename T>
node<T>* _insert_head(node<T> *&head, T insert_this);

//insert after ptr
template <typename T>
node<T>* _insert_after(node<T>*& head, node<T> *after_this, T insert_this);

//insert before ptr
template <typename T>
node<T>* _insert_before(node<T>*& head, node<T>* before_this, T insert_this);

//ptr to previous node
template <typename T>
node<T>* _previous_node(node<T>* head, node<T>* prev_to_this);

//delete, return item
template <typename T>
T _delete_node(node<T>*&head, node<T>* delete_this);

//duplicate the list...
template <typename T>
node<T>* _copy_list(node<T>* head);

//duplicate list and return the last node of the copy
template <typename T>
node<T> *_copy_list(node<T>* &dest, node<T> *src);


//delete all the nodes
template <typename T>
void _clear_list(node<T>*& head);

//_item at this position
template <typename T>
T& _at(node<T>* head, int pos);

//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
//      Sorted List Routines. order: 0: ascending, order: other: descending
//                              Assume a Sorted List
//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

template <typename T>
node<T>* _insert_sorted(node<T>* &head, T item, bool ascending=true);

//insert or add if a dup
template <typename T>
node<T>* _insert_sorted_and_add(node<T>* &head, T item, bool ascending=true);

//node after which this item goes order: 0 ascending
template <typename T>
node<T>* _where_this_goes(node<T>* head, T item, bool ascending=true);

//Last Node in the list
template <typename T>
node<T>* _last_node(node<T>* head);            //never use this function.

//-------------------------------------------------------------------------------------------------------------

//Linked List General Functions:
template <typename T>
void _print_list(node<T>* head)
{
    if(head == nullptr)
    {
        cout << "Cannot print an empty list" << endl;
        return;
    }
    node<T>* node_walker = head;

    while(node_walker != nullptr)
    {
        cout << setw(4) << *node_walker;
        node_walker = node_walker -> _next;
    }
    cout << endl;
}

    //recursive fun! :)
template <typename T>
void _print_list_backwards(node<T> *head)
{
    if(head == nullptr)
    {
        cout << "Cannot print an empty list " << endl;
    }

    _print_list_backwards(head -> _next);

    cout << setw(4) << head ->_item;
}


    //return ptr to key or NULL
template <typename T>
node<T>* _search_list(node<T>* head, T key)
{
    node<T>* node_walker = head;
    while(node_walker != nullptr)
    {
        if(node_walker-> _item == key)
        {
            return node_walker;
        }
        node_walker = node_walker -> _next;
    }
    return nullptr;                         //if key isnt found return nullptr
}


template <typename T>
node<T>* _insert_head(node<T> *&head, T insert_this)
{
    node<T>* new_head = new node<T>(insert_this, head);
    head = new_head;
    return head;
}

    //insert after ptr
template <typename T>
node<T>* _insert_after(node<T>*& head, node<T> *after_this, T insert_this)
{
    if(after_this == nullptr)
    {
        return nullptr;
    }
    if(head == nullptr)
    {
        return _insert_head(head, insert_this);
    }
    node<T>* new_node = new node<T>(insert_this, after_this -> _next);
    after_this -> _next = new_node;
    return new_node;
}

    //insert before ptr
template <typename T>
node<T>* _insert_before(node<T>*& head, node<T>* before_this, T insert_this)
{
    if(head == before_this || head == nullptr || before_this == nullptr)
    {
        return _insert_head(head, insert_this);
    }

    node<T>* previous_node = _previous_node(head, before_this);

    if(previous_node != nullptr)
    {
        return _insert_after(head, previous_node, insert_this);
    }

    return nullptr;
}

    //ptr to previous node
template <typename T>
node<T>* _previous_node(node<T>* head, node<T>* prev_to_this)
{
    if(head == nullptr)
    {
        return nullptr;
    }
    if(head == prev_to_this)
    {
        return nullptr;
    }

    node<T>* node_walker = head;

    while(node_walker != nullptr)
    {
        if(node_walker -> _next == prev_to_this)
        {
            return node_walker;
        }
        node_walker = node_walker -> _next;
    }
    return nullptr;
}

    //delete, return item
template <typename T>
T _delete_node(node<T>*&head, node<T>* delete_this)
{
    assert(head != nullptr && "List is empty, cannot delete");
    T item_to_return = delete_this -> _item;

    if(delete_this == nullptr)
    {
        return T();         //default item type
    }

    if(head == delete_this)
    {
        head = head -> _next;
    }
    else
    {
        node<T>* previous_node = _previous_node(head, delete_this);

        assert(previous_node != nullptr && "Previous node did not return a pointer");
        previous_node -> _next = delete_this -> _next;
        
    }

    delete delete_this;
    return item_to_return;
}

    //duplicate the list...
template <typename T>
node<T>* _copy_list(node<T>* head)
{
    if(head == nullptr)
    {
        return nullptr;
    }

    node<T>* new_head = new node<T>(head -> _item, nullptr);
    
    node<T>* node_walker = head-> _next;

    node<T>* new_node_walker = new_head;

    while(node_walker != nullptr)
    {
        new_node_walker -> _next = new node<T>(node_walker -> _item, nullptr);
        node_walker = node_walker -> _next;                                                 //basically walker++
        new_node_walker = new_node_walker -> _next;
    }

    return new_head;
}

    //duplicate list and return the last node of the copy
template <typename T>
node<T> *_copy_list(node<T>* &dest, node<T> *src)
{
    dest = nullptr;
    if(src == nullptr)
    {
        return dest;
    }

    // dest = new node<T>(src -> _item, nullptr);
    node<T>* src_walker = src;
    node<T>* dest_walker = dest;

    while(src_walker != nullptr)
    {
        dest_walker = _insert_after(dest, dest_walker, src_walker);
        src_walker = src_walker -> _next;
    }
    return dest_walker;
}


    //delete all the nodes
template <typename T>
void _clear_list(node<T>*& head)
{
    node<T>* node_walker = head;
    while(node_walker != nullptr)
    {
        node<T>* next_node = node_walker -> _next;
        delete node_walker;
        node_walker = next_node;
    }
    head = nullptr;
}

    //_item at this position
template <typename T>
T& _at(node<T>* head, int pos)
{
    assert(head != nullptr && "Head of the array does not exist");
    node<T>* node_walker = head;

    for(int i = 0; i < pos; i++)
    {
        assert(node_walker -> _next != nullptr && "Item is out of range");
        node_walker = node_walker -> _next;
    }
    return node_walker -> _item;
}

    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
    //      Sorted List Routines. order: 0: ascending, order: other: descending
    //                              Assume a Sorted List
    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

template <typename T>
node<T>* _insert_sorted(node<T>* &head, T item, bool ascending);

    //insert or add if a dup
template <typename T>
node<T>* _insert_sorted_and_add(node<T>* &head, T item, bool ascending);
    
    //node after which this item goes order: 0 ascending
template <typename T>
node<T>* _where_this_goes(node<T>* head, T item, bool ascending);
    //Last Node in the list

template <typename T>
node<T>* _last_node(node<T>* head)
{
    node<T>* walker = head;
    while(walker -> _next != nullptr)
    {
        walker = walker -> _next;
    }
    return walker;
}            //never use this function.

#endif