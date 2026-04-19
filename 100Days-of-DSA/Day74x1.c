#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct {
    int v, w;
} Edge;

typedef struct {
    Edge data[MAX];
    int size;
} MinHeap;

void swap(Edge *a, Edge *b) {
    Edge t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(MinHeap *h, int i) {
    while (i && h->data[(i - 1) / 2].w > h->data[i].w) {
        swap(&h->data[i], &h->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(MinHeap *h, int i) {
    int l, r, smallest;
    while (1) {
        l = 2 * i + 1;
        r = 2 * i + 2;
        smallest = i;

        if (l < h->size && h->data[l].w < h->data[smallest].w)
            smallest = l;
        if (r < h->size && h->data[r].w < h->data[smallest].w)
            smallest = r;

        if (smallest != i) {
            swap(&h->data[i], &h->data[smallest]);
            i = smallest;
        } else break;
    }
}

void push(MinHeap *h, int v, int w) {
    h->data[h->size].v = v;
    h->data[h->size].w = w;
    heapifyUp(h, h->size);
    h->size++;
}

Edge pop(MinHeap *h) {
    Edge root = h->data[0];
    h->data[0] = h->data[h->size - 1];
    h->size--;
    heapifyDown(h, 0);
    return root;
}

int isEmpty(MinHeap *h) {
    return h->size == 0;
}

typedef struct Node {
    int v, w;
    struct Node *next;
} Node;

Node* adj[MAX];

void addEdge(int u, int v, int w) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->v = v;
    n->w = w;
    n->next = adj[u];
    adj[u] = n;
}

void dijkstra(int V, int src) {
    int dist[MAX];
    for (int i = 0; i < V; i++) dist[i] = INT_MAX;

    MinHeap h;
    h.size = 0;

    dist[src] = 0;
    push(&h, src, 0);

    while (!isEmpty(&h)) {
        Edge e = pop(&h);
        int u = e.v;

        Node* temp = adj[u];
        while (temp) {
            int v = temp->v;
            int w = temp->w;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(&h, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    for (int i = 0; i < V; i++)
        printf("%d ", dist[i]);
}

int main() {
    int V = 5;

    for (int i = 0; i < V; i++) adj[i] = NULL;

    addEdge(0, 1, 10);
    addEdge(0, 4, 5);
    addEdge(1, 2, 1);
    addEdge(4, 1, 3);
    addEdge(4, 2, 9);
    addEdge(2, 3, 4);

    dijkstra(V, 0);

    return 0;
}