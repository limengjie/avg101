#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
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
		/*int numFields;*/

		/*numFields = sscanf(line, "%d %d %lf %*s",\
		 * &newE.from, &newE.to, &newE.weight);*/
		/*if (numFields < 2 || numFields > 3) {*/
			/*printf("bad edge: %s", line);*/
			/*exit(1);*/
		/*}*/
		/*if (numFields == 2)*/
			/*newE.weight = 0.0;*/



		/*alternative way*/
		char * lineTmp = strdup(line);
		char * w0 =  strtok(line, " \t\n");
		char * w1 =  strtok(NULL, " \t\n");
		char * w2 =  strtok(NULL, " \t\n");
		char * w3 =  strtok(NULL, " \t\n");

		if (w0 == NULL || w1 == NULL || w3 != NULL) {
			printf("bad edge: %s", line);
			exit(1);
		}

		newE.from = atoi(w0);
		newE.to   = atoi(w1);
		if (w2 != NULL)
			newE.weight = atof(w2);
		else
			newE.weight = 0.0;
		free(lineTmp);



		printf("from:%d to:%d \n", newE.from, newE.to);

		return newE;
}

void loadEdges(char * line, IntList * adjVs) {

	/*parse line and get edges*/
	Edge e = parseEdges(line);

	/*use edges to get adjacency vertices list*/
	adjVs[e.from] = intCons(e.to, adjVs[e.from]);
	
}
	

void print(IntList * adjVs, int num) {
	int i;

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
		if (!init)                          // if the IntList is NULL 
			printf("]");
		printf("\n");
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
	/*printf("arguments = %d\n", args);*/
	if (args != 1) {
		fprintf(stderr, "Bad line 1: %s", line);
		exit(1);
	}
	printf("there are %d nodes\n", n);

	/*initialize the adjacency list*/
	IntList * adjVertices;
	adjVertices = initEdges(n);




	int edges = 0;
	// read file to buffer and parse each line
	while (fgets(line, sizeof(line), fp)) {
		++edges;
		loadEdges(line, adjVertices);
	}

	print(adjVertices, n);

	fclose(fp);
	free(adjVertices);


	return 0;
}
