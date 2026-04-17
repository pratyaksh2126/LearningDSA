#include <stdio.h>
#include <stdlib.h>

int *result;
int idx;

int dfs(int node, int **graph, int *colSize, int *state) {
    if (state[node] == 1) return 0;
    if (state[node] == 2) return 1;

    state[node] = 1;

    for (int i = 0; i < colSize[node]; i++) {
        if (!dfs(graph[node][i], graph, colSize, state)) return 0;
    }

    state[node] = 2;
    result[idx--] = node;
    return 1;
}

int main() {
    int numCourses, prerequisitesSize;
    scanf("%d %d", &numCourses, &prerequisitesSize);

    int **prerequisites = (int **)malloc(prerequisitesSize * sizeof(int *));
    for (int i = 0; i < prerequisitesSize; i++) {
        prerequisites[i] = (int *)malloc(2 * sizeof(int));
        scanf("%d %d", &prerequisites[i][0], &prerequisites[i][1]);
    }

    int **graph = (int **)malloc(numCourses * sizeof(int *));
    int *colSize = (int *)calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++) {
        graph[i] = (int *)malloc(numCourses * sizeof(int));
    }

    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        graph[b][colSize[b]++] = a;
    }

    int *state = (int *)calloc(numCourses, sizeof(int));
    result = (int *)malloc(numCourses * sizeof(int));
    idx = numCourses - 1;

    int possible = 1;

    for (int i = 0; i < numCourses; i++) {
        if (state[i] == 0) {
            if (!dfs(i, graph, colSize, state)) {
                possible = 0;
                break;
            }
        }
    }

    if (!possible) {
        printf("[]");
        return 0;
    }

    for (int i = 0; i < numCourses; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}