#ifndef __GreedyTree__
#define __GreedyTree__

#include <stdio.h>
#include "edgeList.h"
#include "minPQ.h"

int * initStatus(int);
int * initParent(int);
double * initFringeWgt(int);
void printArrays(int, int[], double[], int[]); //for debugging

//<<<<<<< HEAD
double calcPriority(int, MinPQ, int, double);
void updateFringe(int, MinPQ, EdgeList, int);
void greedyTree(int, EdgeList[] , int, int, int[], double[], int[]);


//=======
//prim MST
void updateFringeP(MinPQ, EdgeList, int);
void primMST(EdgeList[] , int, int, int[], double[], int[]);

//dijkstra SSSP

void updateFringeD(MinPQ, EdgeList, int);
void shortestPath(EdgeList[] , int, int, int[], double[], int[]);
//>>>>>>> 087727c9e1b076c09f8dcd0afe4bcb7f8b9fc11f


#endif
