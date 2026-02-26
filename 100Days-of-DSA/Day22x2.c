#include <stdio.h>

int maxSubArray(int nums[], int size) {
    int maxSum = nums[0];
    int currentSum = nums[0];

    for (int i = 1; i < size; i++) {
        if (currentSum < 0)
            currentSum = nums[i];
        else
            currentSum += nums[i];

        if (currentSum > maxSum)
            maxSum = currentSum;
    }

    return maxSum;
}

int main() {
    int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int size = sizeof(nums) / sizeof(nums[0]);

    printf("Maximum Subarray Sum: %d\n", maxSubArray(nums, size));

    return 0;
}