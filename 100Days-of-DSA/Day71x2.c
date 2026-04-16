#include <stdio.h>
#include <stdlib.h>

int dfs(int v, int **adj, int *vis, int *rec, int n) {
    vis[v] = 1;
    rec[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i]) {
            if (!vis[i] && dfs(i, adj, vis, rec, n))
                return 1;
            else if (rec[i])
                return 1;
        }
    }

    rec[v] = 0;
    return 0;
}

int canFinish(int numCourses, int **prereq, int prereqSize) {
    int **adj = (int **)malloc(numCourses * sizeof(int *));
    for (int i = 0; i < numCourses; i++)
        adj[i] = (int *)calloc(numCourses, sizeof(int));

    for (int i = 0; i < prereqSize; i++) {
        int a = prereq[i][0];
        int b = prereq[i][1];
        adj[b][a] = 1;
    }

    int *vis = (int *)calloc(numCourses, sizeof(int));
    int *rec = (int *)calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++) {
        if (!vis[i]) {
            if (dfs(i, adj, vis, rec, numCourses))
                return 0;
        }
    }
    return 1;
}

int main() {
    int numCourses, m;
    scanf("%d", &numCourses);
    scanf("%d", &m);

    int **prereq = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
        prereq[i] = (int *)malloc(2 * sizeof(int));

    for (int i = 0; i < m; i++)
        scanf("%d %d", &prereq[i][0], &prereq[i][1]);

    if (canFinish(numCourses, prereq, m))
        printf("true");
    else
        printf("false");

    return 0;
}