#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, w;
} Edge;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Edge edges[m];

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    int src;
    scanf("%d", &src);

    int dist[n];

    for (int i = 0; i < n; i++) {
        dist[i] = 1000000000;
    }

    dist[src] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            if (dist[edges[j].u] != 1000000000 && dist[edges[j].u] + edges[j].w < dist[edges[j].v]) {
                dist[edges[j].v] = dist[edges[j].u] + edges[j].w;
            }
        }
    }

    int negative = 0;

    for (int j = 0; j < m; j++) {
        if (dist[edges[j].u] != 1000000000 && dist[edges[j].u] + edges[j].w < dist[edges[j].v]) {
            negative = 1;
            break;
        }
    }

    if (negative) {
        printf("NEGATIVE CYCLE\n");
    } else {
        for (int i = 0; i < n; i++) {
            if (dist[i] == 1000000000)
                printf("INF ");
            else
                printf("%d ", dist[i]);
        }
    }

    return 0;
}