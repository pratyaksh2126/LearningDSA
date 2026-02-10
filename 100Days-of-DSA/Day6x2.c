#include <stdio.h>

int main() {
    int n;

    // Read size of array
    scanf("%d", &n);

    int nums[n];

    // Read array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int k = 0;  // index for non-zero elements

    // Move non-zero elements to the front
    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            nums[k] = nums[i];
            k++;
        }
    }

    // Fill remaining positions with 0
    while (k < n) {
        nums[k] = 0;
        k++;
    }

    // Print updated array
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
