#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int maximumGap(int* nums, int n) {
    if (n < 2)
        return 0;

    int min = INT_MAX, max = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (nums[i] < min) min = nums[i];
        if (nums[i] > max) max = nums[i];
    }

    if (min == max)
        return 0;

    int bucketSize = (max - min) / (n - 1);
    if ((max - min) % (n - 1))
        bucketSize++;

    int bucketCount = (max - min) / bucketSize + 1;

    int* bucketMin = (int*)malloc(bucketCount * sizeof(int));
    int* bucketMax = (int*)malloc(bucketCount * sizeof(int));

    for (int i = 0; i < bucketCount; i++) {
        bucketMin[i] = INT_MAX;
        bucketMax[i] = INT_MIN;
    }

    for (int i = 0; i < n; i++) {
        int idx = (nums[i] - min) / bucketSize;
        if (nums[i] < bucketMin[idx]) bucketMin[idx] = nums[i];
        if (nums[i] > bucketMax[idx]) bucketMax[idx] = nums[i];
    }

    int maxGap = 0, prev = min;

    for (int i = 0; i < bucketCount; i++) {
        if (bucketMin[i] == INT_MAX)
            continue;
        if (bucketMin[i] - prev > maxGap)
            maxGap = bucketMin[i] - prev;
        prev = bucketMax[i];
    }

    free(bucketMin);
    free(bucketMax);

    return maxGap;
}

int main() {
    int n;
    scanf("%d", &n);

    int nums[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    printf("%d\n", maximumGap(nums, n));

    return 0;
}