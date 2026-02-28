#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int totalSum = 0;

    int currMax = nums[0];
    int maxSum = nums[0];

    int currMin = nums[0];
    int minSum = nums[0];

    for (int i = 0; i < n; i++) {
        totalSum += nums[i];

        if (i > 0) {
            currMax = max(currMax + nums[i], nums[i]);
            maxSum = max(maxSum, currMax);

            currMin = min(currMin + nums[i], nums[i]);
            minSum = min(minSum, currMin);
        }
    }

    int result;

    if (maxSum < 0)
        result = maxSum;     
    else
        result = max(maxSum, totalSum - minSum);

    printf("Maximum Circular Subarray Sum: %d\n", result);

    return 0;
}