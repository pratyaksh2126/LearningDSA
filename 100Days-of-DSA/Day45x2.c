#include <stdio.h>
#include <stdlib.h>

int* dailyTemperatures(int* temperatures, int temperaturesSize) {
    int* answer = (int*)malloc(sizeof(int) * temperaturesSize);
    int* stack = (int*)malloc(sizeof(int) * temperaturesSize);
    int top = -1;

    for (int i = 0; i < temperaturesSize; i++)
        answer[i] = 0;

    for (int i = 0; i < temperaturesSize; i++) {
        while (top >= 0 && temperatures[i] > temperatures[stack[top]]) {
            int idx = stack[top--];
            answer[idx] = i - idx;
        }
        stack[++top] = i;
    }

    free(stack);
    return answer;
}

int main() {
    int temperatures[] = {73,74,75,71,69,72,76,73};
    int n = sizeof(temperatures) / sizeof(temperatures[0]);

    int* result = dailyTemperatures(temperatures, n);

    for (int i = 0; i < n; i++)
        printf("%d ", result[i]);

    free(result);
    return 0;
}