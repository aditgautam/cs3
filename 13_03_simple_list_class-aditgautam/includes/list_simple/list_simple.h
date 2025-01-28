#include "../linked_list_functions/linked_list_functions.h"

template <class ITEM_TYPE>
class List
{
public:
    List();

    ~List();
    List(const List<ITEM_TYPE> &copyThis);
    List& operator =(const List& RHS);

    node<ITEM_TYPE>* insert_head(ITEM_TYPE i);           //inset i at the head of list

    node<ITEM_TYPE>* insert_after(ITEM_TYPE i,           //insert i after iMarker
                                 node<ITEM_TYPE>* iMarker);

    node<ITEM_TYPE>* insert_before(ITEM_TYPE i,          //insert i before iMarker
                                  node<ITEM_TYPE>* iMarker);

    node<ITEM_TYPE>* insert_sorted(ITEM_TYPE i);         //insert i. Assume sorted list



    ITEM_TYPE Delete(node<ITEM_TYPE>* iMarker);         //delete node pointed to by iMarker


    void Print() const;                                 //print the list

    node<ITEM_TYPE>* search(const ITEM_TYPE &key);      //return pointer to node containing
                                                        //  key. NULL if not there

    node<ITEM_TYPE>* prev(node<ITEM_TYPE>* iMarker);    //get the previous node to iMarker


    ITEM_TYPE& operator[](int index);                   //return the item at index

    node<ITEM_TYPE>* begin() const;                     //return the head of the list

    node<ITEM_TYPE>* end() const;                       
                                                        
    bool empty() const { return head == nullptr; }      
    
    int size() const{ return _size; }
    template <class U>
    friend ostream& operator <<(ostream& outs,          //insertion operator for list
                                const List<U>& l);
private:
    node<ITEM_TYPE>* head;
    int _size;
};

template <class ITEM_TYPE>
List<ITEM_TYPE>::List()
{
    head = nullptr;
    _size = 0;
}

template <class ITEM_TYPE>
List<ITEM_TYPE>::~List()
{
    _clear_list(head);
    _size = 0;
}

template <class ITEM_TYPE>
List<ITEM_TYPE>::List(const List<ITEM_TYPE> &copyThis)
{
    _size = copyThis._size;
    head = _copy_list(copyThis.head);
}

template <class ITEM_TYPE>
List<ITEM_TYPE>& List<ITEM_TYPE>:: operator =(const List& RHS)
{
    if(&RHS == this)
    {
        return *this;
    }
    _clear_list(head);
    _size = RHS._size;
    head = _copy_list(RHS.head);
    return *this;
}

template <class ITEM_TYPE>
node<ITEM_TYPE>* List<ITEM_TYPE>::insert_head(ITEM_TYPE i)
{
    _size++;
    return _insert_head(head, i);
}

template <class ITEM_TYPE>
node<ITEM_TYPE>* List<ITEM_TYPE>::insert_after(ITEM_TYPE i, node<ITEM_TYPE>* iMarker)
{
    _size++;
    return _insert_after(head, iMarker, i);
}

template <class ITEM_TYPE>
node<ITEM_TYPE>* List<ITEM_TYPE>::insert_before(ITEM_TYPE i, node<ITEM_TYPE>* iMarker)
{
    _size++;
    return _insert_before(head, iMarker, i);
}

template <class ITEM_TYPE>
node<ITEM_TYPE>* List<ITEM_TYPE>::insert_sorted(ITEM_TYPE i)
{
    _size++;
    return _insert_sorted(head, i);
}

template <class ITEM_TYPE>
ITEM_TYPE List<ITEM_TYPE>::Delete(node<ITEM_TYPE>* iMarker)
{
    _size--;
    return _delete_node(head, iMarker);
}

template <class ITEM_TYPE>
void List<ITEM_TYPE>::Print() const
{
    _print_list(head);
}

template <class ITEM_TYPE>
node<ITEM_TYPE>* List<ITEM_TYPE>::search(const ITEM_TYPE &key)
{
    return _search_list(head, key);
}

template <class ITEM_TYPE>
node<ITEM_TYPE>* List<ITEM_TYPE>::prev(node<ITEM_TYPE>* iMarker)
{
    return _previous_node(head, iMarker);
}

template <class ITEM_TYPE>
ITEM_TYPE& List<ITEM_TYPE>::operator[](int index)
{
    return _at(head, index);
}

template <class ITEM_TYPE>
node<ITEM_TYPE>* List<ITEM_TYPE>:: begin() const
{
    return head;
}

template <class ITEM_TYPE>
node<ITEM_TYPE>* List<ITEM_TYPE>:: end() const
{
    // node<ITEM_TYPE>* node_walker = head;
    // while(node_walker -> _next != nullptr)
    // {
    //     node_walker = node_walker -> _next;
    // }
    // return node_walker;
    return nullptr;
}

template <class U>
ostream& operator <<(ostream& outs, const List<U>& l)
{
    node<U>* node_walker = l.head;
    while(node_walker != nullptr)
    {
        outs << setw(5) << *node_walker;
        node_walker = node_walker -> _next;
    }
    outs << endl;
    return outs;
}












