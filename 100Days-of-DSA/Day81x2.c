#include <stdlib.h>

struct Node {
    int val;
    int numNeighbors;
    struct Node** neighbors;
};

struct Node* dfs(struct Node* node, struct Node** visited) {
    if (visited[node->val] != NULL)
        return visited[node->val];

    struct Node* clone = (struct Node*)malloc(sizeof(struct Node));
    clone->val = node->val;
    clone->numNeighbors = node->numNeighbors;
    clone->neighbors = (struct Node**)malloc(node->numNeighbors * sizeof(struct Node*));

    visited[node->val] = clone;

    for (int i = 0; i < node->numNeighbors; i++) {
        clone->neighbors[i] = dfs(node->neighbors[i], visited);
    }

    return clone;
}

struct Node* cloneGraph(struct Node* s) {
    if (s == NULL)
        return NULL;

    struct Node** visited = (struct Node**)calloc(101, sizeof(struct Node*));
    return dfs(s, visited);
}