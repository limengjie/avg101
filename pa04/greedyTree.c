#include <stdlib.h>
#include "minPQ.h" // unseen
#include "edgeList.h"
#include "greedyTree.h"

int * initStatus(int n) {
	int * status = (int *)malloc((n+1)*sizeof(int));
	return status;
}


int * initParent(int n) {
	int * parent = (int *)malloc((n+1)*sizeof(int));
	return parent;
}


double * initFringeWgt(int n) {
	double * wgt = (double *)malloc((n+1)*sizeof(double));
	return wgt;
}

void printArrays(int n, int * status, double * fringeWgt, int * parent) {
	puts("vertex\tstatus\tparent\tfringeWgt\t");
	int i;
	for(i = 1; i <= n; ++i) {
		printf("%d\t  %c\t  %d\t   %.2f\n",\
		       i, status[i], parent[i], fringeWgt[i]);
	} 
}

void greedyTree(int task, EdgeList * adjInfo, int n, int s,\
	     int * status, double * fringeWgt, int * parent) {
	MinPQ pq = createPQ(n, status, fringeWgt, parent);
	insertPQ(pq, s, 0.0, -1);
	while(!isEmptyPQ(pq)) {
		int v = getMin(pq);
		delMin(pq);
		updateFringe(task, pq, adjInfo[v], v);
	}

	free(pq);
}

void updateFringe(int task, MinPQ pq, EdgeList adjInfoOfV, int v) {
	/*see if a better connection is found to any vertex in*/
	/*the list adjInfoOfV and decreaseKey if so.*/
	/*For a new connection, insert the vertex.*/
	EdgeList remAdj;
	remAdj = adjInfoOfV;
	while(remAdj != edgeNil) {
		EdgeInfo wInfo = edgeFirst(remAdj);
		int w = wInfo.to;
		double wgt = wInfo.wgt;
		double newPrior = calcPriority(task, pq, v, wgt);
		if (getStatus(pq, w) == UNSEEN) 
			insertPQ(pq, w, newPrior, v);
		else if (getStatus(pq, w) == FRINGE) 
			if (newPrior < getPriority(pq, w))
			    decreaseKey(pq, w, newPrior, v);
		remAdj = edgeRest(remAdj);
	}
}

double calcPriority(int task, MinPQ pq, int v, double wgt) {
	if (task == 'P') 
		return wgt;
	else {
		double myDist = getPriority(pq, v);
		return (myDist + wgt);
	}
}


