#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int findIndex(int* inorder, int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

struct TreeNode* build(int* preorder, int* inorder, int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd)
        return NULL;

    struct TreeNode* root = createNode(preorder[*preIndex]);
    (*preIndex)++;

    if (inStart == inEnd)
        return root;

    int index = findIndex(inorder, inStart, inEnd, root->val);

    root->left = build(preorder, inorder, inStart, index - 1, preIndex);
    root->right = build(preorder, inorder, index + 1, inEnd, preIndex);

    return root;
}

void postorder(struct TreeNode* root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}

int main() {
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    int preIndex = 0;

    struct TreeNode* root = build(preorder, inorder, 0, n - 1, &preIndex);

    postorder(root);

    return 0;
}