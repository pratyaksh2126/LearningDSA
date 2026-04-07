#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0) return NULL;

    struct TreeNode** nodes = (struct TreeNode**)malloc(n * sizeof(struct TreeNode*));

    for (int i = 0; i < n; i++) {
        if (arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = newNode(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int l = 2 * i + 1;
            int r = 2 * i + 2;

            if (l < n) nodes[i]->left = nodes[l];
            if (r < n) nodes[i]->right = nodes[r];
        }
    }

    struct TreeNode* root = nodes[0];
    free(nodes);
    return root;
}

void helper(struct TreeNode* root, struct TreeNode** prev) {
    if (root == NULL) return;

    helper(root->right, prev);
    helper(root->left, prev);

    root->right = *prev;
    root->left = NULL;
    *prev = root;
}

void flatten(struct TreeNode* root) {
    struct TreeNode* prev = NULL;
    helper(root, &prev);
}

void printList(struct TreeNode* root) {
    while (root) {
        printf("%d ", root->val);
        root = root->right;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct TreeNode* root = buildTree(arr, n);

    flatten(root);
    printList(root);

    return 0;
}