#include <stdio.h>
#include <stdlib.h>

void relativeSort(int arr1[], int n, int arr2[], int m) {
    int count[1001] = {0};

    for (int i = 0; i < n; i++)
        count[arr1[i]]++;

    int result[n];
    int idx = 0;

    for (int i = 0; i < m; i++) {
        while (count[arr2[i]] > 0) {
            result[idx++] = arr2[i];
            count[arr2[i]]--;
        }
    }

    for (int i = 0; i <= 1000; i++) {
        while (count[i] > 0) {
            result[idx++] = i;
            count[i]--;
        }
    }

    for (int i = 0; i < n; i++)
        arr1[i] = result[i];
}

int main() {
    int n, m;
    scanf("%d", &n);

    int arr1[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr1[i]);

    scanf("%d", &m);

    int arr2[m];
    for (int i = 0; i < m; i++)
        scanf("%d", &arr2[i]);

    relativeSort(arr1, n, arr2, m);

    for (int i = 0; i < n; i++)
        printf("%d ", arr1[i]);

    return 0;
}