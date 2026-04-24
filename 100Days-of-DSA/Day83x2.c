#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

int timeCounter;

void dfs(int u, int parent, int* visited, int* disc, int* low, int* ap, int** adj, int* colSize) {
    visited[u] = 1;
    disc[u] = low[u] = ++timeCounter;

    int children = 0;

    for (int i = 0; i < colSize[u]; i++) {
        int v = adj[u][i];

        if (!visited[v]) {
            children++;
            dfs(v, u, visited, disc, low, ap, adj, colSize);

            if (low[v] < low[u]) low[u] = low[v];

            if (parent != -1 && low[v] >= disc[u]) ap[u] = 1;
        }
        else if (v != parent) {
            if (disc[v] < low[u]) low[u] = disc[v];
        }
    }

    if (parent == -1 && children > 1) ap[u] = 1;
}

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    int* colSize = (int*)calloc(V, sizeof(int));
    int** adj = (int**)malloc(V * sizeof(int*));

    int u, v;

    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        colSize[u]++;
        colSize[v]++;
    }

    for (int i = 0; i < V; i++) {
        adj[i] = (int*)malloc(colSize[i] * sizeof(int));
        colSize[i] = 0;
    }

    rewind(stdin);

    scanf("%d %d", &V, &E);

    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        adj[u][colSize[u]++] = v;
        adj[v][colSize[v]++] = u;
    }

    int* visited = (int*)calloc(V, sizeof(int));
    int* disc = (int*)calloc(V, sizeof(int));
    int* low = (int*)calloc(V, sizeof(int));
    int* ap = (int*)calloc(V, sizeof(int));

    timeCounter = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, -1, visited, disc, low, ap, adj, colSize);
        }
    }

    int* result = (int*)malloc(V * sizeof(int));
    int count = 0;

    for (int i = 0; i < V; i++) {
        if (ap[i]) result[count++] = i;
    }

    if (count == 0) {
        printf("-1");
    } else {
        qsort(result, count, sizeof(int), cmp);
        for (int i = 0; i < count; i++) {
            printf("%d ", result[i]);
        }
    }

    return 0;
}