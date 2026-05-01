#include <stdio.h>

int partition(int* nums, int left, int right) {
    int pivot = nums[right];
    int i = left;

    for (int j = left; j < right; j++) {
        if (nums[j] <= pivot) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
        }
    }

    int temp = nums[i];
    nums[i] = nums[right];
    nums[right] = temp;

    return i;
}

int findKthLargest(int* nums, int n, int k) {
    int left = 0, right = n - 1;
    int target = n - k;

    while (left <= right) {
        int pi = partition(nums, left, right);
        if (pi == target)
            return nums[pi];
        else if (pi < target)
            left = pi + 1;
        else
            right = pi - 1;
    }
    return -1;
}

int main() {
    int n, k;
    scanf("%d", &n);

    int nums[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    scanf("%d", &k);

    printf("%d\n", findKthLargest(nums, n, k));

    return 0;
}