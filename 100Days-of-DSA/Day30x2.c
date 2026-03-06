#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            struct ListNode *ptr = head;
            while (ptr != slow) {
                ptr = ptr->next;
                slow = slow->next;
            }
            return ptr;
        }
    }

    return NULL;
}

int main() {
    int n, pos;
    scanf("%d", &n);

    struct ListNode *head = NULL, *temp = NULL, *nodes[n];

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        nodes[i] = createNode(val);

        if (i == 0) {
            head = nodes[i];
            temp = head;
        } else {
            temp->next = nodes[i];
            temp = nodes[i];
        }
    }

    scanf("%d", &pos);

    if (pos != -1) {
        temp->next = nodes[pos];
    }

    struct ListNode *cycleNode = detectCycle(head);

    if (cycleNode == NULL)
        printf("no cycle");
    else {
        for (int i = 0; i < n; i++) {
            if (nodes[i] == cycleNode) {
                printf("tail connects to node index %d", i);
                break;
            }
        }
    }

    return 0;
}