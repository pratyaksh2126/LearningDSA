#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

bool hasCycle(struct ListNode *head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}

int main() {
    int n, pos;
    scanf("%d", &n);

    struct ListNode *head = NULL, *temp = NULL, *cycleNode = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        struct ListNode* newNode = createNode(x);

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }

        if (i == pos)
            cycleNode = newNode;
    }

    scanf("%d", &pos);

    if (pos != -1) {
        temp->next = head;
        for (int i = 0; i < pos; i++)
            temp->next = temp->next->next;
    }

    if (hasCycle(head))
        printf("true");
    else
        printf("false");

    return 0;
}