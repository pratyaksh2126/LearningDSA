#include <stdio.h>
#include <stdlib.h>

int dfs(int node, int color[], int** graph, int* graphColSize, int c) {
    color[node] = c;
    for (int i = 0; i < graphColSize[node]; i++) {
        int neigh = graph[node][i];
        if (color[neigh] == -1) {
            if (!dfs(neigh, color, graph, graphColSize, 1 - c))
                return 0;
        } else if (color[neigh] == c) {
            return 0;
        }
    }
    return 1;
}

int isBipartite(int** graph, int graphSize, int* graphColSize) {
    int* color = (int*)malloc(graphSize * sizeof(int));
    for (int i = 0; i < graphSize; i++)
        color[i] = -1;

    for (int i = 0; i < graphSize; i++) {
        if (color[i] == -1) {
            if (!dfs(i, color, graph, graphColSize, 0)) {
                free(color);
                return 0;
            }
        }
    }

    free(color);
    return 1;
}