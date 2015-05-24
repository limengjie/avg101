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

        




/*Scc phase 1*/
Stack * dfsSweep1(IntList * adjVs, int n) {
        int * color, * dTime1, * fTime1, * parent1;
        int time = 0;

        /*initialize arrays we are going to use later in DFS*/
        color = initColor(n);
        dTime1 = initDiscoverTime(n);
        fTime1 = initFinishTime(n);
        parent1 = initParent(n);
        Stack * stk1 = initStk();
        



        /*recursively call DFS*/
        int i;
        for (i = 1; i <= n; ++i)
                if (color[i] == WHITE)
                        time = dfsTrace1(adjVs, i, color, dTime1,\
                                        fTime1, parent1, stk1, time);

        /*print out the results*/
        printArrays(n, dTime1, fTime1, parent1);


        /*free heap*/
        free(color);
        free(dTime1);
        free(fTime1);
        free(parent1);


        return stk1;
}

        
        
int dfsTrace1(IntList * adjVs, int v, int * color, int * dTime,\
                int * fTime, int * parent, Stack * fStk, int time) {
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
        pushStk(fStk, v);


        return time;
}




int * initColor(int num) {
        int * color = (int *)malloc((num+1)*sizeof(int));
        /*memset(color, WHITE, num + 1);*/
        int i;
        for(i = 0; i <= num; ++i)
                color[i] = WHITE;

        return color;
}


int * initDiscoverTime(int num) {
        int * dTime = (int *)malloc((num+1)*sizeof(int));
        /*memset(dTime, 0, num + 1);*/
        int i;
        for(i = 0; i <= num; ++i)
                dTime[i] = 0;

        return dTime;
}


int * initFinishTime(int num) {
        int * fTime = (int *)malloc((num+1)*sizeof(int));
        /*memset(fTime, 0, num + 1);*/
        int i;
        for(i = 0; i <= num; ++i)
                fTime[i] = 0;

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
        /*memset(fStk, 0, num + 1);*/
        int i;

        for(i = 0; i <= num; ++i)
                fStk[i] = 0;

        return fStk;
}

        
Stack * initStk() {
        Stack * stk = (Stack *)malloc(sizeof(Stack));
        stk->last = NULL;
        stk->size = 0;

        return stk;
}

int isEmptyStk(Stack * stk) {
        if (stk->size == 0)
                return 1;
        else
                return 0;
}

void printStk(Stack * stk) {
        if (isEmptyStk(stk)) {
                puts("Empty stack");
                return;
        }

        FinishTime * ft = stk->last;
        puts("=====================Stack=====================");
        while(ft) {
                printf("%d\n", ft->time);
                ft = ft->prev;
        }
        puts("___\nstk\n");
}


void pushStk(Stack * stk, int elt) {
        /*create a new FinishTime*/
        FinishTime * newElt = (FinishTime *)malloc(sizeof(FinishTime));

        newElt->next = NULL;
        newElt->time = elt;
        newElt->prev = stk->last;
        if (!isEmptyStk(stk)) {
                (stk->last)->next = newElt;
        }
        stk->last = newElt;
        stk->size++;
}


int topStk(Stack * stk) {
        if (isEmptyStk(stk))
                return -1;
        else
                return (stk->last)->time;
}

void popStk(Stack * stk) {
        if (isEmptyStk(stk))
                return;

        FinishTime * top = stk->last;
        stk->last = top->prev;
        free(top);
        stk->size--;
}




void printArrays(int n, int * dTime, int * fTime, int * parent) {
        int i;

        puts("======================arrays========================");
        puts("vertex\t dTime\t fTime\t parent");
        for(i = 1; i <= n; ++i) {
                printf("%d\t %d\t", i, dTime[i]);
                printf("%d\t %d\n", fTime[i], parent[i]);
        }
        puts(" ");

}



/*dfsPhase2*/
int * initDfstRoot(int num) {
        int * dfstRoot = (int *)malloc((num+1)*sizeof(int));
        /*memset(dfst, 0, num + 1);*/
        int i;

        for(i = 0; i <= num; ++i)
                dfstRoot[i] = 0;

        return dfstRoot;
}

void dfsTsweep2(IntList * adjTrans, int n, Stack * fStk) {
        int * color2, * dTime2, * fTime2;
        int * parent2, * scc;
        int time = 0;

        /*initialize arrays*/
        color2 = initColor(n);
        dTime2 = initDiscoverTime(n);
        fTime2 = initFinishTime(n);
        parent2 = initParent(n);
        /*scc's leader*/
        scc = initDfstRoot(n);


        /*pop the stack and use DFS to transpose graph*/
        int i;
        for (i = n; i > 0; --i) {
                int v = topStk(fStk);
                popStk(fStk);
                if (color2[v] == WHITE)
                        time = dfsT2(adjTrans, color2, v, v, scc,\
                                     dTime2, fTime2, parent2, time);
        }

        /*print out the results*/
        printArrays(n, dTime2, fTime2, parent2);
        printScc(scc, n);


        /*free heap*/
        free(color2);
        free(dTime2);
        free(fTime2);
        free(parent2);
        free(scc);

}

int dfsT2(IntList * adjTrans, int * color,\
           int v, int leader, int * scc,\
           int * dTime, int * fTime,\
           int * parent, int time) {

        int w;
        IntList remAdj;

        color[v] = GRAY;
        scc[v] = leader;
        ++time;
        dTime[v] = time;

        remAdj = adjTrans[v];
        while(remAdj != intNil) {
                w = intFirst(remAdj);
                if (color[w] == WHITE) {
                        parent[w] = v;
                        time = dfsT2(adjTrans, color, w, leader, scc,\
                                     dTime, fTime, parent, time);
                }

                remAdj = intRest(remAdj);
        }

        ++time;
        fTime[v] = time;
        color[v] = BLACK;


        return time;
}

void printScc(int * scc, int n) {
        int i;

        puts("=====================scc===========================");
        puts("vertex\t leader");
        for(i = 1; i <= n; ++i) {
                printf("%d\t %d\n", i, scc[i]);
        }
        puts(" ");

}
