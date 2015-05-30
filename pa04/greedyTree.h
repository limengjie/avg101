#ifndef __GreedyTree__
#define __GreedyTree__

#include <stdio.h>
#include "edgeList.h"
#include "minPQ.h"

int * initStatus(int);
int * initParent(int);
double * initFringeWgt(int);
void printArrays(int, int[], double[], int[]); //for debugging

//prim MST
void updateFringeP(MinPQ, EdgeList, int);
void primMST(EdgeList[] , int, int, int[], double[], int[]);

//dijkstra SSSP

void updateFringeD(MinPQ, EdgeList, int);
void shortestPath(EdgeList[] , int, int, int[], double[], int[]);


#endif
