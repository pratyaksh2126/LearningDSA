#include <stdio.h>

int removeElement(int nums[], int numsSize, int val) {
    int k = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}

int main() {
    int n, val;

    // Read size of array
    scanf("%d", &n);

    int nums[n];

    // Read array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    // Read value to remove
    scanf("%d", &val);

    int k = removeElement(nums, n, val);

    // Print result
    printf("%d\n", k);
    for (int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
