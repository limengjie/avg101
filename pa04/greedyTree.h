#ifndef __GreedyTree__
#define __GreedyTree__

#include <stdio.h>
#include "edgeList.h"
#include "minPQ.h"

int * initStatus(int);
int * initParent(int);
double * initFringeWgt(int);
void printArrays(int, int[], double[], int[]); //for debugging

double calcPriority(int, MinPQ, int, double);
void updateFringe(int, MinPQ, EdgeList, int);
void greedyTree(int, EdgeList[] , int, int, int[], double[], int[]);




#endif
