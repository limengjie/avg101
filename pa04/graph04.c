#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include "edgeList.h"
#include "loadWgtGraph.h"
#include "minPQ.h"
#include "greedyTree.h"


int main(int argc, char* argv[]) {

	if (argc != 4) {
		fprintf(stderr, "Usage: graph04 -task start input\n");
		exit(0);
	}

	/*determine the task*/
	int task;
	if (!strcmp(argv[1], "-P")) {
	    task = 'P';
	    puts("=================================");
	    puts("Implement Prim algorithm.");
	    puts("=================================");
	}
	else if (!strcmp(argv[1], "-D")) {
		task = 'D';
		puts("=================================");
		puts("Implement Dijkstra algorithm.");
		puts("=================================");
	}
	else {
		fprintf(stderr, "No such task.(-P or -D)\n");
		exit(1);
	}

	/*open a file*/
	FILE * fp;
	if (strcmp(argv[3], "-"))  //build graph from file
		fp = open_file(argv[3]);
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


	/*get start vertex*/
	int s = atoi(argv[2]);
	if (s > n || s <= 0) {
		fprintf(stderr, "Bad start vertex.\n");
		exit(1);
	}

	/*initialize the adjacency list*/
	EdgeList * adjInfos;
	adjInfos = initEdges(n);


	/*read file to buffer and parse each line*/
	while (fgets(line, sizeof(line), fp)) {
		loadEdges(line, adjInfos, n, task);
	}


	/*print the graph*/
	puts("=====================original graph================== ");
	printGraph(adjInfos, n);


	/*initialize arrays*/
	int * status = initStatus(n);
	int * parent = initParent(n);
	double * fringeWgt = initFringeWgt(n);


	/*implement Prim or Dijkstra algorithm depending on task*/
	greedyTree(task, adjInfos, n, s, status, fringeWgt, parent);


	/*print the result*/
	printArrays(n, status, fringeWgt, parent);
	

	/*clean up before leaving*/
	fclose(fp);
	free(status);
	free(fringeWgt);
	free(parent);


	return 0;
}


