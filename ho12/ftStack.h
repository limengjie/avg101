#ifndef __stack__
#define __stack__

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

#endif
