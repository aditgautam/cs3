#ifndef LINKED_LIST_FUNCTIONS_H
#define LINKED_LIST_FUNCTIONS_H

#include <iostream>
#include <iomanip>
#include <cassert>
#include "../node/node.h"

//Linked List General Functions:
template <typename ITEM_TYPE>
void _print_list(node<ITEM_TYPE>* head);

//recursive fun! :)
template <typename ITEM_TYPE>
void _print_list_backwards(node<ITEM_TYPE> *head);

//return ptr to key or NULL
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _search_list(node<ITEM_TYPE>* head, ITEM_TYPE key);


template <typename ITEM_TYPE>
node<ITEM_TYPE>* _insert_head(node<ITEM_TYPE> *&head, ITEM_TYPE insert_this);

//insert after ptr
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _insert_after(node<ITEM_TYPE>*& head, node<ITEM_TYPE> *after_this, ITEM_TYPE insert_this);

//insert before ptr
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _insert_before(node<ITEM_TYPE>*& head, node<ITEM_TYPE>* before_this, ITEM_TYPE insert_this);

//ptr to previous node
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _previous_node(node<ITEM_TYPE>* head, node<ITEM_TYPE>* prev_to_this);

//delete, return item
template <typename ITEM_TYPE>
ITEM_TYPE _delete_node(node<ITEM_TYPE>*&head, node<ITEM_TYPE>* delete_this);

//duplicate the list...
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _copy_list(node<ITEM_TYPE>* head);

//duplicate list and return the last node of the copy
template <typename T>
node<T> *_copy_list(node<T>* &dest, node<T> *src);


//delete all the nodes
template <typename ITEM_TYPE>
void _clear_list(node<ITEM_TYPE>*& head);

//_item at this position
template <typename ITEM_TYPE>
ITEM_TYPE& _at(node<ITEM_TYPE>* head, int pos);

//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
//      Sorted List Routines. order: 0: ascending, order: other: descending
//                              Assume a Sorted List
//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _insert_sorted(node<ITEM_TYPE>* &head, ITEM_TYPE item, bool ascending=false);

//insert or add if a dup
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _insert_sorted_and_add(node<ITEM_TYPE>* &head, ITEM_TYPE item, bool ascending=false);

//node after which this item goes order: 0 ascending
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _where_this_goes(node<ITEM_TYPE>* head, ITEM_TYPE item, bool ascending=false);

//Last Node in the list
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _last_node(node<ITEM_TYPE>* head);            //never use this function.

//-------------------------------------------------------------------------------------------------------------

//Linked List General Functions:
template <typename ITEM_TYPE>
void _print_list(node<ITEM_TYPE>* head)
{
    if(head == nullptr)
    {
        cout << "Cannot print an empty list" << endl;
        return;
    }
    node<ITEM_TYPE>* node_walker = head;

    while(node_walker != nullptr)
    {
        cout << setw(4) << *node_walker;
        node_walker = node_walker -> _next;
    }
    cout << endl;
}

    //recursive fun! :)
