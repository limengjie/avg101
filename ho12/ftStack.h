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

//Access function
int isEmptyStk(Stack *);

//Access function
//Precondition: Stack is not nil.
//Postcondition: None.
void printStk(Stack *);

//Manipulation procedures
//Precondition: None.
//Postcondition: Stack is not nil.
void pushStk(Stack *, int);

//Access function
//Precondition: stack is not nil.
//return: the first element's time, return -1 if stack is nil.
int topStk(Stack *);

//Manipulation procedures
//Precondition: Stack is not nil.
//Postcondition: None.
void popStk(Stack *);

#endif
