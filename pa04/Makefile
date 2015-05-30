CSOURCE = edgeList.c loadWgtGraph.c minPQ.c greedyTree.c graph04.c
CHEADER = edgeList.h loadWgtGraph.h minPQ.h greedyTree.h
OBJECTS = ${CSOURCE:.c=.o}
EXEBIN = graph04
COMPILEC = gcc -g -Wall -O0
${EXEBIN} : ${OBJECTS}
	${COMPILEC} -o $@ ${OBJECTS}
%.o : %.c
	${COMPILEC} -c $<


clean:
	- rm ${OBJECTS}
