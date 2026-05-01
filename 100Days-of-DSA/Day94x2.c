#include <stdio.h>

int canShip(int* weights, int size, int days, int capacity) {
    int d = 1, load = 0;
    for (int i = 0; i < size; i++) {
        if (load + weights[i] > capacity) {
            d++;
            load = weights[i];
            if (d > days)
                return 0;
        } else {
            load += weights[i];
        }
    }
    return 1;
}

int shipWithinDays(int* weights, int size, int days) {
    int max = 0, sum = 0;
    for (int i = 0; i < size; i++) {
        if (weights[i] > max)
            max = weights[i];
        sum += weights[i];
    }

    int low = max, high = sum, ans = sum;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canShip(weights, size, days, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n, days;
    scanf("%d", &n);

    int weights[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    scanf("%d", &days);

    printf("%d\n", shipWithinDays(weights, n, days));

    return 0;
}