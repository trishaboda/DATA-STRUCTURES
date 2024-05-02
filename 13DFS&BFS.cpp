#include <stdio.h>
#define MAXNODES 4

int visited[MAXNODES] = {0};

void recDfs (int G[][MAXNODES], int v){
    visited[v] = 1;
    printf("%d ", v);
    for(int i = 1; i<MAXNODES;i++){
        if(G[v][i] == 1 && visited[i]==0){
            recDfs();
        }
    }
}

void BFS(int G[][MAXNODES], int v){
    initializeQueue();
    visited[v] = 1;
    enqueue(v);
    while(!isEmpty){
        int i = dequeue();
        printf("%d ", i);
        for(int j = 0; j<MAXNODES; j++){
            if(visited[j]==0 && G[i][j]==1){
                enqueue(j);
                visited[j] = 1;
            }
        }
    }
}