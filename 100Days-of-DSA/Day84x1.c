#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct {
    int v, w;
} Node;

typedef struct {
    Node arr[MAX];
    int size;
} MinHeap;

void swap(Node *a, Node *b) {
    Node t = *a;
    *a = *b;
    *b = t;
}

void push(MinHeap *h, int v, int w) {
    int i = h->size++;
    h->arr[i].v = v;
    h->arr[i].w = w;

    while (i > 0 && h->arr[(i - 1) / 2].w > h->arr[i].w) {
        swap(&h->arr[i], &h->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

Node pop(MinHeap *h) {
    Node root = h->arr[0];
    h->arr[0] = h->arr[--h->size];

    int i = 0;
    while (2 * i + 1 < h->size) {
        int left = 2 * i + 1, right = 2 * i + 2, smallest = i;

        if (left < h->size && h->arr[left].w < h->arr[smallest].w)
            smallest = left;
        if (right < h->size && h->arr[right].w < h->arr[smallest].w)
            smallest = right;

        if (smallest == i) break;

        swap(&h->arr[i], &h->arr[smallest]);
        i = smallest;
    }

    return root;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[MAX][MAX] = {0};

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u - 1][v - 1] = w;
        graph[v - 1][u - 1] = w;
    }

    int source;
    scanf("%d", &source);
    source--;

    int dist[MAX];
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[source] = 0;

    MinHeap h;
    h.size = 0;

    push(&h, source, 0);

    while (h.size > 0) {
        Node cur = pop(&h);
        int u = cur.v;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] > 0) {
                int newDist = dist[u] + graph[u][v];
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    push(&h, v, dist[v]);
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
        printf("%d ", dist[i]);

    return 0;
}