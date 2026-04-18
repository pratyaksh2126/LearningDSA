#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 26

int queue[MAX], front = 0, rear = -1;

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

int main() {
    int n;
    scanf("%d", &n);

    char words[500][101];

    for (int i = 0; i < n; i++) {
        scanf("%s", words[i]);
    }

    int adj[MAX][MAX] = {0};
    int indegree[MAX] = {0};
    int present[MAX] = {0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; words[i][j]; j++) {
            present[words[i][j] - 'a'] = 1;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        char *w1 = words[i];
        char *w2 = words[i + 1];
        int j = 0;

        while (w1[j] && w2[j] && w1[j] == w2[j]) j++;

        if (w1[j] && w2[j]) {
            int u = w1[j] - 'a';
            int v = w2[j] - 'a';
            if (!adj[u][v]) {
                adj[u][v] = 1;
                indegree[v]++;
            }
        } else if (w1[j] && !w2[j]) {
            printf("");
            return 0;
        }
    }

    for (int i = 0; i < MAX; i++) {
        if (present[i] && indegree[i] == 0)
            enqueue(i);
    }

    char result[MAX];
    int idx = 0;

    while (!isEmpty()) {
        int u = dequeue();
        result[idx++] = u + 'a';

        for (int v = 0; v < MAX; v++) {
            if (adj[u][v]) {
                indegree[v]--;
                if (indegree[v] == 0)
                    enqueue(v);
            }
        }
    }

    for (int i = 0; i < MAX; i++) {
        if (present[i] && indegree[i] > 0) {
            printf("");
            return 0;
        }
    }

    result[idx] = '\0';
    printf("%s", result);

    return 0;
}