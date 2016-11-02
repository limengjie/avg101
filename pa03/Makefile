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
#       make scc03 >& make.log
# to create the executable file scc03.
#
# ===================================================================

#CC     = gcc
#CFLAGS = -g -Wall -O0


#intList.o:	intList.c  intList.h
	#${CC}  -c  ${CFLAGS}  intList.c

#disTrace1.o:	dfsTrace1.c  dfsTrace1.h
	#${CC}  -c  ${CFLAGS}  dfsTrace1.c

#scc03.o:	scc03.c  intList.h dfsTrace1.h
	#${CC}  -c  ${CFLAGS}  scc03.c

#scc03:	scc03.o  intList.o 
	#${CC}  -o  scc03  scc03.o intList.o dfsTrace1.o

CSOURCE = intList.c loadGraph.c ftStack.c dfsTrace1.c dfsPhase2.c scc03.c
CHEADER = intList.h loadGraph.h ftStack.h dfsTrace1.h dfsPhase2.h
OBJECTS = ${CSOURCE:.c=.o}
EXEBIN = scc03
COMPILEC = gcc -g -Wall -O0
${EXEBIN} : ${OBJECTS}
	${COMPILEC} -o $@ ${OBJECTS}
%.o : %.c
	${COMPILEC} -c $<


clean:
	- rm ${OBJECTS} ${EXEBIN}
