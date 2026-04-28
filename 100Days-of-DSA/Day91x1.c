#include <stdio.h>

int sqrtInt(int n) {
    long long left = 0, right = n, ans = 0;

    while (left <= right) {
        long long mid = (left + right) / 2;

        if (mid * mid == n)
            return mid;
        else if (mid * mid < n) {
            ans = mid;
            left = mid + 1;
        } else
            right = mid - 1;
    }

    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d", sqrtInt(n));

    return 0;
}