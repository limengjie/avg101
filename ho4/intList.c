#include <stdlib.h>
#include "intList.h"

struct IntListNode {
	int node;
	IntList next;
};

/*intNil->next = NULL;*/
/*intNil->node = 0;*/

int intFirst(IntList oldL) {
	return oldL->node;
}

IntList intRest(IntList oldL) {
	return oldL->next;
}

IntList intCons(int newE, IntList oldL) {
	IntList n = oldL;
	while(n->next != 0) {
		if (n->node == newE) 
			break;
		n = n->next;
	}

	if (n->next == NULL && n->node == 0) 
		n->node = newE;
	else {
		/*create a new node*/
		/*IntList newNode = (IntList)calloc(IntListNode);*/
		/*n->next = newNode;*/
		/*newNode->node = newE;*/
		/*newNode->next = NULL;*/
	}

	return oldL;
}


