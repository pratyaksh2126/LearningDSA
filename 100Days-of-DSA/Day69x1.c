#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int isEmpty() {
    return front == -1 || front > rear;
}

int main() {
    int n, i, j, s;
    int adj[MAX][MAX], visited[MAX] = {0};

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    scanf("%d", &s);

    enqueue(s);
    visited[s] = 1;

    while(!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);

        for(i = 0; i < n; i++) {
            if(adj[node][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }

    return 0;
}