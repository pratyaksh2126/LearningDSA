#include <stdio.h>
#include <limits.h>

#define MAX 101
#define INF 1000000000

int networkDelayTime(int times[][3], int timesSize, int n, int k) {
    int dist[MAX][MAX];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dist[i][j] = (i == j) ? 0 : INF;

    for (int i = 0; i < timesSize; i++) {
        int u = times[i][0];
        int v = times[i][1];
        int w = times[i][2];
        dist[u][v] = w;
    }

    int d[MAX], visited[MAX] = {0};

    for (int i = 1; i <= n; i++) d[i] = INF;

    d[k] = 0;

    for (int i = 1; i <= n; i++) {
        int u = -1, min = INF;

        for (int j = 1; j <= n; j++) {
            if (!visited[j] && d[j] < min) {
                min = d[j];
                u = j;
            }
        }

        if (u == -1) break;

        visited[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (dist[u][v] != INF && d[u] + dist[u][v] < d[v]) {
                d[v] = d[u] + dist[u][v];
            }
        }
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        if (d[i] == INF) return -1;
        if (d[i] > ans) ans = d[i];
    }

    return ans;
}

int main() {
    int n, m, k;

    scanf("%d %d", &n, &m);

    int times[m][3];

    for (int i = 0; i < m; i++)
        scanf("%d %d %d", &times[i][0], &times[i][1], &times[i][2]);

    scanf("%d", &k);

    int result = networkDelayTime(times, m, n, k);

    printf("%d\n", result);

    return 0;
}