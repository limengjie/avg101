#include "intList.h"

#ifndef LOADGRAPH
#define LOADGRAPH

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


#endif
