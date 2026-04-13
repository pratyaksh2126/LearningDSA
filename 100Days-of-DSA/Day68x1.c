#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Node** adj, int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

void dfs(int v, struct Node** adj, int* visited) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->vertex]) {
            dfs(temp->vertex, adj, visited);
        }
        temp = temp->next;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node** adj = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            int v;
            scanf("%d", &v);
            addEdge(adj, i, v);
        }
    }

    int s;
    scanf("%d", &s);

    int* visited = (int*)calloc(n, sizeof(int));

    dfs(s, adj, visited);

    free(visited);
    for (int i = 0; i < n; i++) {
        struct Node* temp = adj[i];
        while (temp) {
            struct Node* t = temp;
            temp = temp->next;
            free(t);
        }
    }
    free(adj);

    return 0;
}