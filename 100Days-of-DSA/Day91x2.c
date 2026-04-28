#include <stdio.h>

int mySqrt(int x) {
    long long left = 0, right = x, ans = 0;

    while (left <= right) {
        long long mid = left + (right - left) / 2;

        if (mid * mid == x)
            return mid;
        else if (mid * mid < x) {
            ans = mid;
            left = mid + 1;
        } else
            right = mid - 1;
    }

    return ans;
}

int main() {
    int x;
    scanf("%d", &x);

    printf("%d", mySqrt(x));

    return 0;
}