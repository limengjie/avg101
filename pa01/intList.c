#include <stdlib.h>
#include "intList.h"

struct IntListNode {
	int node;
	IntList next;
};

typedef struct IntListNode IntListNode;

const IntList nil = NULL;




int intFirst(IntList oldL) {
	return oldL->node;
}

IntList intRest(IntList oldL) {
	return oldL->next;
}

IntList intCons(int newE, IntList oldL) {
	IntList newList = (IntList)calloc(1, sizeof(IntListNode));
	newList->node = newE;
	newList->next = oldL;
	return newList;
}


