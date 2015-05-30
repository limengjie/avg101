/* edgeList.h
 * (what is the purpose of this file?)
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
 * (what are the preconditions?)
 */

/** first
*/
EdgeInfo edgeFirst(EdgeList oldL);

/** rest
*/
EdgeList edgeRest(EdgeList oldL);

/* Constructors
 * (what are the preconditions and postconditions?)
 */

/** cons
*/
EdgeList edgeCons(EdgeInfo newE, EdgeList oldL);

#endif

