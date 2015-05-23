/* intList.h
 * (what is the purpose of this file?)
 */

#ifndef C101IntList
#define C101IntList
/* Multiple typedefs for the same type are an error in C. */

typedef struct IntListNode * IntList;


/** intNil denotes the empty IntList */
extern const IntList intNil;

/* Access functions
 */

/** first
 */
int intFirst(IntList oldL);

/** rest
 */
IntList intRest(IntList oldL);

/* Constructors
 */

/** cons
 */
IntList intCons(int newE, IntList oldL);

#endif

