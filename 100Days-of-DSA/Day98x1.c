#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    int* x = *(int**)a;
    int* y = *(int**)b;
    return x[0] - y[0];
}

int main() {
    int n;
    scanf("%d", &n);

    int** intervals = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        intervals[i] = (int*)malloc(2 * sizeof(int));
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);
    }

    qsort(intervals, n, sizeof(int*), compare);

    int** result = (int**)malloc(n * sizeof(int*));
    int idx = 0;

    result[0] = (int*)malloc(2 * sizeof(int));
    result[0][0] = intervals[0][0];
    result[0][1] = intervals[0][1];

    for (int i = 1; i < n; i++) {
        if (intervals[i][0] <= result[idx][1]) {
            if (intervals[i][1] > result[idx][1])
                result[idx][1] = intervals[i][1];
        } else {
            idx++;
            result[idx] = (int*)malloc(2 * sizeof(int));
            result[idx][0] = intervals[i][0];
            result[idx][1] = intervals[i][1];
        }
    }

    for (int i = 0; i <= idx; i++)
        printf("%d %d\n", result[i][0], result[i][1]);

    return 0;
}