/////////////////////////////////////////////////////////////
# pa01 
/////////////////////////////////////////////////////////////


Purpose:

The purpose of this assginment is to read all lines from a file and transfer it into a graph.


files:

graph01.c
intList.h
intList.c
Makefile
testFiles directory


compile:

make intList.o
make graph01


usage:

./graph01 testfile



test files:

There are several test files in testFiles directory to test all kinds of problems.

In nodeErr.in file, the first line has more than one arguments. 
run:
./graph01 ./testFiles/nodeErr.in

In edgeErr.in file, there are more than 3 arguments in a line. 
run:
./graph01 ./testFiles/edgeErr.in

In outofrange.in file, there is a node whose value is larger than the number of nodes. 
run:
./graph01 ./testFiles/outofrange.in

Files test.in, weighted.in and gr02test0.in are correct.
run:
./graph01 ./testFiles/test.in
./graph01 ./testFiles/weighted.in
./graph01 ./testFiles/gr02test0.in
