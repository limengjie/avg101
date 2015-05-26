#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dfsPhase2.h"


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
        int * parent2, * dfstRoot2;
        int time = 0;

        /*initialize arrays*/
        color2 = initColor(n);
        dTime2 = initDiscoverTime(n);
        fTime2 = initFinishTime(n);
        parent2 = initParent(n);
        /*scc's
         * leader*/
        dfstRoot2 = initDfstRoot(n);

        /*pop the stack and use DFS to transpose graph*/
        int i;
        for (i = n; i > 0; --i) {
                int v = topStk(fStk);
                popStk(fStk);
                if (color2[v] == WHITE)
                        time = dfsT2(adjTrans, color2, v, v, dfstRoot2,\
                                     dTime2, fTime2, parent2, time);
        }

        /*print out the results*/
        printArrays(n, dTime2, fTime2, parent2);
        printScc(dfstRoot2, n);


        /*free heap*/
        free(color2);
        free(dTime2);
        free(fTime2);
        free(parent2);
        free(dfstRoot2);

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

