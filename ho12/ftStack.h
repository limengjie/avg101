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

//Constructor
//Precondition: None.
//Postcondition: if s = initStk() then:
//1.s refers to a newly created object.
//2.isEmpty(s) = true.
Stack * initStk();

//Access function
int isEmptyStk(Stack *);

//Access function
//Precondition: Stack is not nil.
//Postcondition: None.
void printStk(Stack *);

//Manipulation procedures
//Precondition: None.
//Postcondition: 
//1.Stack is not nil.
//2.topStk(s) = e.
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
