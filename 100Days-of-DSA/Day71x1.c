#include <stdio.h>
#include <stdlib.h>

int dfs(int v, int V, int **adj, int *vis, int *rec) {
    vis[v] = 1;
    rec[v] = 1;

    for (int i = 0; i < V; i++) {
        if (adj[v][i]) {
            if (!vis[i] && dfs(i, V, adj, vis, rec))
                return 1;
            else if (rec[i])
                return 1;
        }
    }

    rec[v] = 0;
    return 0;
}

int isCycle(int V, int **adj) {
    int *vis = (int *)calloc(V, sizeof(int));
    int *rec = (int *)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (dfs(i, V, adj, vis, rec))
                return 1;
        }
    }
    return 0;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    int **adj = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        adj[i] = (int *)calloc(V, sizeof(int));
    }

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    if (isCycle(V, adj))
        printf("YES");
    else
        printf("NO");

    return 0;
}