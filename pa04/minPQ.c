#include <stdlib.h>
#include <float.h>  //DBL_MAX
#include "minPQ.h"

struct MinPQNode {
	int numVertices; //total number of vertices
	int numPQ; //number of vertices in current priority queue
	int minVertex; //minVertex == -1 by default
	double oo; //infinite
	int * status;
	int * parent;
	double * fringeWgt;
};

int isEmptyPQ(MinPQ pq) {
	if (pq->numPQ == 0)
					return 1;
	return 0;
}

int getMin(MinPQ pq) {
	/*return fringe vertex with min weight*/
	/*return -1 if no fringe vertex remain*/
	if (pq->minVertex == -1) {
		int v;
		double minWgt = pq->oo;
		for(v = 1; v <= pq->numVertices; ++v) {
			if (pq->status[v] == FRINGE)
				if (pq->fringeWgt[v] < minWgt) {
					pq->minVertex = v;
					minWgt = pq->fringeWgt[v];
				}
		}
	}

	return pq->minVertex;
}

int getStatus(MinPQ pq, int id) {
	return pq->status[id];
}

int getParent(MinPQ pq, int id) {
	return pq->parent[id];
}

double getPriority(MinPQ pq, int id) {
	return pq->fringeWgt[id];
}

void delMin(MinPQ pq) {
	/*delete fringe vertex with min weight from pq*/
	int oldMin = getMin(pq);

	pq->status[oldMin] = INTREE;
	pq->minVertex = -1;
	pq->numPQ--;
}

 void insertPQ(MinPQ pq, int id, double priority, int par) {
	 /*record par, priority as parent, priority of id*/
	 /*and make status[id] = FRINGE*/
	 pq->parent[id] = par;
	 pq->fringeWgt[id] = priority;
	 pq->status[id] = FRINGE;
	 pq->minVertex = -1;
	 pq->numPQ++;
 }

void decreaseKey(MinPQ pq, int id, double priority, int par) {
	/*record par, priority as parent, priority of id*/
	pq->parent[id] = par;
	pq->fringeWgt[id] = priority;
	pq->minVertex = -1;
}
	


MinPQ createPQ(int n, int status[], double priority[], int parent[]) {
	MinPQ pq = (MinPQ)malloc(sizeof(struct MinPQNode));

	pq->parent = parent;
	pq->fringeWgt = priority;
	pq->status = status;
	pq->oo = DBL_MAX;
	pq->numVertices = n;
	pq->numPQ = 0;
	pq->minVertex = -1;

	/*initialize arrays*/
	int i;
	for(i = 0; i <= n; ++i) {
					pq->status[i] = UNSEEN;
					pq->fringeWgt[i] = pq->oo;
					pq->parent[i] = -1;
	}

	return pq;
}

