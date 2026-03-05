#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

struct Node* removeElements(struct Node* head, int val){
    while(head != NULL && head->data == val){
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    struct Node* curr = head;

    while(curr != NULL && curr->next != NULL){
        if(curr->next->data == val){
            struct Node* temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
        } else {
            curr = curr->next;
        }
    }

    return head;
}

void printList(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main(){
    int n, val, x;
    struct Node *head = NULL, *temp, *last = NULL;

    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&x);
        temp = createNode(x);

        if(head == NULL){
            head = temp;
            last = temp;
        } else {
            last->next = temp;
            last = temp;
        }
    }

    scanf("%d",&val);

    head = removeElements(head,val);

    printList(head);

    return 0;
}