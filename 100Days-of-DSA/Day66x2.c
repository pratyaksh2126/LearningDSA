#include <stdio.h>
#include <stdlib.h>

void dfs(int **a, int *vis, int n, int u)
{
    vis[u] = 1;
    for(int v = 0; v < n; v++)
        if(a[u][v] == 1 && vis[v] == 0)
            dfs(a, vis, n, v);
}

int main()
{
    int n;
    scanf("%d", &n);

    int **a = (int **)malloc(n * sizeof(int *));
    for(int i = 0; i < n; i++)
        a[i] = (int *)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    int vis[200] = {0};
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        if(vis[i] == 0)
        {
            dfs(a, vis, n, i);
            count++;
        }
    }

    printf("%d\n", count);

    for(int i = 0; i < n; i++)
        free(a[i]);
    free(a);

    return 0;
}