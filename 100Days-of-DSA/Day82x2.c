#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

int timeCounter;

void dfs(int u, int parent, int* disc, int* low, int** graph, int* colSize, int** result, int* returnSize) {
    disc[u] = low[u] = ++timeCounter;

    for (int i = 0; i < colSize[u]; i++) {
        int v = graph[u][i];

        if (v == parent) continue;

        if (disc[v] == 0) {
            dfs(v, u, disc, low, graph, colSize, result, returnSize);
            low[u] = low[u] < low[v] ? low[u] : low[v];

            if (low[v] > disc[u]) {
                result[*returnSize][0] = u;
                result[*returnSize][1] = v;
                (*returnSize)++;
            }
        } else {
            low[u] = low[u] < disc[v] ? low[u] : disc[v];
        }
    }
}

int** criticalConnections(int n, int** connections, int connectionsSize, int* connectionsColSize, int* returnSize, int** returnColumnSizes) {
    int** graph = (int**)malloc(n * sizeof(int*));
    int* colSize = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < connectionsSize; i++) {
        colSize[connections[i][0]]++;
        colSize[connections[i][1]]++;
    }

    for (int i = 0; i < n; i++) {
        graph[i] = (int*)malloc(colSize[i] * sizeof(int));
        colSize[i] = 0;
    }

    for (int i = 0; i < connectionsSize; i++) {
        int u = connections[i][0];
        int v = connections[i][1];
        graph[u][colSize[u]++] = v;
        graph[v][colSize[v]++] = u;
    }

    int* disc = (int*)calloc(n, sizeof(int));
    int* low = (int*)calloc(n, sizeof(int));

    int** result = (int**)malloc(connectionsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(connectionsSize * sizeof(int));

    for (int i = 0; i < connectionsSize; i++) {
        result[i] = (int*)malloc(2 * sizeof(int));
        (*returnColumnSizes)[i] = 2;
    }

    *returnSize = 0;
    timeCounter = 0;

    dfs(0, -1, disc, low, graph, colSize, result, returnSize);

    return result;
}