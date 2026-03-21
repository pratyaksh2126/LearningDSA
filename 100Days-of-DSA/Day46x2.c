#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int leastInterval(char tasks[], int tasksSize, int n) {
    int freq[26] = {0};

    for (int i = 0; i < tasksSize; i++) {
        freq[tasks[i] - 'A']++;
    }

    int maxFreq = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
        }
    }

    int maxCount = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] == maxFreq) {
            maxCount++;
        }
    }

    int result = (maxFreq - 1) * (n + 1) + maxCount;
    return max(tasksSize, result);
}

int main() {
    int n, cooldown;
    scanf("%d", &n);

    char tasks[n];
    for (int i = 0; i < n; i++) {
        scanf(" %c", &tasks[i]);
    }

    scanf("%d", &cooldown);

    int ans = leastInterval(tasks, n, cooldown);
    printf("%d\n", ans);

    return 0;
}