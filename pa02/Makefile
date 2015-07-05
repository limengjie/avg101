# Makefile starter for pa01.

# See Cmake/Makefile for a complete commented sample Makefile,
# illustrating separate compilation and dependencies.

# Running "make" can generate many error messages.  Do
#	make intList.o >& make.log
# to compile intList.c and cause the errors to go into the file make.log.
# When "make" finishes you can read the file with "view", "more", or "less".
#
# Many later error messages can be meaningless because they were caused
# by an earlier error.  Always try to correct errors in order.
#
# Do 
#       make graph02 >& make.log
# to create the executable file graph02.
#
# ===================================================================

CC     = gcc
CFLAGS = -g -Wall -O0

intList.o:	intList.c  intList.h
	${CC}  -c  ${CFLAGS}  intList.c

graph02.o:	graph02.c  intList.h
	${CC}  -c  ${CFLAGS}  graph02.c

graph02:	graph02.o  intList.o
	${CC}  -o  graph02  graph02.o intList.o
