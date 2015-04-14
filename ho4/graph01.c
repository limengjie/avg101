#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intList.h"

typedef struct {
	int from;
	int to;
	double weight;
} Edge;


IntList * initEdges(int n) {
	IntList * adjVs = (IntList *)calloc(n + 1, sizeof(IntList));
	int i;
	for (i = 1; i <= n; ++i) 
		adjVs[i] = NULL;
	return adjVs;
}

Edge parseEdges(char * line) {
		Edge newE;

		int numFields;

		numFields = sscanf(line, "%d %d %lf %*s", &newE.from, &newE.to, &newE.weight);
		if (numFields < 2 || numFields > 3) {
			printf("bad edge: %s", line);
			exit(1);
		}

		if (numFields == 2)
			newE.weight = 0.0;

		/*printf("from:%d to:%d \n", newE.from, newE.to);*/

		return newE;
}

void loadEdges(char * line, IntList * adjVs) {
	Edge e = parseEdges(line);
	adjVs[e.from] = intCons(e.to, adjVs[e.from]);
	
}
	

void print(IntList * adjVs, int num) {
	int i;

	for (i = 1; i <= num; ++i) {
		IntList pnode = adjVs[i];
		int init = 1;
		printf("%d\t", i);
		while (pnode) {
			if(init)
				printf("[");
			else
				printf(", ");
			printf("%d", pnode->node);
			pnode = pnode->next;
			init = 0;
		}
		if (!init)                          // if the IntList is NULL 
			printf("]\n");
	}

}

int main(int argc, char* argv[]) {

	if (argc != 2) {
		fprintf(stderr, "Usage: graph01 input.data \n");
		exit(0);
	}




        //open a file
	char * infile = argv[1];
	FILE * fp;
	fp = fopen(infile, "r");
	if (fp == NULL) {
		fprintf(stderr, "no such file!\n");
		exit(-1);
	}
	printf("Opened %s for input\n", infile);





	char line[1024];
	char * fgetsRetn;
	/*read and parse n*/
	int n, args;
	fgetsRetn = fgets(line, sizeof(line), fp);
	args = sscanf(line, "%d %*s",  &n);
	printf("arguments = %d\n", args);
	if (args != 1) {
		fprintf(stderr, "Bad line 1: %s", line);
		exit(1);
	}
	printf("there are %d nodes\n", n);

	/*initialize the adjacency list*/
	IntList * adjVertices;
	adjVertices = initEdges(n);




	int edges = 0;
	// read file to buffer
	while (fgets(line, sizeof(line), fp)) {
		++edges;
		/*printf("size of the line is %d\n", sizeof(line));*/
		loadEdges(line, adjVertices);
		/*Edge e;*/
		/*e = parseEdges(line);*/
	}

	print(adjVertices, n);

	return 0;
}
