#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

int stack[MAX], top = -1;
int visited[MAX];

typedef struct Node {
    int v;
    struct Node* next;
} Node;

Node* adj[MAX];
Node* rev[MAX];

void addEdge(Node* graph[], int u, int v) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->v = v;
    temp->next = graph[u];
    graph[u] = temp;
}

void dfs1(int v) {
    visited[v] = 1;
    Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->v])
            dfs1(temp->v);
        temp = temp->next;
    }
    stack[++top] = v;
}

void dfs2(int v) {
    visited[v] = 1;
    Node* temp = rev[v];
    while (temp) {
        if (!visited[temp->v])
            dfs2(temp->v);
        temp = temp->next;
    }
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
        rev[i] = NULL;
        visited[i] = 0;
    }

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
        addEdge(rev, v, u);
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i])
            dfs1(i);
    }

    for (int i = 0; i < V; i++)
        visited[i] = 0;

    int scc = 0;

    while (top != -1) {
        int v = stack[top--];
        if (!visited[v]) {
            dfs2(v);
            scc++;
        }
    }

    printf("%d\n", scc);
    return 0;
}