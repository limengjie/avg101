#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dfsTrace1.h"


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