template <typename ITEM_TYPE>
void _print_list_backwards(node<ITEM_TYPE> *head)
{
    if(head == nullptr)
    {
        cout << "Cannot print an empty list " << endl;
    }

    _print_list_backwards(head -> _next);

    cout << setw(4) << head ->_item;
}


    //return ptr to key or NULL
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _search_list(node<ITEM_TYPE>* head, ITEM_TYPE key)
{
    node<ITEM_TYPE>* node_walker = head;
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


template <typename ITEM_TYPE>
node<ITEM_TYPE>* _insert_head(node<ITEM_TYPE> *&head, ITEM_TYPE insert_this)
{
    node<ITEM_TYPE>* new_head = new node<ITEM_TYPE>(insert_this, head);
    head = new_head;
    return head;
}

    //insert after ptr
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _insert_after(node<ITEM_TYPE>*& head, node<ITEM_TYPE> *after_this, ITEM_TYPE insert_this)
{
    if(after_this == nullptr)
    {
        // cout << "Insert after: after_this is nullptr, inserting head" << endl;
        return _insert_head(head, insert_this);
    }
    if(head == nullptr)
    {
        // cout << "Insert after: head is nullptr, inserting head" << endl;
        return _insert_head(head, insert_this);
    }
    // cout << "Insert after making it where it needs to be " << endl;
    node<ITEM_TYPE>* new_node = new node<ITEM_TYPE>(insert_this, after_this -> _next);
    after_this -> _next = new_node;
    return new_node;
}

    //insert before ptr
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _insert_before(node<ITEM_TYPE>*& head, node<ITEM_TYPE>* before_this, ITEM_TYPE insert_this)
{
    if(head == before_this || head == nullptr || before_this == nullptr)
    {
        return _insert_head(head, insert_this);
    }

    node<ITEM_TYPE>* previous_node = _previous_node(head, before_this);

    if(previous_node != nullptr)
    {
        return _insert_after(head, previous_node, insert_this);
    }

    return nullptr;
}

    //ptr to previous node
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _previous_node(node<ITEM_TYPE>* head, node<ITEM_TYPE>* prev_to_this)
{
    if(head == nullptr)
    {
        return nullptr;
    }
    if(head == prev_to_this)
    {
        return nullptr;
    }

    node<ITEM_TYPE>* node_walker = head;

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
template <typename ITEM_TYPE>
ITEM_TYPE _delete_node(node<ITEM_TYPE>*&head, node<ITEM_TYPE>* delete_this)
{
    assert(head != nullptr && "List is empty, cannot delete");
    ITEM_TYPE item_to_return = delete_this -> _item;

    if(delete_this == nullptr)
    {
        return ITEM_TYPE();         //default item type
    }

    if(head == delete_this)
    {
        head = head -> _next;
    }
    else
    {
        node<ITEM_TYPE>* previous_node = _previous_node(head, delete_this);

        assert(previous_node != nullptr && "Previous node did not return a pointer");
        previous_node -> _next = delete_this -> _next;
        
    }

    delete delete_this;
    return item_to_return;
}


    //duplicate the list...
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _copy_list(node<ITEM_TYPE>* head)
{
    if(head == nullptr)
    {
        return nullptr;
    }

    node<ITEM_TYPE>* new_head = new node<ITEM_TYPE>(head -> _item, nullptr);
    
    node<ITEM_TYPE>* node_walker = head-> _next;

    node<ITEM_TYPE>* new_node_walker = new_head;

    while(node_walker != nullptr)
    {
        new_node_walker -> _next = new node<ITEM_TYPE>(node_walker -> _item, nullptr);
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
template <typename ITEM_TYPE>
void _clear_list(node<ITEM_TYPE>*& head)
{
    node<ITEM_TYPE>* node_walker = head;
    while(node_walker != nullptr)
    {
        node<ITEM_TYPE>* next_node = node_walker -> _next;
        delete node_walker;
        node_walker = next_node;
    }
    head = nullptr;
}

    //_item at this position
template <typename ITEM_TYPE>
ITEM_TYPE& _at(node<ITEM_TYPE>* head, int pos)
{
    assert(head != nullptr && "Head of the array does not exist");
    node<ITEM_TYPE>* node_walker = head;

    for(int i = 0; i < pos; i++)
    {
        assert(node_walker -> _next != nullptr && "Item is out of range");
        node_walker = node_walker -> _next;
    }
    return node_walker -> _item;
}

template <typename ITEM_TYPE>
const ITEM_TYPE& _at(const node<ITEM_TYPE>* head, int pos) {
    assert(head != nullptr && "Head of the array does not exist");
    const node<ITEM_TYPE>* node_walker = head;

    for (int i = 0; i < pos; i++) {
        assert(node_walker->_next != nullptr && "Item is out of range");
        node_walker = node_walker->_next;
    }
    return node_walker->_item;
}

    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
    //      Sorted List Routines. order: 0: ascending, order: other: descending
    //                              Assume a Sorted List
    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _insert_sorted(node<ITEM_TYPE>* &head, ITEM_TYPE item, bool ascending)
{
    if(head == nullptr)
    {
        // cout << "List was empty, inserting head" << endl;
        return _insert_head(head, item);
    }
    // if(ascending)
    // {
    //     // cout << "Ascending, inserting after" << endl;
    //     return _insert_after(head, _where_this_goes(head, item), item);
    // }
    // else if(!ascending)
    // {
    //     cout << "Descending, inserting after " << endl;
    //     return _insert_after(head, _where_this_goes(head, item, false), item);
    // }
    // return nullptr;
    return _insert_after(head, _where_this_goes(head, item, ascending), item);
}

    //insert or add if a dup
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _insert_sorted_and_add(node<ITEM_TYPE>* &head, ITEM_TYPE item, bool ascending)
{
    // if(head == nullptr)
    // {
    //     // cout << "Empty list, inserting at head" << endl;
    //     return _insert_head(head, item);
    // }
    
    node<ITEM_TYPE>* where = _search_list(head, item);

    if(where == nullptr){
        // cout << "Couldnt find where to insert and add, inserting sorted : " << endl;
        return _insert_sorted(head, item, ascending);
    }

    // cout << "Found where to insert and add, currently there is: " << where -> _item << endl;
    // cout << "adding " << item << endl;

    where -> _item = (where -> _item) + item; 
    return where;
}
    
    //node after which this item goes order: 0 ascending
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _where_this_goes(node<ITEM_TYPE>* head, ITEM_TYPE item, bool ascending)
{
    if(head == nullptr)
    {
        return nullptr;
    }
    node<ITEM_TYPE>* walker = head;
    if(ascending)
    {
        // cout << "Where this goes ascending" << endl;
        while( walker -> _next != nullptr && item > (walker-> _next -> _item))
        {
            walker = walker -> _next;
        }
    }
    else
    {
        // cout << "Where this goes not ascending " << endl;
        if(item > head -> _item)
        {
            return nullptr;
        }
        while( walker -> _next != nullptr && item < (walker-> _next -> _item))
        {
            // cout << "yo" << endl;
            walker = walker -> _next;
        }
    }
    return walker;
}
    //Last Node in the list

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _last_node(node<ITEM_TYPE>* head)
{
    node<ITEM_TYPE>* walker = head;
    while(walker -> _next != nullptr)
    {
        walker = walker -> _next;
    }
    return walker;
}            //never use this function.

#endif