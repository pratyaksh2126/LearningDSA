#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

struct ListNode* insertionSortList(struct ListNode* head) {
    struct ListNode dummy;
    dummy.next = NULL;

    struct ListNode* curr = head;

    while (curr != NULL) {
        struct ListNode* next = curr->next;

        struct ListNode* prev = &dummy;
        while (prev->next != NULL && prev->next->val < curr->val) {
            prev = prev->next;
        }

        curr->next = prev->next;
        prev->next = curr;

        curr = next;
    }

    return dummy.next;
}

int main() {
    int n;
    scanf("%d", &n);

    if (n <= 0) return 0;

    int x;
    scanf("%d", &x);
    struct ListNode* head = createNode(x);
    struct ListNode* temp = head;

    for (int i = 1; i < n; i++) {
        scanf("%d", &x);
        temp->next = createNode(x);
        temp = temp->next;
    }

    head = insertionSortList(head);

    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }

    return 0;
}