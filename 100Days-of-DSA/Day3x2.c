#include <stdio.h>

int missingNum(int arr[], int n) {
    int total = (n + 1) * (n + 2) / 2;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    return total - sum;
}

int main() {
    int n;

    // Input size (n = size of array)
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Function call
    int result = missingNum(arr, n);

    // Output
    printf("%d\n", result);

    return 0;
}
