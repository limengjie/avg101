/* intList.h
 */

#ifndef C101IntList
#define C101IntList
/* Multiple typedefs for the same type are an error in C. */

typedef struct IntListNode * IntList;


/** intNil denotes the empty IntList */
extern const IntList intNil;

/* Access functions
 * Precondition: OldL is not nil.
 * Return: first element of oldL.
 */

/** first
 */
int intFirst(IntList oldL);

/** rest
 * Access functions
 * Precondition: OldL is not nil.
 * Return: list of all elements of L, except 1st.
 */
IntList intRest(IntList oldL);

/* Constructors
 * Precondition: None.
 * Postcondition: Let newL be the return value of cons.
 * Then: newL refers to a new object, newL is not nil.
 * first(newL) = newE, rest(newL) = oldL.
 */

/** cons
 */
IntList intCons(int newE, IntList oldL);

#endif

