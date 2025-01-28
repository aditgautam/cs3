#ifndef PLANE_H
#define PLANE_H
#include "../two_d_functions/two_d_functions.h"

bool **init_plane();
bool reserve(bool **plane, int row, int seat);
bool cancel(bool** plane, int row, int seat);
void print_plane(bool **plane);
void print_plane_row(bool **plane, int row_number, int* row_sizes);

#endif