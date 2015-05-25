#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "loadGraph.h"


/*load and build graph*/

FILE * open_file(char * infile) {
	/*open a file*/
	FILE * fp; 
	fp = fopen(infile, "r");
	if (fp == NULL) {
		fprintf(stderr, "no such file!\n");
		exit(-1);
	}   
	printf("Opened %s for input\n", infile);

	return fp; 
}

IntList * initEdges(int n) {
	IntList * adjVs = (IntList *)calloc(n + 1, sizeof(IntList));
	int i;
	for (i = 1; i <= n; ++i) 
		adjVs[i] = NULL;
	return adjVs;
}


int parseN(char * line) {
	int num;
	char * lineTmp = strdup(line);
	char * w0 =  strtok(lineTmp, " \t\n");
	char * w1 =  strtok(NULL, " \t\n");

	if (w0 == NULL || w1 != NULL) {
		fprintf(stderr, "bad line 1: %s", line);
		exit(1);
	}

	num = atoi(w0);

	free(lineTmp);

	return num;
}

Edge parseEdges(char * line, int num) {
	Edge newE;
	char * lineTmp = strdup(line);
	char * w0 =  strtok(lineTmp, " \t\n");
	char * w1 =  strtok(NULL, " \t\n");
	char * w2 =  strtok(NULL, " \t\n");
	char * w3 =  strtok(NULL, " \t\n");

	if (w0 == NULL || w1 == NULL || w3 != NULL) {
		fprintf(stderr, "bad edge: %s", line);
		exit(1);
	}

	newE.from = atoi(w0);
	newE.to   = atoi(w1);

	/*ensure it won't lead to segmantation fault*/
	/*assert(newE.from > 0 && newE.from <= num);*/
	/*assert(newE.to > 0 && newE.to <= num);*/

	if (newE.from <= 0 || newE.from > num \
	    || newE.to <= 0 || newE.to > num) {
		fprintf(stderr, "Edge (%d, %d) is out of range\n",\
			newE.from,   newE.to);
		newE.from = 0;
		newE.to = 0;
	}  

	if (w2 != NULL)
		newE.weight = atof(w2);
	else
		newE.weight = 0.0;
	free(lineTmp);


	return newE;
}


void loadEdges(char * line, IntList * adjVs, int num) {

	/*parse line and get edges*/
	Edge e = parseEdges(line, num);

	/*use edges to get adjacency vertices list*/
	if (e.from != 0 && e.to != 0)
		adjVs[e.from] = intCons(e.to, adjVs[e.from]);

}


void printGraph(IntList * adjVs, int num) {                                     
	int i;

	printf("This graph has %d nodes.\n", num);
	for (i = 1; i <= num; ++i) {
		IntList pnode = adjVs[i];
		int init = 1;
		printf("%d\t", i);
		/*recursively print every node*/
		while (pnode) {
			if(init)
				printf("[");
			else
				printf(", ");
			printf("%d", intFirst(pnode));
			pnode = intRest(pnode);
			init = 0;
		}
		if (init)           // if the IntList is NULL 
			printf("NULL");
		else
			printf("]");
		printf("\n");
	}
	puts(" ");

}

IntList * transposeGraph(IntList *origGraph, int n) {
	int i;

	/*initialize a transpose graph*/
	IntList * tranG = initEdges(n);

	/*construct transpose graph */
	for (i = 1; i <= n; ++i) {
		IntList pnode = origGraph[i];
		while (pnode) {
			int newNode = intFirst(pnode);
			tranG[newNode] = intCons(i, tranG[newNode]);
			pnode = intRest(pnode);
		}
	}

	return tranG;

}

int hasCycle(IntList * origGraph, int n) {
	int isCycle;
	int i;

	/*apply the DFS to find out if it has cycle or not*/
	/*start from every node and get the longest distance it can reach*/
	for (i = 1; i <= n; ++i) {
		printf("root %d:\n", i);
		isCycle = hasCycleLen(origGraph, n, 0, origGraph[i]);
		if (isCycle) {
			return 1;
		}
	}
	return 0;
}

int hasCycleLen(IntList * origGraph, int n, int sofar, IntList v) {
	int node, vertex = 0;

	sofar++;
	while (v != NULL) {
		node = intFirst(v);
		if (sofar > n) {
			printf("node %d might be in the cycle\n", node);
			return node;
		}

		printf("currnet node: %d, sofar = %d\n", node, sofar);
		vertex = hasCycleLen(origGraph, n, sofar, origGraph[node]);

		if (vertex) 
			return vertex;

		v = intRest(v);

	}

	return 0;
}

