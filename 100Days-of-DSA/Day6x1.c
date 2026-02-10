#include <stdio.h>

int main() {
    int n;

    // Read size of array
    scanf("%d", &n);

    int arr[n];

    // Read array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // If array is empty
    if (n == 0) {
        return 0;
    }

    int k = 1;  // Index for unique elements

    // Remove duplicates in-place
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            arr[k] = arr[i];
            k++;
        }
    }

    // Print unique elements
    for (int i = 0; i < k; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
