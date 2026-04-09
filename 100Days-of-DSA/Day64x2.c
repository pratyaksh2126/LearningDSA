#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int search(int* inorder, int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

struct TreeNode* build(int* inorder, int* postorder, int start, int end, int* postIndex) {
    if (start > end)
        return NULL;

    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = postorder[*postIndex];
    node->left = node->right = NULL;
    (*postIndex)--;

    if (start == end)
        return node;

    int idx = search(inorder, start, end, node->val);

    node->right = build(inorder, postorder, idx + 1, end, postIndex);
    node->left = build(inorder, postorder, start, idx - 1, postIndex);

    return node;
}

void preorder(struct TreeNode* root) {
    if (root == NULL)
        return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int inorder[n], postorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    int postIndex = n - 1;

    struct TreeNode* root = build(inorder, postorder, 0, n - 1, &postIndex);

    preorder(root);

    return 0;
}