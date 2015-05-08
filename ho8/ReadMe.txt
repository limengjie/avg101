/////////////////////////////////////////////////////////////
# Mengjie Li   
# mli55@ucsc.edu
# CMPS 101 Spring 2015 - Intro to Algorithm
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


compile:

make intList.o
make graph02



main function:

We add two functions based on our last assignment.
After the graph is built, we transpose it and create a new graph called
tranGraph.
Then we use the hasCycle function to detect both the original graph and
transpose graph. To accomplish this goal, hasCylceLen function will be called
and use DFS to explore the depth from every node. If the depth is larger than
the number of nodes, there is a cycle found in the graph. 
Once it finds a cycle, it will print a vertex that might be in
that cycle.




usage:

./graph02 testfile



test files:

There are several test files in testFiles directory to test all kinds of problems.

In cycle0.in, cycle1.in and cycle2.in files, the function should be cable to
detect cycle.
In cycle1.in, there is an edge point to a node itself. In cycle2.in, there are
two nodes point to each other.

In nocycle0.in and nocycle1.in, no cycle should be detected.
In nocycle1.in, there is an edge out of range. We do not add it but print a
message and keep going.

The rest of input files are used for last assignment.
