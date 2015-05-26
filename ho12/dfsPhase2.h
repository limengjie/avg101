#ifndef DFS2
#define DFS2

#include "intList.h"
#include "ftStack.h"
#include "dfsTrace1.h"

int * initDfstRoot(int);
void printScc(int[], int);
int dfsT2(IntList[], int[], int, int,\
                      int[], int[], int[], int[], int);
void dfsTsweep2(IntList[], int, Stack *); 

#endif
