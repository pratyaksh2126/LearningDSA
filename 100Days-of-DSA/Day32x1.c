#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createList(int n){
    struct Node *head = NULL, *temp = NULL, *newNode;
    int x;

    for(int i=0;i<n;i++){
        scanf("%d",&x);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = NULL;

        if(head == NULL){
            head = newNode;
            temp = newNode;
        }else{
            temp->next = newNode;
            temp = newNode;
        }
    }

    return head;
}

int length(struct Node* head){
    int count = 0;
    while(head){
        count++;
        head = head->next;
    }
    return count;
}

int main(){
    int n,m;

    scanf("%d",&n);
    struct Node* head1 = createList(n);

    scanf("%d",&m);
    struct Node* head2 = createList(m);

    int l1 = length(head1);
    int l2 = length(head2);

    struct Node *p1 = head1;
    struct Node *p2 = head2;

    if(l1 > l2){
        for(int i=0;i<l1-l2;i++)
            p1 = p1->next;
    }else{
        for(int i=0;i<l2-l1;i++)
            p2 = p2->next;
    }

    while(p1 && p2){
        if(p1->data == p2->data){
            printf("%d",p1->data);
            return 0;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    printf("No Intersection");
    return 0;
}