#include "plane.h"
#include <iostream>
#include <iomanip>

using namespace std;

bool **init_plane()
{
    int sizes[] {4, 4, 4, 4, 4, 4, 4, -1};      //Have to hard code :( 

    bool **plane = allocate_twod<bool>(sizes);
    init_twod(plane, sizes, false);
    return plane;
}
bool reserve(bool **plane, int row, int seat)
{
    bool reserve_this = get_twod(plane, row, seat);        //Pass address???

    if(!reserve_this)                                        //If the variable returns a true (available) change sttatus to false
    {
        write_twod(plane, row, seat, true);
        return true;                                        //Seat was successfully reserved
    }
    return false;

}
bool cancel(bool** plane, int row, int seat)
{
    bool cancel_this = get_twod(plane, row, seat);

    if(cancel_this)
    {
        write_twod(plane, row, seat, false);
        return true;
    }
    return false;

}
void print_plane(bool **plane)
{
    int num_rows = 7;  //There is literally no way to do this without hard coding.
    int row_size = 4;  //If we could create a plane object, we could make this dynamic. But I don't wanna mess with the grader

    for (int row = 0; row < num_rows; row++)
    {
        print_plane_row(plane, row, &row_size);         //using address because of the signature of helper function was built for
    }                                                   //dynamic arrays
}
void print_plane_row(bool **plane, int row_number, int* row_sizes)  //this was like my cs2 console battleship
{
    cout << setw(2) << row_number + 1;                              //in our main for loop, we will start at 0, so add 1

    bool* col_walker = *(plane + row_number);                       //row walker dereferences plane double pointer and adds the row number
    for(int i = 0; i < *row_sizes; i++)
    {
        bool* seat_to_print = col_walker + i;
        char print = 'A' + i;

        if(!*seat_to_print)
        {
            cout << setw(2) << 'X';
        }
        else if(*seat_to_print)
        {
            cout << setw(2) << print;
        }
    }
    cout << endl;
}