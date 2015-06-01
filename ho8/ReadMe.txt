/////////////////////////////////////////////////////////////
# pa02 
/////////////////////////////////////////////////////////////


Purpose:

The purpose of this assginment is to add two functions to pa01.
The first function will transpose a graph. The second function can detect cycle
in a graph and print a node which might be in the cycle.


files:

graph02.c
intList.h
intList.c
Makefile
testFiles 

graph02.c declares and defines the main function and other important functions
such as parseN, initEdges, loadEdges, print, transposeGraph, hasCycle and   hasCycleLen.

intList.c defines ADT's member functions such as intFirst, intRest and intCons.

intList.h remains the same according to the requirement.


compile:

make intList.o
make graph02



main function:

build graph:
Based on the second argument(argv[1]), we choose to read information from standard
input or files. Then we use parseN to parse the first line of the input file to get the
number of nodes in the graph. With the number of nodes, we can allocate a blank
space in heap for our graph with initEdges. Then we parse every edge using
parseEdges and add new edge to the graph with intCons. If the edge is
out of range, print a message and skip this edge. Print out the graph after it
is built with print.

We add two functions based on our last assignment.

transpose graph:
After the graph is built, we transpose it and create a new graph called
tranGraph.

detect cycle:
We use the hasCycle function to detect both the original graph and
transpose graph. To accomplish this goal, hasCylceLen function will be called
and use DFS to explore the depth from every node. It means that if there is a
recursive call in DFS, the variable sofar will be increased. When sofar is
larger than the number of nodes, there is a cycle found in the graph. 
Once it finds a cycle, it will print a vertex that might be in
that cycle and hasCycle will return 1.




usage:

./graph02 testfile



test files:

There are several test files in testFiles directory to test all kinds of problems.

In cycle0.in, cycle1.in and cycle2.in files, the function should be able to
detect cycle.
In cycle1.in, there is an edge point to a node itself. In cycle2.in, there are
two nodes point to each other.


In nocycle0.in and nocycle1.in, no cycle should be detected.
In nocycle1.in, there is an edge out of range. We do not add it but print a
message and keep going.


The rest of input files are used for last assignment.
