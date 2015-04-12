#include <stdio.h>
/*#include "intList.h"*/

/*struct Node {*/
	/*int num;*/
	/*struct Node * next;*/
/*};*/

typedef struct {
	int from;
	int to;
	float weight;
} Edge;


int * initEdges(int n) {
	int * ini = (int *)calloc(n*(n-1), sizeof(int));
	return ini;
}

Edge parseEdge(char * line) {
		int node0, node1, vars;
		float weight;
		vars = sscanf(line, "%d %d  %f", &node0, &node1, weight);
		
		if (vars == 2) {
			printf("%d    %d\n", node0, node1);
			weight = 0.0;
		}
		else if (vars == 3)
			printf("%d  %d  %f\n", node0, node1, weight);

		Edge e;
		e.from = node0;
		e.to = node1;
                e.weight = weight;

		puts("finish parse edge");

		return e;
}

void loadEdges(char * line, int * adjVs, int num) {
	Edge e = parseEdge(line);
	adjVs[(num-1)*e.from + e.to] = 1;
	/*adjVs[(num-1)*e.to + e.from] = 1;*/

	puts("finish loadEdge");
}
	

int main(int argc, char* argv[]) {

	if (argc != 2) {
		perror("Usage: graph01 input.data");
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





	char line[100];
	/*read and parse n*/
	int n, args;
	fgets(line, sizeof(line), fp);
	args = sscanf(line, "%d", &n);
	if (args != 1) {
		fprintf(stderr, "Bad line 1: %s", line);
		exit(1);
	}
	printf("there are %d nodes\n", n);

	/*initialize the adjacency list*/
	int * adjVertices;
	adjVertices = initEdges(n);



	int count = 0;

	// read file to buffer
	while (fgets(line, sizeof(line), fp)) {
		printf("%d loop: \n", count++);
		/*printf("size of the line is %d\n", sizeof(line));*/
		loadEdges(line, adjVertices, n);
	}

	int i, j;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n -1; ++j)
			printf("%d  ", adjVertices[i*(n-1) + j]);
		printf("\n");
	}

	return 0;
}
