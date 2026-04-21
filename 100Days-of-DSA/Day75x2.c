#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int flights[m][3];

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &flights[i][0], &flights[i][1], &flights[i][2]);
    }

    int src, dst, k;
    scanf("%d %d %d", &src, &dst, &k);

    int INF = 1000000000;
    int dist[n];

    for (int i = 0; i < n; i++) dist[i] = INF;
    dist[src] = 0;

    for (int i = 0; i <= k; i++) {
        int temp[n];
        for (int j = 0; j < n; j++) temp[j] = dist[j];

        for (int j = 0; j < m; j++) {
            int u = flights[j][0];
            int v = flights[j][1];
            int w = flights[j][2];

            if (dist[u] == INF) continue;

            if (dist[u] + w < temp[v]) {
                temp[v] = dist[u] + w;
            }
        }

        for (int j = 0; j < n; j++) dist[j] = temp[j];
    }

    if (dist[dst] == INF) printf("-1\n");
    else printf("%d\n", dist[dst]);

    return 0;
}