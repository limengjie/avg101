/* edgeList.h
 * This file is used to declare the constructors, manipulation procedures 
 * and access functions for ADT.
 */

#ifndef C101EdgeList
#define C101EdgeList
/* Multiple typedefs for the same type are an error in C. */

typedef struct EdgeListNode * EdgeList;

typedef struct EdgeInfoStruct
    {
    int to;
    double wgt;
    }
    EdgeInfo;

/** edgeNil denotes the empty EdgeList */
extern const EdgeList edgeNil;

/* Access functions
 * Precondition: OldL is not nil.
 * Return: first element of oldL.
*/

/** first
*/
EdgeInfo edgeFirst(EdgeList oldL);

/** rest
*/
EdgeList edgeRest(EdgeList oldL);

/* Constructors
  * Precondition: None.
  * Postcondition: Let newL be the return value of cons.
  * Then: newL refers to a new object, newL is not nil.
  * edgeFirst(newL) = newE, edgeRest(newL) = oldL.
 */

/** cons
*/
EdgeList edgeCons(EdgeInfo newE, EdgeList oldL);

#endif

