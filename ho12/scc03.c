#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include "intList.h"
#include "dfsTrace1.h"
#include "dfsPhase2.h"


int main(int argc, char* argv[]) {

	if (argc != 2) {
		fprintf(stderr, "Usage: graph01 input.data \n");
		exit(0);
	}


	/*open a file*/
	FILE * fp;
	if (strcmp(argv[1], "-"))  //build graph from file
		fp = open_file(argv[1]);
	else  // build graph from stdin
		fp = stdin;


	/*read and parse n*/
	char line[1024];
	int n;
	char * fgetsRetn;
	fgetsRetn = fgets(line, sizeof(line), fp);
	if (!fgetsRetn)
		fprintf(stderr, "empty file\n");
	n = parseN(line);


	/*initialize the adjacency list*/
	IntList * adjVertices;
	adjVertices = initEdges(n);


	/*read file to buffer and parse each line*/
	while (fgets(line, sizeof(line), fp)) {
		loadEdges(line, adjVertices, n);
	}


	/*print the result*/
	puts("=====================original graph================== ");
	printGraph(adjVertices, n);



	/*scc phase 1*/
	Stack * finishStk1 = dfsSweep1(adjVertices, n);

	/*print out the stack*/
	printStk(finishStk1);



	/*transpose a graph*/
	IntList * tranGraph = transposeGraph(adjVertices, n);
	puts("=====================transpose graph=====================");
	printGraph(tranGraph, n);


	/*scc phase 2*/
	dfsTsweep2(tranGraph, n, finishStk1);


	/*clean up before leaving*/
	fclose(fp);
	free(adjVertices);
	free(tranGraph);
	free(finishStk1);


	return 0;
}


