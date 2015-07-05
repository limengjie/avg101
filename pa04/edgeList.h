/* edgeList.h
<<<<<<< HEAD
 * This file is used to declare the constructors, manipulation procedures 
 * and access functions for ADT.
=======
 * (what is the purpose of this file?)
>>>>>>> 087727c9e1b076c09f8dcd0afe4bcb7f8b9fc11f
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
<<<<<<< HEAD
 * Precondition: OldL is not nil.
 * Return: first element of oldL.
*/
//=======
 //* (what are the preconditions?)
 //*/
//>>>>>>> 087727c9e1b076c09f8dcd0afe4bcb7f8b9fc11f

/** first
*/
EdgeInfo edgeFirst(EdgeList oldL);

/** rest
*/
EdgeList edgeRest(EdgeList oldL);

/* Constructors
<<<<<<< HEAD
  * Precondition: None.
  * Postcondition: Let newL be the return value of cons.
  * Then: newL refers to a new object, newL is not nil.
  * edgeFirst(newL) = newE, edgeRest(newL) = oldL.
=======
 * (what are the preconditions and postconditions?)
>>>>>>> 087727c9e1b076c09f8dcd0afe4bcb7f8b9fc11f
 */

/** cons
*/
EdgeList edgeCons(EdgeInfo newE, EdgeList oldL);

#endif

