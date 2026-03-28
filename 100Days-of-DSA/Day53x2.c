#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int sum(struct TreeNode* root, int isLeft) {
    if (root == NULL) return 0;

    if (root->left == NULL && root->right == NULL && isLeft)
        return root->val;

    return sum(root->left, 1) + sum(root->right, 0);
}

int sumOfLeftLeaves(struct TreeNode* root) {
    return sum(root, 0);
}

int main() {
    struct TreeNode* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    printf("%d", sumOfLeftLeaves(root));
    return 0;
}