#include <stdio.h>
#include <conio.h>

#define MAX 4

int adj[MAX][MAX];
int visited[MAX];
int n = 4;


void DFS(int vertex) {
    int i;
    visited[vertex] = 1;
    printf("Visited %d \n", vertex);

    for (i = n - 1; i >= 0; i--) { 
        if (adj[vertex][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}


void printGraph() {
    int i, j;
    for (i = 0; i < n; i++) {
        printf("\n Adjacency list of vertex %d\n ", i);
        for (j = n - 1; j >= 0; j--) {
            if (adj[i][j] == 1)
                printf("%d -> ", j);
        }
        printf("\n");
    }
}

void main() {
    int edges[4][2] = { {0,1}, {0,2}, {1,2}, {2,3} };
    int i, j;

    clrscr();

    // Initialize adjacency matrix and visited array
    for (i = 0; i < n; i++) {
        visited[i] = 0;
        for (j = 0; j < n; j++)
            adj[i][j] = 0;
    }

   
    for (i = 0; i < 4; i++) {
        int src = edges[i][0];
        int dest = edges[i][1];
        adj[src][dest] = 1;
        adj[dest][src] = 1;
    }

    printGraph();
    DFS(2);

    getch();
}
