#ifndef DFS1
#define DFS1

#include "intList.h"
#include "ftStack.h"

#define WHITE 0
#define GRAY  1
#define BLACK 2

//DFS

int * initColor(int);
int * initDiscoverTime(int);
int * initFinishTime(int);
int * initParent(int);

void printArrays(int, int[], int[], int[]);
Stack * dfsSweep1(IntList[], int);
int dfsTrace1(IntList[], int, int[], int[], int[],\
                              int[], Stack *, int);

#endif





