#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int minCost(int** points, int n) {
    int* minDist = (int*)malloc(n * sizeof(int));
    int* visited = (int*)calloc(n, sizeof(int));

    for(int i = 0; i < n; i++) minDist[i] = INT_MAX;

    minDist[0] = 0;
    int result = 0;

    for(int i = 0; i < n; i++) {
        int u = -1;
        for(int j = 0; j < n; j++) {
            if(!visited[j] && (u == -1 || minDist[j] < minDist[u])) {
                u = j;
            }
        }

        visited[u] = 1;
        result += minDist[u];

        for(int v = 0; v < n; v++) {
            if(!visited[v]) {
                int dist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                if(dist < minDist[v]) {
                    minDist[v] = dist;
                }
            }
        }
    }

    free(minDist);
    free(visited);
    return result;
}

int main() {
    int n;
    scanf("%d", &n);

    int** points = (int**)malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++) {
        points[i] = (int*)malloc(2 * sizeof(int));
        scanf("%d %d", &points[i][0], &points[i][1]);
    }

    printf("%d\n", minCost(points, n));

    for(int i = 0; i < n; i++) free(points[i]);
    free(points);

    return 0;
}