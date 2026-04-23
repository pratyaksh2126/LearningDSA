#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int sum;
    int index;
} Node;

int find(Node *arr, int size, int sum) {
    for (int i = 0; i < size; i++) {
        if (arr[i].sum == sum) return arr[i].index;
    }
    return -1;
}

int maxLen(int arr[], int n) {
    Node *hash = (Node *)malloc(n * sizeof(Node));
    int size = 0, sum = 0, max_len = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0) max_len = i + 1;

        int prev = find(hash, size, sum);

        if (prev != -1) {
            if (i - prev > max_len)
                max_len = i - prev;
        } else {
            hash[size].sum = sum;
            hash[size].index = i;
            size++;
        }
    }

    free(hash);
    return max_len;
}

int main() {
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("%d", maxLen(arr, n));

    free(arr);
    return 0;
}