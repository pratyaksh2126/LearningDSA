#include <stdio.h>

int canSplit(int* nums, int size, int k, int maxSum) {
    int count = 1, sum = 0;
    for (int i = 0; i < size; i++) {
        if (sum + nums[i] > maxSum) {
            count++;
            sum = nums[i];
            if (count > k)
                return 0;
        } else {
            sum += nums[i];
        }
    }
    return 1;
}

int splitArray(int* nums, int size, int k) {
    int max = 0, sum = 0;
    for (int i = 0; i < size; i++) {
        if (nums[i] > max)
            max = nums[i];
        sum += nums[i];
    }

    int low = max, high = sum, ans = sum;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canSplit(nums, size, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n, k;
    scanf("%d", &n);

    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    scanf("%d", &k);

    printf("%d\n", splitArray(nums, n, k));

    return 0;
}