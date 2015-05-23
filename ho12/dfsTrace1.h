#include "intList.h"

#ifndef DFS1
#define DFS1

//load and build graph
typedef struct {                                                                
   int from;
   int to;
   double weight;
} Edge;


FILE * open_file(char *);
IntList * initEdges(int);
int parseN(char *);
Edge parseEdges(char *, int);
void loadEdges(char *, IntList[], int);
void printGraph(IntList[], int);
IntList * transposeGraph(IntList[], int);
int hasCycle(IntList[], int);
int hasCycleLen(IntList[], int, int, IntList);


//DFS
int * initColor(int);
int * initDiscoverTime(int);
int * initFinishTime(int);
int * initParent(int);
int * initFinishStk(int);
int * dfsSweep1(IntList[], int);
int dfsTrace1(IntList[], int, int[], int[], int[],\
                              int[], int[], int);

//dfsPhase2
int * initDfstRoot(int);
void printArrays(int, int[], int[], int[]);
void printStk(int[], int);
void printScc(int[], int);
int dfsT2(IntList[], int[], int, int,\
      int[], int[], int[], int[], int);
void dfsTsweep2(IntList [], int, int []);


#endif





