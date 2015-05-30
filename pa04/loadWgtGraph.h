#ifndef LOADGRAPH
#define LOADGRAPH

#include "edgeList.h"

//load and build graph
typedef struct {
	int from;                                                         
	int to;
	double weight;
} Edge;


FILE * open_file(char *);
EdgeList * initEdges(int); 
int parseN(char *);
Edge parseEdges(char *, int);
void loadEdges(char *, EdgeList[], int, int);
void printEdge(EdgeInfo);
void printGraph(EdgeList[], int);
//IntList * transposeGraph(IntList[], int);
//int hasCycle(IntList[], int);
//int hasCycleLen(IntList[], int, int, IntList);


#endif
