#include "lab.h"
#include <iostream>
#include <iomanip>

using namespace std;

int **init_lab(int* stations)
{
   int** lab = allocate_twod<int>(stations);
   init_twod(lab, stations, 0);
   return lab;
}
bool login(int** labs, int lab, int station, int id)
{
    // if(!index_is_valid(*labs, lab, station))
    // {
    //     return false;
    // }
    // if(search_twod(labs, *labs, id) != nullptr)
    // {
    //     return false;
    // }
    if(get_twod(labs, lab, station) == 0)
    {
        write_twod(labs, lab, station, id);
        return true;
    }
    return false;
}
bool logout(int** labs, int* sizes, int id)
{
    int row = 0;        //declaring the variables bc we will cheese two retuns from search
    int col = 0;

    if(search_twod(labs, sizes, id, row, col))  // row and col are reference, so if the bool returns true we have the location
    {
        write_twod(labs, row, col, 0);
        return true;
    }
    return false;
}