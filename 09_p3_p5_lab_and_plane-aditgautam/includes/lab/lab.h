#ifndef LAB_H
#define LAB_H

#include "../two_d_functions/two_d_functions.h"

int **init_lab(int* stations);
bool login(int** labs, int lab, int station, int id);
bool logout(int** labs, int* sizes, int id);
//I eat shit!!!!

#endif