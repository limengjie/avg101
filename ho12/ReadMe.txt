/////////////////////////////////////////////////////////////
# Mengjie Li   
# mli55@ucsc.edu
# CMPS 101 Spring 2015 - Intro to Algorithm
# pa03 
/////////////////////////////////////////////////////////////


Purpose:

The purpose of this assginment is to implement SCC algorithm.


files:

scc03.c
intList.h
intList.c
loadGraph.h
loadGraph.c
dfsTrace1.h
dfsTrace1.c
dfsPhase2.h
dfsPhase2.c
Makefile
testFiles 

In scc03.c, the main function is used to call diferent functions to complete
the scc algorithm.

intList.c defines ADT's member functions such as intFirst, intRest and intCons.
intList.h remains the same according to the requirement.

In loadGraph.h and loadGraph.c, functions such as parseN, initEdges, 
loadEdges, print, transposeGraph, hasCycle and hasCycleLen are declared and
defined to build the graph according to the input file.

In dfsTrace1.h and dfsTrace1.c, functions are defined and declared to 
accomplish the first phase of scc algorithm. 
initColor(int), initDiscoverTime(int), initFinishTime(int) and
initParent(int) are used to initialize those arrays will be used in DFS.
initStk, isEmptyStk, printStk, pushStk, topStk and popStk are use to 
manipulate the finish time stack.
Then call dfsSweep1 and dfsTrace1 to finish the DFS and push those vertices
into stack based on their finish time.

In dfsPhase2.h and dfsPhase2.c, functions are declared and defined to 
accomplish the second phase of scc algorithm. 
initDfstRoot function is used to record the leaders of each scc.
Call dfsTsweep2 and dfsT2 to accomplish DFS according to the order in 
finish time stack.






compile:

make scc03 


usage:

./scc03 testfile



test files:

There are 3 test files in testFiles directory. test.in is the given sample 
file. g711.in and g724.in are input files I made according to the graphs
7.11 and 7.24 in the textbook. 

