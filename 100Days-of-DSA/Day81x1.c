#include <stdio.h>
#include <stdlib.h>

void dfs(int node, int n, int** adj, int* colSize, int* visited) {
    visited[node] = 1;
    for (int i = 0; i < colSize[node]; i++) {
        int neigh = adj[node][i];
        if (!visited[neigh])
            dfs(neigh, n, adj, colSize, visited);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int** adj = (int**)malloc((n + 1) * sizeof(int*));
    int* colSize = (int*)calloc((n + 1), sizeof(int));

    for (int i = 0; i <= n; i++)
        adj[i] = (int*)malloc((n + 1) * sizeof(int));

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][colSize[u]++] = v;
        adj[v][colSize[v]++] = u;
    }

    int* visited = (int*)calloc((n + 1), sizeof(int));
    int count = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, n, adj, colSize, visited);
            count++;
        }
    }

    printf("%d", count);

    return 0;
}