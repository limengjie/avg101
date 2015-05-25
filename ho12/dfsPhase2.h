#include "intList.h"
#include "dfsTrace1.h"

#ifndef DFS2
#define DFS2

int * initDfstRoot(int);
void printArrays(int, int[], int[], int[]);
void printScc(int[], int);
int dfsT2(IntList[], int[], int, int,\
                      int[], int[], int[], int[], int);
void dfsTsweep2(IntList[], int, Stack *); 

#endif
