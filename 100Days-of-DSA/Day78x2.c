#include <stdio.h>
#include <stdlib.h>

int parent[1001];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

int unite(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px == py) return 0;
    parent[py] = px;
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    int edges[n][2];

    for (int i = 0; i < n; i++)
        scanf("%d %d", &edges[i][0], &edges[i][1]);

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    int res[2];

    for (int i = 0; i < n; i++) {
        if (!unite(edges[i][0], edges[i][1])) {
            res[0] = edges[i][0];
            res[1] = edges[i][1];
        }
    }

    printf("%d %d", res[0], res[1]);

    return 0;
}