#include "intList.h"
//#include "loadGraph.h"

#ifndef DFS1
#define DFS1

#define WHITE 0
#define GRAY  1
#define BLACK 2



//DFS


int * initColor(int);
int * initDiscoverTime(int);
int * initFinishTime(int);
int * initParent(int);
int * initFinishStk(int);


struct finishTime
{
   int time;
   struct finishTime * prev;
   struct finishTime * next;
};

typedef struct finishTime FinishTime;

typedef struct
{
   int size;
   FinishTime * last;
} Stack;

Stack * initStk();
int isEmptyStk(Stack *);
void printStk(Stack *);
void pushStk(Stack *, int);
int topStk(Stack *);
void popStk(Stack *);


void printArrays(int, int[], int[], int[]);
Stack * dfsSweep1(IntList[], int);
int dfsTrace1(IntList[], int, int[], int[], int[],\
                              int[], Stack *, int);


#endif





