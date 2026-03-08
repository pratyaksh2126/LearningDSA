#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void createLoop(struct Node* head, int pos) {
    if(pos < 0) return;

    struct Node *temp = head, *loopNode = NULL;
    int index = 0;

    while(temp->next != NULL) {
        if(index == pos)
            loopNode = temp;
        temp = temp->next;
        index++;
    }

    if(index == pos)
        loopNode = temp;

    if(loopNode != NULL)
        temp->next = loopNode;
}

bool removeLoop(struct Node* head) {
    if(head == NULL || head->next == NULL)
        return true;

    struct Node *slow = head, *fast = head;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
            break;
    }

    if(fast == NULL || fast->next == NULL)
        return true;

    slow = head;

    if(slow == fast) {
        while(fast->next != slow)
            fast = fast->next;
    } else {
        while(slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    fast->next = NULL;
    return true;
}

int main() {
    int n, pos;
    scanf("%d",&n);

    struct Node *head = NULL, *temp = NULL;

    for(int i=0;i<n;i++) {
        int x;
        scanf("%d",&x);

        struct Node* newNode = createNode(x);

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    scanf("%d",&pos);

    createLoop(head,pos);

    if(removeLoop(head))
        printf("true");
    else
        printf("false");

    return 0;
}