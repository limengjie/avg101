#include <stdlib.h>
#include "edgeList.h"

struct EdgeListNode {
	EdgeInfo elt;
	struct EdgeListNode * next;
};

typedef struct EdgeListNode EdgeListNode;

const EdgeList edgeNil = NULL;

EdgeInfo edgeFirst(EdgeList oldL) {
	return oldL->elt;
}

EdgeList edgeRest(EdgeList oldL) {
	return oldL->next;
}

EdgeList edgeCons(EdgeInfo newE, EdgeList oldL) {
        /*create a new EdgeInfo element*/
	EdgeList newList = (EdgeList)malloc(sizeof(EdgeListNode));
	newList->elt = newE;
	newList->next = oldL;

	/*add the new element to the list*/
	return newList;
}
	
