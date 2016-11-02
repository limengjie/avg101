#include <stdio.h>
#include <stdlib.h>
#include "ftStack.h"

Stack * initStk() {
	Stack * stk = (Stack *)malloc(sizeof(Stack));
	stk->last = NULL;
	stk->size = 0;

	return stk;
}

int isEmptyStk(Stack * stk) {
	if (stk->size == 0)
		return 1;
	else
		return 0;
}

void printStk(Stack * stk) {
	if (isEmptyStk(stk)) {
		puts("Empty stack");
		return;
	}   

	FinishTime * ft = stk->last;
	puts("=====================Stack=====================");
	while(ft) {
		printf("%d\n", ft->vertex);
		ft = ft->prev;
	}
	puts("___\nstk\n");
}

void pushStk(Stack * stk, int elt) {
	/*create a new FinishTime*/
	FinishTime * newElt = (FinishTime *)malloc(sizeof(FinishTime));

	newElt->next = NULL;
	newElt->vertex = elt;
	newElt->prev = stk->last;
	if (!isEmptyStk(stk)) {
		(stk->last)->next = newElt;
	}
	stk->last = newElt;
	stk->size++;
}


int topStk(Stack * stk) {
	if (isEmptyStk(stk))
		return -1;
	else
		return (stk->last)->vertex;
}

void popStk(Stack * stk) {
	if (isEmptyStk(stk))
		return;

	FinishTime * top = stk->last;
	stk->last = top->prev;
	free(top);
	stk->size--;
}

