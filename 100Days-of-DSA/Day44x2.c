#include <stdio.h>
#include <stdlib.h>

#define OFFSET 10000
#define RANGE 20001

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    int *freq = (int*)calloc(RANGE, sizeof(int));

    for (int i = 0; i < numsSize; i++)
        freq[nums[i] + OFFSET]++;

    int **bucket = (int**)malloc((numsSize + 1) * sizeof(int*));
    int *bucketSize = (int*)calloc(numsSize + 1, sizeof(int));

    for (int i = 0; i <= numsSize; i++)
        bucket[i] = (int*)malloc(numsSize * sizeof(int));

    for (int i = 0; i < RANGE; i++) {
        if (freq[i] > 0) {
            int f = freq[i];
            bucket[f][bucketSize[f]++] = i - OFFSET;
        }
    }

    int *result = (int*)malloc(k * sizeof(int));
    int count = 0;

    for (int i = numsSize; i >= 0 && count < k; i--) {
        for (int j = 0; j < bucketSize[i] && count < k; j++) {
            result[count++] = bucket[i][j];
        }
    }

    *returnSize = k;
    return result;
}

int main() {
    int n, k;
    scanf("%d", &n);

    int *nums = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    scanf("%d", &k);

    int returnSize;
    int *res = topKFrequent(nums, n, k, &returnSize);

    for (int i = 0; i < returnSize; i++)
        printf("%d ", res[i]);

    return 0;
}