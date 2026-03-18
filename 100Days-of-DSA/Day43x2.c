#include <stdio.h>
#include <stdlib.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    int *result = (int*)malloc((numsSize - k + 1) * sizeof(int));
    int *dq = (int*)malloc(numsSize * sizeof(int));
    int front = 0, rear = 0;
    *returnSize = 0;

    for(int i = 0; i < numsSize; i++) {
        if(front < rear && dq[front] <= i - k) front++;

        while(front < rear && nums[dq[rear - 1]] < nums[i]) rear--;

        dq[rear++] = i;

        if(i >= k - 1) {
            result[*returnSize] = nums[dq[front]];
            (*returnSize)++;
        }
    }

    free(dq);
    return result;
}

int main() {
    int n, k;
    scanf("%d", &n);

    int *nums = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    scanf("%d", &k);

    int returnSize;
    int *ans = maxSlidingWindow(nums, n, k, &returnSize);

    for(int i = 0; i < returnSize; i++) {
        printf("%d ", ans[i]);
    }

    free(nums);
    free(ans);
    return 0;
}