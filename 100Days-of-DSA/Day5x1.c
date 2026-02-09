#include <stdio.h>

int main() {
    int p, q;
    
    // Input size of first log
    scanf("%d", &p);
    int arr1[p];
    
    // Input elements of first log
    for (int i = 0; i < p; i++) {
        scanf("%d", &arr1[i]);
    }
    
    // Input size of second log
    scanf("%d", &q);
    int arr2[q];
    
    // Input elements of second log
    for (int i = 0; i < q; i++) {
        scanf("%d", &arr2[i]);
    }

    int merged[p + q];
    int i = 0, j = 0, k = 0;

    // Merge both arrays
    while (i < p && j < q) {
        if (arr1[i] <= arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    // Copy remaining elements of arr1
    while (i < p) {
        merged[k++] = arr1[i++];
    }

    // Copy remaining elements of arr2
    while (j < q) {
        merged[k++] = arr2[j++];
    }

    // Print merged array
    for (int i = 0; i < p + q; i++) {
        printf("%d ", merged[i]);
    }

    return 0;
}
