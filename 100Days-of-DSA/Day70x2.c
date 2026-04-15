#include <stdio.h>
#include <stdlib.h>

int dfs(int v, int parent, int visited[], int** adj, int size[]) {
    visited[v] = 1;

    for (int i = 0; i < size[v]; i++) {
        int u = adj[v][i];

        if (!visited[u]) {
            if (dfs(u, v, visited, adj, size))
                return 1;
        } else if (u != parent) {
            return 1;
        }
    }
    return 0;
}

int hasCycle(int V, int** adj, int size[]) {
    int visited[V];

    for (int i = 0; i < V; i++)
        visited[i] = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, visited, adj, size))
                return 1;
        }
    }

    return 0;
}

int main() {
    int V, E;
    scanf("%d", &V);
    scanf("%d", &E);

    int** adj = (int**)malloc(V * sizeof(int*));
    int* size = (int*)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++)
        adj[i] = (int*)malloc(2 * E * sizeof(int));

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][size[u]++] = v;
        adj[v][size[v]++] = u;
    }

    if (hasCycle(V, adj, size))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}