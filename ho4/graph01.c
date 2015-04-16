#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
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
	/*int numFields;*/

	/*numFields = sscanf(line, "%d %d %lf %*s",\*/
	 /*&newE.from, &newE.to, &newE.weight);*/
	/*if (numFields < 2 || numFields > 3) {*/
		/*printf("bad edge: %s", line);*/
		/*exit(1);*/
	/*}*/
	/*if (numFields == 2)*/
		/*newE.weight = 0.0;*/


	/*alternative way*/
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
	assert(newE.from > 0 && newE.from <= num);
	assert(newE.to   > 0 && newE.to   <= num);

	if (w2 != NULL)
		newE.weight = atof(w2);
	else
		newE.weight = 0.0;
	free(lineTmp);



	/*printf("from:%d to:%d \n", newE.from, newE.to);*/

	return newE;
}

void loadEdges(char * line, IntList * adjVs, int num) {

	/*parse line and get edges*/
	Edge e = parseEdges(line, num);

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
		if (init)                          // if the IntList is NULL 
			printf("NULL");
		else
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





	/*read and parse n*/
	char line[1024];
	char * fgetsRetn;
	int n;
	fgetsRetn = fgets(line, sizeof(line), fp);
	if (!fgetsRetn)
		fprintf(stderr, "empty file\n");
	n = parseN(line);



	/*initialize the adjacency list*/
	IntList * adjVertices;
	adjVertices = initEdges(n);



	// read file to buffer and parse each line
	int edges = 0;
	while (fgets(line, sizeof(line), fp)) {
		++edges;
		loadEdges(line, adjVertices, n);
	}


	/*print the resulct*/
	printf("%d nodes\n", n);
	printf("%d edges\n", edges);
	print(adjVertices, n);

	
	/*clean up before leaving*/
	fclose(fp);
	free(adjVertices);


	return 0;
}
