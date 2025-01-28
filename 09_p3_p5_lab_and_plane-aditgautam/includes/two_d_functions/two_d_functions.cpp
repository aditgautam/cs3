#include "two_d_functions.h"

using namespace std;

int array_size(int* sizes)
{
    return 0;

}
void print_array(int* a)
{

}
bool index_is_valid(int* sizes, int row, int col)
{
    int num_of_rows = get_num_rows(sizes);
    if( row >= num_of_rows)
    {
        return false;
    }
    for(int i = 0; i < row ; i++)
    {
        sizes++;                    //go to the column index
    }
    if(col >= *sizes)
    {
        return false;
    }
    return true;

}

int get_num_rows(int* sizes)
{
    int n = 0;                          //Initializing our counter for the sizes array
    while(*sizes != -1)                 //Sizes array will return a -1 when it terminates
    {
        n++;                            //Counts the number of rows. Now we have variable n stores for our number of rows
        sizes++;
    }
    return n;
}