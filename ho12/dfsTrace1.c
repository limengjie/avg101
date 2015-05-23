#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dfsTrace1.h"

#define WHITE 0
#define GRAY  1
#define BLACK 2


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
                /*assert(newE.to   > 0 && newE.to   <= num);*/

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

        




/*DFS*/

int * dfsSweep1(IntList * adjVs, int n) {
        int * color, * dTime1, * fTime1;
        int * parent1, * fStk1 = NULL;
        int time = 0;

        /*initialize arrays we are going to use
         * later in DFS*/
        color = initColor(n);
        dTime1 = initDiscoverTime(n);
        fTime1 = initFinishTime(n);
        parent1 = initParent(n);
        fStk1 = initFinishTime(n);



        /*call DFS*/
        int i;
        for (i = 1; i <= n; ++i)
                if (color[i] == WHITE)
                        time = dfsTrace1(adjVs, i, color, dTime1,\
                                        fTime1, parent1, fStk1, time);

        /*print out the results*/
        puts("======================arrays========================");
        printf("vertex\t color\t dTime\t fTime\t parent\n");
        for (i = 1; i <= n; ++i) {
                printf("%d\t", i);
                if (color[i] == BLACK) 
                        printf("black\t");
                else 
                        printf("gray or white\t");
                printf("%d\t %d\t %d\n", dTime1[i], fTime1[i], parent1[i]);
        }

        /*print out the stack*/
        puts("=====================stack========================");
        printf("order\t vertex\n");
        for (i = 1; i <= n; ++i)
                printf("%d:\t %d\n", i, fStk1[i]);


        return fStk1;
}

int dfsTrace1(IntList * adjVs, int v, int * color, int * dTime,\
                int * fTime, int * parent, int * fStk, int time) {
        int w;
        IntList remAdj;

        color[v] = GRAY;
        ++time;
        dTime[v] = time;

        remAdj = adjVs[v];
        while(remAdj != intNil) {
                w = intFirst(remAdj);
                if (color[w] == WHITE) {
                        parent[w] = v;
                        time = dfsTrace1(adjVs, w, color, dTime,\
                                        fTime, parent, fStk, time);
                }

                remAdj = intRest(remAdj);
        }

        ++time;
        fTime[v] = time;
        color[v] = BLACK;

        /*push vertex v into stack*/
        int i = 1;
        while(i <= 6) {
                if (fStk[i] == 0) {
                        fStk[i] = v;
                        break;
                }
                else
                        ++i;
        }


        return time;
}




int * initColor(int num) {
        int * color = (int *)malloc((num+1)*sizeof(int));
        memset(color, 0, num + 1);

        return color;
}


int * initDiscoverTime(int num) {
        int * dTime = (int *)malloc((num+1)*sizeof(int));
        memset(dTime, 0, num + 1);

        return dTime;
}


int * initFinishTime(int num) {
        int * fTime = (int *)malloc((num+1)*sizeof(int));
        memset(fTime, 0, num + 1);

        return fTime;
}


int * initParent(int num) {
        int * parent = (int *)malloc((num+1)*sizeof(int));
        /*memset((void *)parent, -1, num + 1);*/
        int i;
        for (i = 0; i <= num; ++i)
                parent[i] = - 1;

        return parent;
}

int * initFinishStk(int num) {
        int * fStk = (int *)malloc((num+1)*sizeof(int));
        memset(fStk, 0, num + 1);

        return fStk;
}

