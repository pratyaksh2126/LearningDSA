#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    Node** queue = (Node**)malloc(n * sizeof(Node*));
    int front = 0, rear = 0;

    Node* root = createNode(arr[0]);
    queue[rear++] = root;

    int i = 1;
    while (i < n) {
        Node* current = queue[front++];

        if (i < n && arr[i] != -1) {
            current->left = createNode(arr[i]);
            queue[rear++] = current->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            queue[rear++] = current->right;
        }
        i++;
    }

    free(queue);
    return root;
}

void dfs(Node* root, int level, int* maxLevel) {
    if (!root) return;

    if (level > *maxLevel) {
        printf("%d ", root->data);
        *maxLevel = level;
    }

    dfs(root->right, level + 1, maxLevel);
    dfs(root->left, level + 1, maxLevel);
}

void rightSideView(Node* root) {
    int maxLevel = -1;
    dfs(root, 0, &maxLevel);
}

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0) {
        return 0;
    }

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n);
    rightSideView(root);

    return 0;
}